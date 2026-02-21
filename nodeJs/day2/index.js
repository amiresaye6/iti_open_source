const express = require("express");
const mongoose = require("mongoose");
const postsRoute = require("./routes/posts.routes");

require("dotenv").config();

const app = express();

app.use(express.json());

app.get("/", (req, res) => {
    res.status(200).json(
        {
            message: "welcome to my first api with express at the iti :__:",
            author: "botato"
        }
    )
})

app.use(postsRoute);


app.listen(process.env.PORT, () => {
    mongoose.connect(process.env.DB_CONNECTION_STRING).then(() => {
        console.log("✔✔ connected to mongodb successfully");
    }).catch((err) => {
        console.log('❌❌ Connected to MongoDB')
        console.log(err)
    });
    console.log(`✔✔ server is listening on port ${process.env.PORT}`);
})