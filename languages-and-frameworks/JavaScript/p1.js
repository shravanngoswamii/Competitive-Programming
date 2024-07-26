// q1 - add number to string
let a = "shravan"
let b = 9
console.log(a+b)

// q2 - find type of string
console.log(typeof (a+b))

// q3 - creat const object, can you change it to hold a number later?
const obj = {
    name: "shravan",
    age: 19
}
console.log(obj)
// Answer - No

// q4 - try to add a new key to the const object in q3. were you able to do it?

obj["friend"] = "shubhh"
console.log(obj)
// Answer - Yes

// q5 - write a program to create a word meaning dictionary of 5 words.

const dictionary = {
    hello: "greeting",
    "bye": "farewell",
    "shravan": "name",
    "shubhh": "name",
    "raj": "name"
}
console.log(dictionary)