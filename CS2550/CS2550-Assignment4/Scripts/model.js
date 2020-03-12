grid = [
  ['', '1', '2', '3', '4', '5', '6'],
  ['7', '8', '9', '10', '11', '12', '13'],
  ['14', '15', '16', '17', '18', '19', '20'],
  ['21', '22', '23', '24', '25', '26', '27'],
  ['28', '29', '30', '31', '', '', ''],
];
/*var
var grid = [
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
];*/
var eventsGrid = [
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
  ['', '', '', '', '', '', ''],
];

let months = [
  'January',
  'February',
  'March',
  'April',
  'May',
  'June',
  'July',
  'August',
  'September',
  'October',
  'November',
  'December',
];

let rows = 5;
let columns = 7;
let date = new Date();
let currentMonth = date.getMonth();
let currentYear = date.getFullYear();
let firstDay = new Date(currentYear, currentMonth).getDay();
let day = 1;

function getCorrectDateInfo(currentMonth, currentYear) {
  console.log(firstDay + " is first day")
  for (let row = 0; row < rows; row++) {
    for (let column = 0; column < columns; column++) {
      console.log("Row: " + row + " Column: " + column)

      if (row === 0) {
        while (firstDay > column) {
          setGrid(row, column, ' ');
          column++;
        }
        console.log("Row: " + row + " Column: " + column)
        setGrid(row, column, day);
        day++;
      } else {
        if (day <= daysInMonth(currentMonth, currentYear))
          setGrid(row, column, day);
        day++;
      }
    }
  }
}

function setGrid(row, column, value) {
  value = value.toString();
  console.log(`Setting row: ${row} column: ${column} to ${value}`);
  grid[row][column] = value;
}

function printGrid() {
  for (var i = 0; i < rows; i++) {
    for (var j = 0; j < columns; j++) {
      console.log(grid[i][j]);
    }
  }
}

function set2() {
  for (var i = 0; i < rows; i++) {
    for (var j = 0; j < columns; j++) {
      console.log(grid[i][j])
      grid[i][j] = getCellDate(i, j);
    }
  }
}

function getCellDate(row, col) {
  return grid[row][col];
}

function getCellEvents(row, col) {
  return eventsGrid[row][col];
}

function daysInMonth(month, year) {
  return 32 - new Date(year, month, 32).getDate();
}

function updateGridWithDates() {
  getCorrectDateInfo(currentMonth, currentYear);
  printGrid();
  // addEvents();
}

function createCalEvent(row, column) {
  updateSelectedCell(row, column);
  const cellEventID = `newEvent[${row}][${column}`;
  const cellID = `[${row}][${column}]`;
  console.log(`Cell [${row}][${column}] has been clicked]`)
  if (document.getElementById(cellEventID)) {
    return;
  }

  const cell = document.getElementById(cellID);

  const newEventHTML = `
    <input placeholder="New Event" id="${cellEventID}" />
    <button onclick="submitNewEvent('${cellEventID}', '${cellID}')" type="button">Add Event</button>
  `;
  const container = document.createElement('div');
  container.id = `container of ${cellEventID}`;
  container.innerHTML = newEventHTML;

  cell.appendChild(container);
}

function updateSelectedCell(row, column) {
  const coordinatesHTML = document.getElementById('coordinates');
  coordinatesHTML.innerText = `[${row}][${column}]`;
}

function submitNewEvent(cellEventID, cellID) {
  const eventText = document.getElementById(cellEventID).value;
  const newSpan = document.createElement('span');
  newSpan.innerHTML = `${eventText} <br>`;

  const cell = document.getElementById(cellID);
  const container = document.getElementById(`container of ${cellEventID}`);

  cell.appendChild(newSpan);
  setTimeout(() => {
    cell.removeChild(container);
    console.log("Event Created")
  });
}

function updateMonth() {
  let selectedMonth = document.getElementById("monthList").selectedIndex
  let monthLabel = document.getElementById("MonthYear")

  currentMonth = selectedMonth - 1
  monthLabel.innerHTML = `<b>${months[currentMonth] +
    ' ' +
    currentYear}<b> 
    <select id="monthList" onchange="updateMonth()">
            <option>Change Month</option>
            <option id="option0" value="0" >January </option>
            <option value="1" >February </option>
            <option value="2" >March </option>
            <option value="3" >April </option>
            <option value="4" >May </option>
            <option value="5" >June </option>
            <option value="6" >July </option>
            <option value="7" >August </option>
            <option value="8" >September </option>
            <option value="9" >October </option>
            <option value="10" >November </option>
            <option value="11" >December </option>
          </select>`

  day = 1;
  updateGridWithDates()
  console.log("Month has been changed")
}





/* Eventually, I can probably combine grid and eventsGrid into an object, they can be 
properties of an object, the object being a day or a cell   */