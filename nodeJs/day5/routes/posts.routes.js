const postsController = require("../controllers/posts.controller");
const express = require("express");
const validate = require("../middlewares/validator");
const schema = require("../schemas/posts");
const restrictTo = require('../middlewares/restrictTo');
const authenticate = require("../middlewares/authenticate");


const route = express.Router();

route.get('/', authenticate, validate(schema.getAllPostsSchema), postsController.getPosts);
route.get('/:id', authenticate, postsController.getPostById);
route.post('/', authenticate, restrictTo(['admin', 'user']), validate(schema.createPostSchema), postsController.createPost);
route.patch('/:id', authenticate, restrictTo(['admin', 'user']), validate(schema.updatePostSchema), postsController.updatePostById);
route.delete('/:id', authenticate, restrictTo(['admin', 'user']), postsController.deletePostById);

module.exports = route;