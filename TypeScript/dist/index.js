"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function render(document) {
    console.log(document);
}
let nums = [1, 3, 4.3, "amir"];
const fun = () => {
    return "botato";
};
let mixed = ["hi there", 3];
let mixed1 = ["a", "b", "c", "d"];
mixed1.push("botato");
var Size;
(function (Size) {
    Size[Size["Small"] = 1] = "Small";
    Size[Size["Medium"] = 2] = "Medium";
    Size[Size["Large"] = 3] = "Large";
    Size[Size["ExtraLarge"] = 4] = "ExtraLarge";
})(Size || (Size = {})); // compiler by default will set numeric values for medium, large , ...etc with the start , start + 1, ....
let mySize = Size.Large;
function print(input) {
    console.log(input);
}
print(mySize.toString());
print(mixed.join(", "));
print(fun());
print(nums.join("here"));
print(nums.join(">>"));
render(mixed1);
let employee = {
    id: 123156,
    name: "Amir Alsayed",
    fun: (param) => {
        console.log("botato chips" + param);
    }
};
print(`ID: ${employee.id}, Name: ${employee.name}`);
let myEmp = {
    id: 423423,
    name: "amir alsayed",
    age: "23"
};
print(myEmp.name + myEmp.age?.toString());
let widget = {
    drag: () => {
        console.log("drag fuc");
    },
    resize: () => {
        console.log("resize fuc");
    }
};
widget.drag();
let myDimention = "cm";
print(myDimention);
//# sourceMappingURL=index.js.map