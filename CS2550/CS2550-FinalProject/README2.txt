HTML5 video element was added to index.html. A javascript function in the index.js file causes it to play. I did not use 
the autoplay attribute in the html document. 

Once the page is loaded, the script runs and calls the user-defined function:

function playVideo() {
    let video = document.getElementById("vid");
    video.play();
}

**IMPORTANT**
A password is NOT required to login to the calendar. If you don't want to login, you can click the button where it says :

"           My version of the Event Calendar can be found HERE"

Located on line 46 of the html document 