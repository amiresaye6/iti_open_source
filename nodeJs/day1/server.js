const http = require("http");
const fs = require("fs");
const studentController = require("./fileOperations");


const server = http.createServer(async (req, res) => {
    try {
        console.log(req.url)
        if (req.url === "/students") {
            res.writeHead(200, { 'Content-Type': 'application/json' });

            res.end(JSON.stringify(
                studentController.findStudents()
            ));
        } else if (req.url === "/stats") {
            res.writeHead(200, { 'Content-Type': 'application/json' });

            res.end(JSON.stringify(
                { numberOfStudents: studentController.findStudents().length }
            ));
        } else if (req.url.startsWith("/find-student")) {
            res.writeHead(200, { 'Content-Type': 'application/json' });
            let name = req.url.split("?name=")[1].replace("%20", " ");

            res.end(JSON.stringify(
                studentController.findByName(name)[0]
            ));
        }
        else if (req.url === "/courses") {
            res.writeHead(200, { 'Content-Type': 'application/json' });

            res.end(JSON.stringify(
                { courses: studentController.findStudents().map(el => el.course) }
            ));
        } else {
            res.writeHead(404, { "Content-Type": "text/plain" });
            res.end("Not Found");
        }
    } catch (error) {
        res.writeHead(500, { "Content-Type": "text/plain" });
        res.end("Internal Server Error");
    }
});

const PORT = 1234;
server.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});