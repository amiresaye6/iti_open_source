"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
class Botato {
    name;
    age;
    botato;
    constructor(name, age, botato) {
        this.name = name;
        this.age = age;
        this.botato = botato;
    }
}
// intefaces when used as data types ar exacly like when declaring custom type with the type keyworkd, except for type merging
// like if we declare the same interface name with new properites, ts will merge them to the others so you have one general one
let user = {
    email: "amiralsayed.work@gmail.com",
    password: "***********",
    role: "user",
    login: () => {
        console.log("logged in successfully");
    },
    logout() {
        console.log("logged out successfully");
    },
};
console.log(user);
class AbstractClass {
    print() { }
    anotehrPrint(val) {
        console.log(val);
    }
}
class NotBotato extends Botato {
    static counter = 0;
    constructor() {
        super("amir", 23, "botato");
        NotBotato.counter++;
    }
    print() {
        console.log(`
        Name: ${this.name}
        Age: ${this.age}
        Botato: ${this.botato}
        `);
    }
    get getName() {
        return this.name;
    }
    get getAge() {
        return this.age;
    }
    get getBotato() {
        return this.botato;
    }
    set setName(val) {
        this.name = val;
    }
    set setAge(val) {
        this.age = val;
    }
    set setBotato(val) {
        this.botato = val;
    }
    static printCount() {
        console.log(`Number of instances so far : ${NotBotato.counter} object`);
    }
    static printAnyThing(botato) {
        console.log(botato ?? "hamada");
        return !!botato;
    }
}
let nb = new NotBotato();
for (let i = 0; i < Math.ceil(Math.random() * 15); i++)
    new NotBotato();
nb.setAge = 123;
nb.setName = "Amir Alsayed";
nb.setBotato = "Botaaaaato";
nb.print();
NotBotato.printAnyThing(!!1);
NotBotato.printCount();
//# sourceMappingURL=Classes.js.map