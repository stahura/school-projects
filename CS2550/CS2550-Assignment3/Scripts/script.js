function showHTML() {
  const gridDiv = document.getElementById("gridDiv");
  gridDiv.innerHTML = genHTML();
}

function genHTML() {
  const rows = 5;
  const columns = 7;

  let date = new Date();
  var firstDayOfMonth = new Date(date.getFullYear(), date.getMonth(), 1);
  var weekdayOfFirstDay = firstDayOfMonth.getDay();
  var lastDayOfMonth = new Date(date.getFullYear(), date.getMonth() + 1, 0);
  var weekdayOfLastDay = lastDayOfMonth.getDay();

  console.log(firstDayOfMonth);
  console.log(weekdayOfFirstDay);
  console.log(lastDayOfMonth);
  console.log(weekdayOfLastDay);

  let months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  ];
  const daysOfWeek = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"];

  currentMonth = months[date.getMonth()];
  currentYear = date.getFullYear();
  console.log("current month:" + currentMonth);

  let tableHead = `
    <table>
        <caption id="MonthYear"><b>${currentMonth + " " + currentYear}<b>
        </caption>
        <thead id="M-F">
            <tr>
                ${daysOfWeek
                  .map(day => {
                    return `<th>${day}</th>`;
                  })
                  .join("")}
            </tr> 
            </thead>
    `;

  let tableBody = `
        <tbody>

    `;

  tableBody += generateCalendarBody(rows, columns, weekdayOfFirstDay);

  tableBody += "</tbody></table>";

  return tableHead + tableBody;
}

function generateCalendarBody(rows, columns, firstDay, LastDay) {
  let tableBody = "";
  for (let row = 0; row < rows; row++) {
    tableBody += `
            <tr id = "Week${row + 1}">
        `;
    for (let column = 0; column < columns; column++) {
      tableBody += `
            <td style="vertical-align:top" class="${
              getDay(row, column) % 2 === 0 ? "darker" : ""
            }">${getDay(row, column) <= 30 ? "-" : "-"}</td> 
        `;
    }

    tableBody += "</tr>";
  }
  return tableBody;
}

function getDay(row, column) {
  return row * 7 + (column + 1);
}

function getCell(row, colunn) {
  return
}
//getDay(row, column)
//FUNCTIONS TO GET MONTH DATA