// Ramadan Kareem :}

// Create a Database named "ITI_Mongo". 
use ITI_Mongo

// Create a Collection named "Staff". 

db.staff

// Insert one document into the "Staff" collection: {_id, name, age, gender, department}. 

db.staff.insertOne({
    "_id": 1,
    "name": "Amir Alsayed",
    "age": 23,
    "gender": "M",
    "department": "Open Source"
})


// Insert many documents into the "Staff" collection: 
db.staff.insertMany(
    [
        {
            "_id": 2,
            "name": "2Amir Alsayed",
            "age": 20,
            "gender": "male",
            "department": "Java"
        },
        {
            "_id": 3,
            "name": "Eman Alsayed",
            "age": 25,
            "gender": "female",
            "managerName": "Amir Alsayed",
            "department": "Open Source"
        },
        {
            "_id": 4,
            "name": "4Amir Alsayed",
            "age": 15,
            "gender": "M",
            "DOB": "idk"
        }
    ]
)

// Query to find data from the "Staff" collection: 

// 1) Find all documents. 
db.staff.find({});

// 2) Find documents where gender is "male". 
db.staff.find({ gender: "male" })

// 3) Find documents with age between 20 and 25. 
db.staff.find({ age: { $gte: 20, $lte: 25 } })

// 4) Find documents where age is 25 and gender is "female". 
db.staff.find({ age: 25, gender: "female" })

//5) Find documents where age is 20 or gender is "female".  
db.staff.find({
    $or: [
        { age: 20 },
        { gender: "female" }
    ]
})
// Update one document in the "Staff" collection where age is 15, set the name to "your name". 
db.staff.updateOne(
    {
        age: 15
    },
    {
        $set: {
            name: "your name :__:"
        }
    }
)

// Update many documents in the "Staff" collection, update the department to "AI". 
db.staff.updateMany({}, { $set: { department: "AI" } })

// Create a new collection called "test" and insert documents from Question 4. 

use test
db.test.insertMany(
    [
        {
            "_id": 2,
            "name": "2Amir Alsayed",
            "age": 20,
            "gender": "male",
            "department": "Java"
        },
        {
            "_id": 3,
            "name": "Eman Alsayed",
            "age": 25,
            "gender": "female",
            "managerName": "Amir Alsayed",
            "department": "Open Source"
        },
        {
            "_id": 4,
            "name": "4Amir Alsayed",
            "age": 15,
            "gender": "M",
            "DOB": "idk"
        }
    ]
)

// Try to delete one document from the "test" collection where age is 15. 

// With justification, explain which document will be deleted if more than one has age = 15. (Try it.) 

// First insert: db.collection.insertOne({ _id: 5, name: "ahmed", age: 15 }) 

// Second insert: db.collection.insertOne({ _id: 6, name: "eman", age: 15 }) 

// b. When you run deleteOne, will it delete ahmed or eman? 

db.test.insertOne(
    {
        _id: 5,
        name: "ahmed",
        age: 15
    }
)
db.test.insertOne(
    {
        _id: 6,
        name: "eman",
        age: 15
    }
)

db.test.deleteOne({
    age: 15
}) // will delete the first record it finds based on where it is stored in the disk
db.test.find({ age: 15 })


// try to delete all male gender 
db.test.deleteMany({ gender: "male" })
db.test.find({ gender: "male" })

// Try to delete all documents in the "test" collection. 
db.test.deleteMany({})
db.test.find({})


