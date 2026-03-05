type FileSource = {
  path: string;
};

type DatabaseSource = {
  connectionString: string;
};

let file: FileSource = {
  path: "./data/users/botato.usr",
};
let db: DatabaseSource = {
  connectionString: "mongodb://127.0.0.1:8000/dbtest",
};

type source = FileSource | DatabaseSource;

function load(content: source) {
  if ("path" in content) {
    console.log(content.path);
    return;
  }
  console.log(content.connectionString);
}

load(file);
load(db);

/////////////////////////////////
class User {
  constructor(public name: string) {}
  join() {}
}

class Admin {
  constructor(public permessions: string[]) {}
  scan() {}
}

const user = new User("Amir Alsayed");

const admin = new Admin(["dashboard", "kpi", "botato"]);

type Entity = User | Admin;

let init = (entity: Entity) => {
  if (entity instanceof User) {
    console.log(entity.name);
    entity.join();
    return;
  }
  console.log(entity.permessions.join(", "));
  entity.scan();
};

//// function overloading >> based on the input type, the output changes for example

function getLength(val: string): string;
function getLength(val: any[]): number;
function getLength(val: string | any[]) {
  if (typeof val === "string") {
    return `${val.length} words`;
  }
  return val.length;
}

console.log(getLength(user.name));
console.log(getLength(admin.permessions));

init(user);
init(admin);
