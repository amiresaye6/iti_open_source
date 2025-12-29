// Task 1: Array Operations

let arrSize = prompt("Enter the size of the array:");
let arr = [];

for (let i = 0; i < arrSize; i++) {
    let element = NaN;
    while (!Number.isInteger(Number(element)))
        element = prompt(`Enter element ${i + 1}:, must be a valid number`);
    arr.push(Number(element));
}

// let opt = 'exit';
let opt = null;

while (opt !== "exit") {
    opt = prompt(
        `chose one of the following: 
Letter  Operation 
a       Display the array in the same order it was entered 
b       Display the array in ascending order 
c       Display the array in descending order 
d       Display the reversed version of the original array 
e     Display only even numbers from the array. If none exist, show an alert 
f      Ask the user for a number, then display all array elements divisible by it. If none exist, show an alert 
g     Display a new array where all numbers have a 30% discount applied 
h      Display a string of all numbers concatenated using ***
`
    )

    switch (opt) {
        case "a":
            alert(`Display the array in the same order it was entered: ${[...arr].join(" , ")}`)
            break;
        case "b":
            alert(`Display the array in ascending order : ${[...arr].sort((a, b) => a - b).join(" , ")}`)
            break;

        case "c":
            alert(`Display the array in descending order : ${[...arr].sort((a, b) => b - a).join(" , ")}`)
            break;

        case "d":
            alert(`Display the reversed version of the original array : ${[...arr].reverse().join(" , ")}`)
            break;

        case "e":
            alert(`Display only even numbers from the array.
                    If none exist, show an alert  : ${[...arr].filter(el => el % 2 == 0).length == 0 ?
                    "did not find any even elment" :
                    [...arr].filter(el => el % 2 == 0).join(" , ")}`)
            break;

        case "f":
            let num = Number(prompt("Enter a number:"));
            let divisible = arr.filter(el => el % num === 0);

            if (divisible.length === 0) {
                alert("No elements divisible by this number");
            } else {
                alert(divisible.join(" , "));
            }
            break;

        case "g":
            alert(`Display a new array where all numbers have a 30% discount applied  : ${[...arr].map(el => el * 0.7).join(" , ")}`)
            break;

        case "h":
            alert(`Display a string of all numbers concatenated using ***   : ${[...arr].join("***")}`)
            break;

    }
}


// Task 2: Count Vowels

function vCount(str = "") {
    let res = 0;
    str.toLowerCase().split("").forEach(ch => {
        if ("aeiou".indexOf(ch) != -1)
            res++;
    })

    console.log(`number of voul letters in ${str} is ${res}`);
}

vCount("botato")
vCount("aaaaaaaaaaa")
vCount("ddddddddd")


// Task 3: Capitalize Words

function strCapitalizer5000(str = "") {
    let res = str.split(" ").map(word => {
        return word.charAt(0).toUpperCase() + word.slice(1);
    }).join(" ");

    console.log(`${str} >>>> ${res}`);
}

strCapitalizer5000("botato")
strCapitalizer5000("test case for this function")
strCapitalizer5000("AMIR alsayed")

// Task 4: Count Character Occurrences

let countOccurances = (str = "", ch = "") => {
    let ocr = str.split("").filter(c => c === ch).length;
    console.log(`character ${ch} apppeard in ${str} ${ocr} times`);

}

countOccurances("botato", "o")
countOccurances("aaaaaaaaaaabcdefgaaaaa", "a")



let workdCounter5000 = (str = "") => {
    console.log(`number of words in ${str} are ${str.trim().replace(/ +/g, " ").split(" ").length}`);
}

workdCounter5000("botato")
workdCounter5000("amir alsayed abdulsamea")
workdCounter5000("     amir alsayed abdulsamea       mohamed    ")



// Task 6: User Name and Mobile Validation
// let flag = false;
let flag = true;
let mobileInput = "";
do {
    let checker = /^002\d{3}-\d{7}$/;
    mobileInput = prompt("please input your mobile phone, ")
    if (mobileInput.length < 11 || !checker.test(mobileInput))
        alert("mobile number must be exactly 11 characters long with this format xxx-xxxxxxx")

    else if (!["010", "011", "012", "015"].includes(mobileInput.slice(0, 3)))
        alert("number must start with 010 | 011 | 012 | 015")
    else {
        alert(`success: ${mobileInput}`)
        flag = false
    }
} while (flag)



// Task 7: Date Object & Validation 
// Part 2: Birth Date Validation 
let birthDate = prompt('PLEASE INPUT YOUR BD IN THIS FORMAT: DD-MM-YYYY >> EX: 30-12-2000');

let dateChicker234 = (str = "") => {
    let checker = /^\d{2}-\d{2}-\d{4}/;
    if (!checker.test(str)) {
        alert("Wrong Date Format");
    } else {
        let [bDay, bMonth, bYear] = str.split("-").map(Number);
        
        let today = new Date();
        let cDay = today.getDate();
        let cMonth = today.getMonth() + 1;
        let cYear = today.getFullYear();

        let days = cDay - bDay;
        let months = cMonth - bMonth;
        let years = cYear - bYear;

        if (days < 0) {
            days += new Date(cYear, cMonth - 1, 0).getDate();
            months--;
        }
        if (months < 0) {
            months += 12;
            years--;
        }

        alert(`Age: ${years}y, ${months}m, ${days}d`);
    }
}

dateChicker234(birthDate);


let getDayName = (dateStr = "") => {
    let dayIdx = new Date(dateStr).getDay();
    console.log(dayIdx);
    switch (dayIdx) {
        case 0:
            alert("this day is Sunday")
            break;
        case 1:
            alert("this day is Monday")
            break;
        case 2:
            alert("this day is Tuesday")
            break;
        case 3:
            alert("this day is Wednesday")
            break;
        case 4:
            alert("this day is Thursday")
            break;
        case 5:
            alert("this day is Friday")
            break;
        case 6:
            alert("this day is Saturday")
            break;

    }

}
getDayName(new Date(Date.now()))