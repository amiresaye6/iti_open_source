const express = require("express");
const mongoose = require("mongoose");
require("dotenv").config();

const cors = require("cors");
const morgan = require("morgan");
const helmet = require("helmet");
const hpp = require("hpp");
const { sanitizeMongoInput } = require("express-v5-mongo-sanitize");
const { xss } = require("express-xss-sanitizer");

const rateLimiter = require('./middlewares/rateLimiter');

const postsRoute = require("./routes/posts.routes");
const usersRoutes = require('./routes/users.routes');
const donationRoutes = require('./routes/donation');

const errorHandler = require("./middlewares/errorHandling");


const app = express();

// app middlewares
app.set('trust proxy', 1);
app.use(cors());
app.use(express.json());
app.use(morgan("dev"))
app.use(helmet())
app.use(hpp())
app.use(xss())
app.use(sanitizeMongoInput)
app.use(rateLimiter);

// global route
app.get("/", (req, res) => {
    res.status(200).json(
        {
            message: "welcome to my first api with express at the iti :__:",
            author: "botato"
        }
    )
})
// app routes
app.use("/posts", postsRoute);
app.use("/users", usersRoutes);
app.use("/donation", donationRoutes);

app.use(errorHandler);

app.listen(process.env.PORT, () => {
    mongoose.connect(`${process.env.MONGODB_URL}/${process.env.MONGODB_DATABASE}`).then(() => {
        console.log("✔✔ connected to mongodb successfully");
    }).catch((err) => {
        console.log('❌❌ Connected to MongoDB')
        console.log(err)
    });
    console.log(`✔✔ server is listening on port ${process.env.PORT}`);
})