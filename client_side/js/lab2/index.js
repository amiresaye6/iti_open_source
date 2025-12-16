// question one

let arr = [
    "Use `const` for variables that won't be reassigned and `let` for variables that will, avoiding `var` due to its scoping issues.",
    "Prefer using the strict equality operator (`===`) instead of the loose one (`==`) to avoid unexpected type coercion.",
    "Use template literals (backticks ``) for string concatenation, as they make code cleaner and allow for easy multiline strings and variable interpolation (`${variable}`).",
    "Destructure arrays and objects (`const { prop1, prop2 } = object;` or `const [a, b] = array;`) to extract values cleanly and concisely.",
    "Utilize the spread operator (`...`) for copying arrays/objects or merging them without mutation, e.g., `const newArray = [...oldArray];`.",
    "Master asynchronous JavaScript using Promises and `async/await` for cleaner and more readable handling of operations like API calls.",
    "Use array methods like `map()`, `filter()`, and `reduce()` instead of traditional `for` loops for iteration and data transformation.",
    "Implement short-circuit evaluation with logical operators (e.g., `condition && expression;` or `value || defaultValue;`) for conditional rendering or setting default values.",
    "Understand and leverage closures, which are functions that remember the scope in which they were created, even after the outer function has finished executing.",
    "Avoid global variables by wrapping your code in an Immediately Invoked Function Expression (IIFE) or using ES Modules."
];

let idx = Math.random() * arr.length;

console.log(`Tip of the Day: ${arr[Math.floor(idx)]}`);


// question two

let numArray = [60, 100, 10, 15, 85]

numArray.sort((a, b) => b - a);

console.log(numArray);

console.log(`highest score student: ${numArray.find(el => el <= 100)}`);

numArray.forEach(el => {
    if (el < 60)
        console.log(`low score: ${el}`);
});


// question three

let students = [
    { name: "notAmir", score: 95 },
    { name: "yousef", score: 50 },
    { name: "hamdy", score: 80 },
    { name: "amir", score: 100 },
]


console.log(
    students.find(el => el.score >= 90 && el.score <= 100).name
);
console.log(
    students.find(el => el.score < 60).name
);

students.push({ name: "botato", score: 14 })

students.forEach(el => {
    console.log(`name: ${el.name} , score: ${el.score}`)
})
console.log("=======================");

students.pop();

students.forEach(el => {
    console.log(`name: ${el.name} , score: ${el.score}`)
});

students.sort((a, b) => a.name.localeCompare(b.name));

console.log("=======================");
students.forEach(el => {
    console.log(`name: ${el.name} , score: ${el.score}`)
});

students.splice(2, 0, { name: "botato two", score: 55 }, { name: "botato three", score: 75 });

console.log("=======================");
students.forEach(el => {
    console.log(`name: ${el.name} , score: ${el.score}`)
});

students.splice(3, 1);

console.log("=======================");
students.forEach(el => {
    console.log(`name: ${el.name} , score: ${el.score}`)
});