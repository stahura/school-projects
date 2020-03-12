function showHTML() {
    const gridDiv = document.getElementById("gridDiv")
    gridDiv.innerHTML = genHTML();
}

function genHTML() {
    const rows = 5
    const columns = 7
    const daysOfWeek = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', ]

    let tableHead = `
    <table>
        <caption id="MonthYear"><b>June 2019<b>
        </caption>
        <thead id="M-F">
            <tr>
                ${daysOfWeek.map(day => {
                    return `
                        <th>${day}</th>
                    `
                }).join('')}
            </tr> 
            </thead>
    `


    let tableBody = `
        <tbody>

    `

    tableBody += generateCalendarBody(rows, columns)

    tableBody += "</tbody></table>"


    return tableHead + tableBody

}

function generateCalendarBody(rows, columns) {
    let tableBody = ""
    for (let row = 0; row < rows; row++) {
        tableBody += `
            <tr id = "Week${row + 1}">
        `
        for (let column = 0; column < columns; column++) {
            tableBody += `
            <td style="vertical-align:top" class="${getDay(row,column) % 2 === 0 ? 'darker' : ''}" >${getDay(row, column) <= 30 ? getDay(row, column) : '-'}</td> 
        `
        }
        tableBody += "</tr>"
    }
    return tableBody
}

function getDay(row, column) {
    return (row * 7) + (column + 1)
}


// const days = [{
//         events: [{
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             },
//             {
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             } {
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             } {
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             }
//         ]
//     }, {
//         events: []
//     },
//     {
//         events: [{
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             },
//             {
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             } {
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             } {
//                 title: "Brothers wedding",
//                 time: "9:00 am",
//                 location: "temple"
//             }
//         ]
//     }
// ]