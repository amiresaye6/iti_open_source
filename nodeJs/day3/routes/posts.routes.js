const postsController = require("../controllers/posts.controller");
const express = require("express");
const validate = require("../middlewares/validator");
const schema = require("../schemas/posts");

const route = express.Router();

route.get('/posts', validate(schema.getAllPostsSchema), postsController.getPosts);
route.get('/posts/:id', postsController.getPostById);
route.post('/posts', validate(schema.createPostSchema), postsController.createPost);
route.patch('/posts/:id', validate(schema.updatePostSchema), postsController.updatePostById);
route.delete('/posts/:id', postsController.deletePostById);

module.exports = route;