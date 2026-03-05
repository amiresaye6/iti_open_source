const dataEntry = {
    keyONe: 234,
    keyTwo: 234324
} satisfies Record<string, number>;

// satsfies keyword, will take the record type if the acual object types are less specific
// but in this case the object is more specific, so it is the type :__: