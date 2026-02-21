const postsController = require("../controllers/posts.controller");
const express = require("express");

const route = express.Router();

route.post('/posts', postsController.createPost);
route.get('/posts', postsController.getPosts);
route.get('/posts/:id', postsController.getPostById);
route.patch('/posts/:id', postsController.updatePostById);
route.delete('/posts/:id', postsController.deletePostById);

module.exports = route;