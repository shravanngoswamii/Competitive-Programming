// Write a program to find a factorial of a number.

let num = prompt("Enter a number: ");
num = Number.parseInt(num);

let fact = 1;
for(let i = 1; i <= num; i++) {
    fact *= i;
}
console.log(fact);
