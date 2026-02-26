const express = require("express");
const mongoose = require("mongoose");
const postsRoute = require("./routes/posts.routes");
const cors = require("cors");
const errorHandler = require("./middlewares/errorHandling");
const morgan = require("morgan");


require("dotenv").config();

const app = express();

// app middlewares
app.use(cors());
app.use(express.json());
app.use(morgan("dev"))

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
app.use("/", postsRoute);



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