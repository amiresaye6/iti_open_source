const fs = require("fs");
const http = require("http");

// common js modules >> const fs = require("fs"); >> old shape >> what i will use in node course.
// es6 modules = import fs from "fs"; >> new shape


const data = JSON.parse(fs.readFileSync('./data.json'));


const server = http.createServer((req, res) => {
    console.log(req);
    res.writeHead(200, { 'Content-Type': 'application/json' });
    res.end(JSON.stringify({
        data,
    }));
});

server.listen(1234);

