const Joi = require('joi');

const schema = {
    query: Joi.object({
        title: Joi.string().alphanum().min(3).max(30),
        content: Joi.string().min(3).max(300),
        author: Joi.string().min(8).max(30),
        tags: Joi.array().items(Joi.string()),
        published: Joi.boolean().default(true),
    }).required(),
    params: Joi.object({
        id: Joi.string().hex().length(24).required(),
    }).required()
}


module.exports = schema;