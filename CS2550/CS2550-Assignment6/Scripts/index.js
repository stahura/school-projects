function requestForIndex() {
  let request = new XMLHttpRequest();
  //let jsmonth = null

  console.log("making new xmlhttprequest...");

  request.open("GET", './json/sample.json', false); //D:\Riley\Programming\Code\School\CS2550\CS2550-Assignment6\json\sample.json
  request.send(null);
  //Cross-Origin Request Blocked: The Same Origin Policy disallows reading the remote resource at file:///D:/Riley/Programming/Code/School/CS2550/CS2550-Assignment6/json/sample.json.
  let response = JSON.parse(request.responseText);
  let year = response["2019"];
  console.log(response["2019"]);

  let parent = document.getElementById("parent");
  let child = document.createElement("pre");

  parent.appendChild(child);

  child.innerHTML = ` <span id="jsonDescription"><b>The following is what is found within the sample.json file</b></span> <br> <br>
    
    [${year.January.cellEvents}]
    [${year.February.cellEvents}]
    [${year.March.cellEvents}]
    [${year.April.cellEvents}]
    [${year.May.cellEvents}]
    [${year.June.cellEvents}]
    [${year.July.cellEvents}]
    [${year.August.cellEvents}]
    [${year.September.cellEvents}]
    [${year.October.cellEvents}]
    [${year.November.cellEvents}]
    [${year.December.cellEvents}]
    `;
}

requestForIndex();