const Post = require("../modules/Posts.model");
const MyError = require("../utils/MyError");

const createPost = async (req, res) => {
    const { title, content, author } = req.body;
    if (!title || !content || !author) {
        throw new MyError(404, "please input all required fields correctly");
    }


    const post = await Post.create({ ...req.body, userId: req.user.userId });
    return res.status(201).json({ message: "post created successfully", post })
}

const getPosts = async (req, res) => {
    let { page = 1, limit = 10 } = req.query;
    page = Number.parseInt(page)
    limit = Number.parseInt(limit)
    const post = await Post.find({}).skip((page - 1) * limit).limit(limit).lean();
    const count = await Post.countDocuments();
    let result = post.map(p => { return { ...p, isOwner: req.user.userId === p.userId.toString() ? true : false } })
    return res.status(200).json({
        message: "posts fetched successfully",
        data: result,
        pagination: {
            total: count,
            limit,
            page,
            totalPages: Math.ceil(count / limit)
        }
    })
}

const getPostById = async (req, res) => {
    let { id } = req.params;
    const post = await Post.findById(id);
    if (post) {
        return res.status(200).json({
            message: "posts fetched successfully",
            post,
            isOwner: req.user.userId === post.userId.toString() ? true : false
        })
    }
    else {
        throw new MyError(404, `Post with id ${id} not found :__:`);
    }
}

const updatePostById = async (req, res) => {
    let { id } = req.params;
    let { userId } = req.user;
    const post = await Post.findByIdAndUpdate(id, req.body, { returnDocument: 'after' });
    if (!post) {
        throw new MyError(404, `Post with id ${id} not found :__:`)
    }
    else if (userId !== post.userId.toString()) {
        throw new MyError(401, "You are not authorized to update this post")
    }
    else {
        return res.status(200).json({
            message: `Post updated successfuly`,
            post
        })
    }
}

const deletePostById = async (req, res) => {
    let { id } = req.params;
    let { userId } = req.user;

    const post = await Post.findByIdAndDelete(id);
    if (!post) {
        throw new MyError(404, `Post with id ${id} not found :__:`)
    }
    else if (userId !== post.userId.toString()) {
        throw new MyError(401, "You are not authorized to delete this post")
    }
    else {
        return res.status(200).json({
            message: `Post deleted successfuly`,
            post
        })
    }
}

module.exports = {
    createPost,
    getPosts,
    getPostById,
    updatePostById,
    deletePostById
}