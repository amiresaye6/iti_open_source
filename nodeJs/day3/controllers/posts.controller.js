const { default: mongoose } = require("mongoose");
const Post = require("../modules/Posts.model");
const MyError = require("../utils/myError");

const createPost = async (req, res) => {
    const { title, content, author } = req.body;
    if (!title || !content || !author) {
        throw new MyError(404, "please input all required fields correctly");
    }


    const post = await Post.create(req.body);
    return res.status(201).json({ message: "post created successfully", post })
}

const getPosts = async (req, res) => {
    let { page = 1, limit = 10 } = req.query;
    page = Number.parseInt(page)
    limit = Number.parseInt(limit)
    const post = await Post.find({}).skip((page - 1) * limit).limit(limit);
    const count = await Post.countDocuments();
    return res.status(200).json({
        message: "posts fetched successfully", post, pagination: {
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
            message: "posts fetched successfully", post
        })
    }
    else {
        throw new MyError(404, `Post with id ${id} not found :__:`);
    }
}

const updatePostById = async (req, res) => {
    let { id } = req.params;
    const post = await Post.findByIdAndUpdate(id, req.body, { returnDocument: 'after' });
    if (!post) {
        throw new MyError(404, `Post with id ${id} not found :__:`)
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
    const post = await Post.findByIdAndDelete(id);
    if (!post) {
        throw new MyError(404, `Post with id ${id} not found :__:`)
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