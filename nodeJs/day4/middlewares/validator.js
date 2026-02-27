const MyError = require("../utils/MyError");

const validator = (schema) => {
    return (req, res, next) => {
        for (const key in schema) {
            const { error } = schema[key].validate(req[key], { abortEarly: true }); // abortEarly will return err by err.
            if (error) {
                throw new MyError(400, error.details[0].message);
            }
        }
        next();
    }
}

module.exports = validator;