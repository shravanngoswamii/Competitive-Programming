// q1 - use logical operator to find whether the age of a person is between 10 and 15.
// Only work in browser console
/*
let age = prompt("Enter your age: ")
   if (age >= 10 && age <= 15) {
       console.log("Age is between 10 and 15")
   }
   else {
       console.log("Age is not between 10 and 15")
   } 
*/

// q2 - use switch case to find whether the age of a person is between 10 and 15.

/*
let age = prompt("Enter your age: ")
age = Number.parseInt(age)
switch (age) {
    case 10:
        console.log("Age is between 10 and 15")
        break;
    case 11:
        console.log("Age is between 10 and 15")
        break;
    case 12:
        console.log("Age is between 10 and 15")
        break;
    case 13:
        console.log("Age is between 10 and 15")
        break;
    case 14:
        console.log("Age is between 10 and 15")
        break;
    case 15:
        console.log("Age is between 10 and 15")
        break;
    
    default:
        console.log("Age is not between 10 and 15")
        break;
}
*/

// q3 - Write a JS program to check whether a number is divisible by 2 and 3 or not.

let num = prompt("Enter a number: ")
num = Number.parseInt(num)
if (num%2 ==0 && num%3 ==0) {
    console.log("Number is divisible by 2 and 3")
}
else {
    console.log("Number is not divisible by 2 and 3")
}

// q4 - Print "You can drive" or "You cannot drive" based on the age of the person using ternary operator.

let age = prompt("Enter your age: ");
age = Number.parseInt(age);

let result = (age >= 18) ? "you can drive" : "you cannot drive";
console.log(result); 