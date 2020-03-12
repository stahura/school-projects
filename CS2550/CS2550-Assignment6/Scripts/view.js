function showHTML() {
  updateGridWithDates()
  const gridDiv = document.getElementById('gridDiv');
  gridDiv.innerHTML = genHTML();
  printGrid();
  readStorage();
  //requestCalendarJson()
}

function genHTML() {
  console.log("running genHTML()")
  const rows = 5;
  const columns = 7;

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
  const daysOfWeek = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'];


  console.log('current month:' + currentMonth);


  let tableHead = `
    <h1 id="selected-cell">Selected Cell: <span id="coordinates"></span></h1>
     
      <table id="calendar-grid">
          <caption id="MonthYear"><b>${months[currentMonth] +
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
          </select>
          </caption>
          <thead id="M-F">
              <tr>
                  ${daysOfWeek
                    .map(day => {
                      return `<th>${day}</th>`;
                    })
                    .join('')}
              </tr> 
              </thead>
      `;

  let tableBody = `
          <tbody>
  
      `;

  tableBody += generateCalendarBody(rows, columns);

  tableBody += '</tbody></table>';

  return tableHead + tableBody;
}

function generateCalendarBody(rows, columns) {
  let tableBody = '';
  for (let row = 0; row < rows; row++) {
    tableBody += `
              <tr id = "Week${row + 1}">
          `;
    for (let column = 0; column < columns; column++) {
      var cellDate = getCellDate(row, column);
      var cellContent = getCellEvents(row, column);
      tableBody += `
              <td id="[${row}][${column}]" onclick="createCalEvent(${row}, ${column})" style="vertical-align:top" class="${
        getDay(row, column) % 2 === 0 ? 'darker' : ''
      }">${cellDate}<br><br><br><span id="cell-content">${cellContent}</span></td> 
          `;
    }

    tableBody += '</tr>';
  }
  return tableBody;
}

function getDay(row, column) {
  return row * 7 + (column + 1);
}