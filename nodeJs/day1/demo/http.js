const http = require('http');


const server = http.createServer((req,res)=>{
   if(req.url === '/'){
    res.writeHead(200, { 'Content-Type': 'application/json' });
    res.end(JSON.stringify({
      message: 'Hello World!',
    }));
   }else if (req.url === '/about'){
    res.writeHead(200, { 'Content-Type': 'application/json' });
    res.end(JSON.stringify({
      message: 'About Page',
    }));
   }else{
    //404
    res.writeHead(404, { 'Content-Type': 'text/html' });
    res.end('<h1>404 Not Found</h1>');
   }
});

server.listen(3000,()=>{
    console.log("server is running on port 3000");
});