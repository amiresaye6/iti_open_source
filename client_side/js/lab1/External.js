// printing var before delcaration

console.log(`Value of number1 before declaration: ${number1}`);
console.log(`Value of number2 before declaration: ${number2}`);
console.log(`Value of number3 before declaration: ${number3}`);

var number1 = 10;
var number2 = 2.9;
var number3 = 0xff;

var firstName = "John";
var middleName = 'Doe';
var lastName = `Smith`;
// b. Boolean flag 
var flag = true;
// c. Log message 
console.log("This is the External JavaScript file");

console.log(`Value of number1 after declaration: ${number1}`);
console.log(`Value of number2 after declaration: ${number2}`);
console.log(`Value of number3 after declaration: ${number3}`);



// type of of all variables

console.log(`Type of number1: ${typeof number1}`);
console.log(`Type of number2: ${typeof number2}`);
console.log(`Type of number3: ${typeof number3}`);
console.log(`Type of firstName: ${typeof firstName}`);
console.log(`Type of middleName: ${typeof middleName}`);
console.log(`Type of lastName: ${typeof lastName}`);
console.log(`Type of flag: ${typeof flag}`);


const data = [
    { id: 1, name: "Alice" },
    { id: 2, name: "Bob" }
];
console.table(data);



console.log("even/odd");

let oddEven = (num) => {
    console.log(`${num} is ${num % 2 === 0 ? 'even' : 'odd'}`);
}

oddEven(5);
oddEven(10);


console.log("looping");

for (let i = 1; i < 11; i++)
    console.log(i);


console.log("sign check");

let signCheck = (num) => {
    num < 0 ? console.log(`${num} is negative`) : console.log(`${num} is positive`);
}
signCheck(-5);
signCheck(5);

console.log("multiplication table");
let multiplicationTable = (num) => {
    for (let i = 1; i <= 12; i++) {
        console.log(`${num} x ${i} = ${num * i}`);
    }
}


multiplicationTable(7);
console.log("end");
multiplicationTable(12);

let dayesInWeek = (idx) => {
    switch (idx) {
        case 1:
            console.log("Saturday");
            break;
        case 2:
            console.log("Sunday");
            break;
        case 3:
            console.log("Monday");
            break;
        case 4:
            console.log("tuesday");
            break;
        case 5:
            console.log("widnesday");
            break;
        case 6:
            console.log("Thursday");
            break;
        case 7:
            console.log("Friday");
            break;
        default:
            console.log("Invalid day index");
    }
}

dayesInWeek(1);
dayesInWeek(5);
dayesInWeek(8);


let weekEnds = (day) => {
    if (day === 1 || day === 7) {
        console.log(`${day} is a weekend`);
    }
    else {
        console.log(`${day} is a weekday`);
    }
}

weekEnds(1);
weekEnds(4);
weekEnds(7);

