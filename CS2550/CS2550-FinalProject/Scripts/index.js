function requestForIndex() {
    let request = new XMLHttpRequest();
    //let jsmonth = null

    console.log("making new xmlhttprequest...")

    request.open('GET', 'json/sample.json', false)
    request.send(null);

    let response = JSON.parse(request.responseText);
    let year = response["2019"]
    console.log(response["2019"])

    let parent = document.getElementById("parent")
    let child = document.createElement("pre")

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
    `

}

function playVideo() {
    let video = document.getElementById("vid");
    video.play();
}
requestForIndex();
playVideo();