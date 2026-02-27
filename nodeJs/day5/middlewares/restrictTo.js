const MyError = require('../utils/MyError');

const restrictTo = (roles) => {
    return (req, res, next) => {
        if (!roles.includes(req.user.role)) {
            throw new MyError(403, "Invalid User Type");
        }
        next();
    }
}

module.exports = restrictTo;