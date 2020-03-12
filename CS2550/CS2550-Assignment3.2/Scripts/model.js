var grid = [
  ["", "1", "2", "3", "4", "5", "6"],
  ["7", "8", "9", "10", "11", "12", "13"],
  ["14", "15", "16", "17", "18", "19", "20"],
  ["21", "22", "23", "24", "25", "26", "27"],
  ["28", "29", "30", "31", "", "", ""]
];
var eventsGrid = [
  ["", "", "", "Dentist Apt.", "", "", ""],
  ["", "", "", "", "", "", ""],
  ["", "Assignment 3 Due", "", "", "", "", ""],
  ["", "", "Assignment 4 Due", "", "", "", ""],
  ["", "Assignment 5 Due", "", "", "", "", ""]
];
var month = "July";
var year = 2019;
var day = 14;
var dayOfWeek = "Sun";

function getCellDate(row, col) {
  return grid[row][col];
}

function getCellEvents(row, col) {
  return eventsGrid[row][col];
}

/* Eventually, I can probably combine grid and eventsGrid into an object, they can be 
properties of an object, the object being a day or a cell */

/* I have found a way to get the correct month / day / day of week.
This will allow my calendar month/day/year to update dynamically*/
