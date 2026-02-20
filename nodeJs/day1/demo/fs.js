const fs = require("fs"); // commonjs module



// read file synchronasly
const data = fs.readFileSync("students.json", "utf-8"); // return a string
const parsedData = JSON.parse(data); // return an object



// // read file asynchronsuly
// fs.readFile("students.json","utf-8",(err,data)=>{
//     if(err){
//         console.error(err);
//     }
//     const parsedData = JSON.parse(data);
//     console.log(parsedData[0]);
// })

// // promises
// // async/await => es8

// 
const newStudent = {
    "name": "shady radwan",
    "address": "mansoura, Egypt",
    "grade": "A",
    "courses": ["nodejs", "express", "mongodb", "react"]
  }
// console.log(parsedData);
parsedData.push(newStudent);
// write file synchronasly
// console.log(parsedData);
// fs.writeFileSync("students.json",JSON.stringify(parsedData,null,2));

// write file asynchronsuly
fs.writeFile("students.json",JSON.stringify(parsedData,null,2),(err)=>{
    if(err){
        console.error(err);
    }
    console.log("file written successfully");
})

