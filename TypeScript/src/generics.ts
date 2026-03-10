let choises: Array<string> = ["amir", "not amir", "botato"];
console.log(choises.join("||"));

type MyCustomGenericTypeNameIDK<T> = {
  [properityTmpNameCanBeAnyThing: string]: T;
};

let obj: MyCustomGenericTypeNameIDK<string | boolean> = {
  botato: "chips",
  chips: "botato",
  anyThing: "else",
  test: true,
};

console.log(obj);

function merge<T>(a: T, b: T) {
  return [a, b];
}

console.log(merge<number>(10, 13));
console.log(merge<string>("amir ", "alsayed"));
console.log(merge(10, 13)); // typescript will refere the type itself here

function mergeWithTwoTypes<T, U>(a: T, b: U) {
  return [a, b];
}

console.log(mergeWithTwoTypes("amir alsayed", 234));
console.log(mergeWithTwoTypes(2343, "amir alsayed"));
console.log(mergeWithTwoTypes(2343, 23422));
console.log(mergeWithTwoTypes("amir ", "alsayed"));
console.log(mergeWithTwoTypes<string, string>("amir ", "alsayed"));

// function to merge objects in a lareger object
function mergeObj<T extends object, U extends object>(a: T, b: U) {
  return { ...a, ...b };
}
console.log(mergeObj({ test: "value" }, { testTwo: "value two" }));
// can be used with interfaces tooo
class User<ID extends string | number, DATA> {
  constructor(
    public id: ID,
    public data: DATA,
  ) {}
}

let u = new User("abcd", 23454);
console.log(u);

let u2 = new User(312321, { naem: "amir alsayed", age: 234, active: true });
console.log(u2);
