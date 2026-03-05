"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
let file = {
    path: "./data/users/botato.usr",
};
let db = {
    connectionString: "mongodb://127.0.0.1:8000/dbtest",
};
function load(content) {
    console.log(typeof (content));
}
load(file);
load(db);
//# sourceMappingURL=guards.js.map