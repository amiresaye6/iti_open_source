const mongoose = require("mongoose");

const postSchema = mongoose.Schema({
    title: { type: String, required: true },
    content: { type: String, required: true },
    author: { type: String, required: true },
    tags: [String],
    published: { type: Boolean, default: false },
    likes: { type: Number, default: 0 },
}, { timestamps: true });

const Post = mongoose.model("post", postSchema);

module.exports = Post;