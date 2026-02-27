const Joi = require('joi');

const createUserSchema = {
    body: Joi.object({
        title: Joi.string().alphanum().min(3).max(30).required(),
        content: Joi.string().min(3).max(300).required(),
        author: Joi.string().min(8).max(30).required(),
        tags: Joi.array().items(Joi.string()),
        published: Joi.boolean().default(true),
    }).required(),
}

module.exports = createUserSchema;