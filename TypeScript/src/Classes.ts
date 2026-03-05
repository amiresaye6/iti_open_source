class Botato {
  constructor(
    protected name: string,
    protected age: number,
    protected botato: string,
  ) {}
}
// can be used as a type for variables or as a contract for other classes
interface Printable {
  print(): void;
}

interface Authonticatable {
  email: string;
  password: string;

  login(): void;
  logout(): void;
}

interface Authonticatable {
  role: string;
}
// intefaces when used as data types ar exacly like when declaring custom type with the type keyworkd, except for type merging
// like if we declare the same interface name with new properites, ts will merge them to the others so you have one general one
let user: Authonticatable = {
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

interface AuthonticateAdmin extends Authonticatable {
  role: "admin" | "superAdmin";
}

abstract class AbstractClass {
  print(): void {}
  anotehrPrint(val: string): void {
    console.log(val);
  }
}

class NotBotato extends Botato implements Printable {
  private static counter: number = 0;

  constructor() {
    super("amir", 23, "botato");
    NotBotato.counter++;
  }

  print(): void {
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

  set setName(val: string) {
    this.name = val;
  }
  set setAge(val: number) {
    this.age = val;
  }
  set setBotato(val: string) {
    this.botato = val;
  }

  static printCount(): void {
    console.log(`Number of instances so far : ${NotBotato.counter} object`);
  }

  static printAnyThing(botato: boolean): boolean {
    console.log(botato ?? "hamada");
    return !!botato;
  }
}

let nb: NotBotato = new NotBotato();

for (let i = 0; i < Math.ceil(Math.random() * 15); i++) new NotBotato();

nb.setAge = 123;
nb.setName = "Amir Alsayed";
nb.setBotato = "Botaaaaato";

nb.print();

NotBotato.printAnyThing(!!1);
NotBotato.printCount();
