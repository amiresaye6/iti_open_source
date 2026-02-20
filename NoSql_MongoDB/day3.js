use iti_mongoDB_course

// Provide the MongoDB code for enforcing JSON schema validation when creating a collection named "employees" with required fields "name," "age" (min. 18), and "department" (limited to ["HR," "Engineering," "Finance"]). 

db.createCollection("employees", {
    validator: {
        $jsonSchema: {
            bsonType: "object",
            title: "Employees schema with validation",
            required: ["name", "age", "department"],
            properties: {
                "name": {
                    bsonType: "string",
                    description: "name must be a string and is required"
                },
                "age": {
                    bsonType: "int",
                    minimum: 18,
                    description: "age must be an integer greater than or equal to 18"
                },
                "department": {
                    bsonType: "string",
                    enum: ["HR", "Engineering", "Finance"],
                    description: "department must be one of the allowed strings"
                }
            }
        }
    }
})

db.employees.insert({
    "name": "Amir Alsayed",
})

db.employees.insert({
    "name": "Amir Alsayed",
    "age": 23,
})

db.employees.insert({
    "name": "Amir Alsayed",
    "age": 15,
})

db.employees.insert({
    "name": "Amir Alsayed",
    "age": 23,
    "department": "test"
})

db.employees.insert({
    "name": "Amir Alsayed",
    "age": 23,
    "department": "Engineering"
})


// Create new Database named Demo 
use Demo

// And Collections named trainningCenter1, trainningCenter2  
db.createCollection("trainningCenter1")
db.createCollection("trainningCenter2")
// Insert documents into trainningCenter1 collection contains (Use Variable named data as Array) 
// _id , name as firstName lastName , age , address as array , status 
let data = [
    {
        "_id": 1,
        "name": {
            "firstName": "Amir",
            "lastName": "Alsayed"
        },
        "age": 23,
        "address": [
            "sharquia",
            "Abu Hammad",
            "botato chips"
        ],
        "status": "Active"
    },
    {
        "_id": 2,
        "name": {
            "firstName": "Am6ir",
            "lastName": "Als6ayed"
        },
        "age": 33,
        "address": [
            "sharqui6a",
            "Abu Hamma6d",
            "botato chip6s"
        ],
        "status": "Active"
    },
    {
        "_id": 3,
        "name": {
            "firstName": "Am6ir",
            "lastName": "Alsay6ed"
        },
        "age": 44,
        "address": [
            "sharqu6ia",
            "Abu Ha6mmad",
            "botato ch6ips"
        ],
        "status": "Active"
    },
    {
        "_id": 4,
        "name": {
            "firstName": "Am5ir",
            "lastName": "Alsa5yed"
        },
        "age": 55,
        "address": [
            "shar5quia",
            "Abu Ham5mad"],
        "status": "Active"
    },
    {
        "_id": 5,
        "name": {
            "firstName": "2Amir",
            "lastName": "Alsayed"
        },
        "age": 66,
        "address": [
            "sharq2uia",
            "Abu Ham2mad",
            "botato c2hips"
        ],
        "status": "InActive"
    }
]

db.trainningCenter1.drop()

db.trainningCenter2.drop()

// Using insert ONE from data Variable 
db.trainningCenter1.insertOne(data)
db.trainningCenter1.find() // all documents added :__:, but as one object of multible entires with the indes as key

// Using Same Variable (data) with same data and insert MANY into trainningCenter2 collection 
db.trainningCenter2.insertMany(data)
db.trainningCenter2.find() // all do`cuments added as expected normally

// Use find. explain function (find by age field) and mention scanning type 

db.trainningCenter2.find({"age": 23}).explain() // "stage" : "COLLSCAN",

// Create index on created collection named it “IX_age” on age field
db.trainningCenter2.createIndex({"age": 1}, {name: "IX_age"})

// Use find. explain view winning plan for index created (find by age field) and mention scanning type 
db.trainningCenter2.find({"age": 23}).explain() // "stage" : "IXSCAN",

// Try find().explain before create index and mention scanning type 
db.trainningCenter2.find({"name.firstName": "Amir"}).explain() // "stage" : "COLLSCAN",

// Create index on created collection named it “compound” on firstNsme and lastName 
db.trainningCenter2.createIndex({"name.firstName": 1, "name.lastName": 1}, {"name": "compount"})

// Try find().explain after create index and mention scanning type 
db.trainningCenter2.find({"name.firstName": "Amir"}).explain() // "stage" : "IXSCAN",

// Drop Demo Database
db.dropDatabase()


// Bonus Part 

// Use mongodump to back up your Lab database. 
// >> mongoexport --collection=employees --db=iti_mongoDB_course --out=employeesCollection.dump.json