function render(document: any) {
    console.log(document);
}

let nums: (string | number)[] = [1, 3, 4.3, "amir"];

const fun: () => string = () => {
    return "botato";
}

let mixed: [string, number] = ["hi there", 3]
let mixed1: Array<string> = ["a", "b", "c", "d"];

mixed1.push("botato");

enum Size { Small = 1, Medium, Large, ExtraLarge } // compiler by default will set numeric values for medium, large , ...etc with the start , start + 1, ....

let mySize: Size = Size.Large;

function print(input: string) {
    console.log(input)
}
print(mySize.toString());

print(mixed.join(", "));

print(fun());

print(nums.join("here"));

print(nums.join(">>"));

render(mixed1);


let employee: {
    id: number,
    name: string,
    fun?: (param: string) => void
} = {
    id: 123156,
    name: "Amir Alsayed",
    fun: (param: string) => {
        console.log("botato chips" + param);
    }
}

print(`ID: ${employee.id}, Name: ${employee.name}`);

type Emp = {
    id: number,
    name: string,
    age?: string | number, // type union
    fun?: (param: string) => void
}

let myEmp: Emp = {
    id: 423423,
    name: "amir alsayed",
    age: "23"
}

print(myEmp.name + myEmp.age?.toString());


// type interesection

type Dragable = {
    drag: () => void
}

type Resizable = {
    resize: () => void
}

type UiWidget = Dragable & Resizable;

let widget: UiWidget = {
    drag: () => {
        console.log("drag fuc");
    },
    resize: () => {
        console.log("resize fuc");
    }
}

widget.drag()

type Dimention = "cm" | "mm";

let myDimention: Dimention = "cm";
print(myDimention);