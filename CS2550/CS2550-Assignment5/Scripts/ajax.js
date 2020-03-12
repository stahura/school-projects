document.getElementById("ajaxButton").addEventListener('click', makeRequest)
let recordObject = {
    "logRecords": []
};


function makeRequest() {
    let userVal = document.getElementById("ajaxUser").value;
    let passVal = document.getElementById("ajaxPassword").value;
    let httpRequest = new XMLHttpRequest();

    console.log("executing makeRequest Function")
    console.log(`userVal is: ${userVal} and passVal is: ${passVal}`)

    if (!httpRequest) {
        alert('cannot create xmlhttp instance')
        return false;
    }

    console.log(`sending: userName=${userVal}&password=${passVal}`)
    httpRequest.open('POST', 'http://universe.tc.uvu.edu/cs2550/assignments/PasswordCheck/check.php', false)
    httpRequest.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    httpRequest.send(`userName=${userVal}&password=${passVal}`)


    if (httpRequest.status === 200) {

        let responseJson = JSON.parse(httpRequest.responseText);
        console.log(`Username password combo was ${responseJson["result"]}`)
        document.getElementById("ajaxLoginStatus").innerHTML =
            `Username password combination was ${responseJson["result"]}`;

        if (responseJson["result"] == "valid") {
            let today = new Date();
            let time = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();
            let logInfo = `${userVal} ${time}`;
            storeLogin(logInfo)
            navigateToCalendar()

        }

    }


}

function storeLogin(logInfo) {
    recordObject.logRecords.push(logInfo)
    let recordObjectStr = JSON.stringify(recordObject.logRecords)
    localStorage.record = recordObjectStr
    localStorage.setItem("cs2550timestamp", recordObjectStr)

}

function navigateToCalendar() {
    //window.open("calendar.html", "_self")
    window.open("calendar.html")
}