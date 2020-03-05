// This is my code.js file that contains the function I will want to run.

/*Welcome to Austin's casino 
Here is where you will play the amazing game of craps.
The objective of this game is to get doubles well rolling the dice.
If you do not win the roll a screen will pop up displaying either
you lost or just the total number of the dice you rolled that turn.*/

//this line is naming the function
function randomNum() {
    //this is naming the variables
    var num1;
    var num2;
    num1 = Math.ceil((Math.random() * 6));
    num2 = Math.ceil((Math.random() * 6));
    //this is adding the num1 and num2 variables together
    var sum = num1 + num2;
    if (sum == 7 || sum == 11) {
        //below is the actual game functionality adding the numbers and naming the popup displays ingame.
        alert("You rolled a " + num1 + " and a " + num2 + " which means you lost");
    } else if (num1 == num2 && num1 % 2 == 0){
        alert("You rolled a " + num1 + " and a " + num2 + " which means you win!!!");
    } else {
        alert("I rolled a " + num1 + " and a " + num2 + " which add up to " + sum);
    }
    
}