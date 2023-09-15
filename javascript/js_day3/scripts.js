console.log('I am back!')

// Switch case

let s = 1
switch (s) {
    case 1:
        console.log('Super User')
        break
    case 2:
        console.log('Medium User')
        break
    case 3:
        console.log('Normal User')
        break
    default:
        console.log('No User')
}


// ternary operator
// condn ? correctVal : falseValue
let age = 16
let vote = age>=18 ? true:false 
// if (age >= 18)
// {
//     vote = 1
// }
// else 
// {
//     vote = 2
// }
console.log(vote)

// loops
let a = 1
// while
while(a<10)
{
    console.log(a)
    a++
}

// do-while
let b = 10
do
{
   console.log(b)
   b++
}
while(b<10)

// for loop
for (let c=1; c<10; c++)
{
    if(c==4)
    {
        //break
        continue
    }
    console.log('c'+c)
}

// array
let cities = ['Mumbai','Pune', 'Patna']
// console.log(cities[0])
for(let d=0;d<cities.length;d++)
{
    console.log(cities[d])
}

// objects
// collection of properties/data which is representing a single entity
let student = {
    name: 'Rohit',
    age: 19,
    cities: 'Patna'
}

console.log(student.name, student.age,student.cities)

let student2 = {
    name: 'Saurabh',
    age: 27,
    cities: 'Mumbai'
}
