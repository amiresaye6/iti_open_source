use iti_mongoDB_course

// Find documents where the "tags" field exists. 
db.inventory.find({ "tags": { $exists: true } }, { _id: 0, "tags": 1 })

// Find documents where the "tags" field does not contain values "ssl" or "security." 
db.inventory.find({ "tags": { $nin: ["ssl", "security"] } }, { _id: 0, "tags": 1 })

// Find documents where the "qty" field is equal to 85. 
db.inventory.find({ "qty": { $eq: 85 } })


// Find documents where the "tags" array contains all of the values [ssl, security] using the `$all` operator. 
db.inventory.find({ "tags": { $all: ["ssl", "security"] } })

// Question: 
// If you need to find only the two values "ssl" and "security", what change would you make to your query? 
db.inventory.find({ "tags": ["ssl", "security"] })

// Find documents where the "tags" array has a size of 3. 
db.inventory.find({ "tags": { $size: 3 } }, { _id: 0, "tags": 1 })


//Update the "item" field in the "paper" document, update "size.uom" to "meter" and using the `$currentDate` operator. 
db.inventory.updateOne(
    {
        "item": "paper"
    },
    {
        $set: {
            "size.uom": "meter"
        },
        $currentDate: {
            "lastUpdate": true
        }
    })
db.inventory.find({ "item": "paper" })

//Also, use the upsert option (within updateOne)and change filter condition item:”laptopDevice”. 
//Use the $setOnInsert operator to add new data if an insert occurs. 
//
//Example field: dataSource: "todayRegister" 
db.inventory.updateOne(
    {
        "item": "laptopDevice"
    }, {
        $set: { "size.uom": "meter" },
        $currentDate: { "lastUpdate": true },
        $setOnInsert: { "dataSource": "todayRegister" }
    }, {
        upsert: true
    }
)
db.inventory.find({ "item": "laptopDevice" })


//Try using the updateMany operation. 
db.inventory.updateMany(
    {
        "item": "paper"
    },
    {
        $set: {
            "size.uom": "meter"
        },
        $currentDate: {
            "lastUpdate": true
        }
    })
db.inventory.find({ "item": "paper" })


//Try using the `replaceOne` operation. >> i have to provide the new entire document to replace the old one
db.inventory.replaceOne(
    { "item": "paper" },
    {
        "item": "paper",
        "size": { "uom": "meter" },
        "lastUpdate": new Date(),
        "status": "updated"
    },
    { upsert: true }
)


// Insert a document with incorrect field names "neme" and "ege," then rename them to "name" and "age." 
db.inventory.insert({
    "neme": "Amir Alsayed",
    "ege": 23
})

db.inventory.find({ "neme": { $exists: true } })

db.inventory.updateMany({ "neme": { $exists: true } }, {
    $rename: {
        "neme": "name",
        "ege": "age"
    }
})
db.inventory.find({ "neme": { $exists: true } })

// Try to reset any document field using the `$unset` function. 
db.inventory.insertOne({ "deleteThisField": "a temp filed to be deleted next step :__:" })

db.inventory.find({ "deleteThisField": { $exists: true } })

db.inventory.updateOne(
    { "deleteThisField": { $exists: true } },
    { $unset: { "deleteThisField": "" } }
)

// Try update operators like `$inc`, `$min`, `$max`, and `$mul` to modify document fields. 

// Important: Use a different field for each operation listed below. Insert Data If Not Existing 

// Apply the following MongoDB update operators to the specified fields: 

// Use $max on the field: salary 
db.employees.find({}, { "salary": 1 })
db.employees.updateMany({}, { $max: { "salary": 50000 } })

// Use $min on the field: overtime 
db.employees.find({}, { "overtime": 1 })
db.employees.updateMany({}, { $min: { "overtime": 20 } })

// Use $inc on the field: age 
db.employees.find({}, { "age": 1 })
db.employees.updateMany({}, { $inc: { "age": 1 } })

// Use $mul on the fields: quantity and price
db.sales.find({}, { "quantity": 1, "price": 1 })
db.sales.updateMany({}, { $mul: { "price": 1.1, "quantity": 2 } })

// Calculate the total revenue for product from sales collection documents within the date range '01-01-2020' to '01-01-2023' and then sort them in descending order by total revenue. 
// Total Revenue=  Sum (Quantity * Price) 
db.sales.find()
db.sales.aggregate([
    {
        // filter from '01-01-2020' to '01-01-2023'
        $match: {
            "date": {
                $gte: ISODate("2020-01-01T00:00:00Z"),
                $lte: ISODate("2023-01-01T23:59:59Z")
            }
        }
    },
    {
        // join and calc total revenue >> Total Revenue =  Sum (Quantity * Price)
        $group: {
            "_id": "$product",
            "totalRevenue": {
                $sum: { $multiply: ["$quantity", "$price"] }
            }
        }
    },
    {
        //  sort descending by total revenue
        $sort: { "totalRevenue": -1 }
    }
])

// Calculate the average salary for employees for each department from the employee’s collection. 

db.employees.find()

db.employees.aggregate([
    {
        // join each department
        // calc avrage for each one of them
        $group: {
            "_id": "$department",
            "avrageSalary": { $avg: "$salary" }
        }
    }
])

// Use likes Collection to calculate max and min likes per title 

db.likes.find({}, {likes: 1, title: 1})

db.likes.aggregate([
{
      // group with title
      // calc min
      // calc max
      $group: {
          "_id": "$title",
          "minLikes": {$min: "$likes"},
          "maxLikes": {$max: "$likes"}
      }  
},
])
