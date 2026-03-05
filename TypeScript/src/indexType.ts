// this type can have any number of properites with string key and number or boolean value
type DataStore = {
  [prop: string]: number | boolean;
};

// this is the same as the Record generic type

let myStore: Record<string, number | boolean>;
myStore = {
  id: 2,
  botato: true,
};

let store: DataStore = {
  id: 2,
  botato: true,
};
store.newVal = false;
store.andSoOnYouCanDoThisAllDay = 1;

// cosnt types
// auth type now is the three values only, not an array of strings
let auth = ["admin", "user", "guest"] as const;

let myUser = auth[0];
console.log(myUser);
