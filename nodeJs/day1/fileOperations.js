const fs = require("fs");

// ===============setup==============
const studentData = [
    {
        id: 1,
        name: "Alice Johnson",
        age: 20,
        course: "Computer Science",
        grades: {
            math: 90,
            programming: 95,
        },
    },
    {
        id: 2,
        name: "Bob Smith",
        age: 22,
        course: "Data Science",
        grades: {
            statistics: 88,
            machine_learning: 92,
        },
    },
    {
        id: 3,
        name: "Carol Williams",
        age: 21,
        course: "Web Development",
        grades: {
            html: 95,
            javascript: 89,
        },
    },
];

const dataBase = "students.json"
fs.writeFileSync(dataBase, JSON.stringify(studentData));

// ===============functions==============

// Write the studentData to students.json
const addStudent = student => {
    let tmp = JSON.parse(fs.readFileSync(dataBase));
    tmp.push(student);
    fs.writeFileSync(dataBase, JSON.stringify(tmp));
}

// Write the studentData to students.json
const findStudents = (id) => {
    let tmp = JSON.parse(fs.readFileSync(dataBase));
    return id ? tmp.filter(s => s.id === id) : tmp;
}
// find by name
const findByName = (name) => {
    let tmp = JSON.parse(fs.readFileSync(dataBase));
    return tmp.filter(s => s.name === name);
}

// update student
const updateStudentById = (id, data) => {
    let tmp = JSON.parse(fs.readFileSync(dataBase));
    let student = tmp.filter(s => s.id === id)[0];
    let allData = tmp.filter(s => s.id !== id);

    let newStudent = {
        name: data.name || student.name,
        age: data.age || student.age,
        course: data.course || student.course,
        grades: data.grades || student.grades,
    }
    allData.push(newStudent);
    fs.writeFileSync(dataBase, JSON.stringify(allData))

}

// delete student
const deleteStudentById = (id, data) => {
    let tmp = JSON.parse(fs.readFileSync(dataBase));
    let allData = tmp.filter(s => s.id !== id);
    fs.writeFileSync(dataBase, JSON.stringify(allData))
}

module.exports = {
    addStudent,
    findStudents,
    updateStudentById,
    deleteStudentById,
    findByName
}