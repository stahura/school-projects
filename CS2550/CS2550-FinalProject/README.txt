The JSON file loaded is located at json/sample.json.

The function responsible for creating the XMLHttpRequest is located at:
    model.js: function requestCalendarJson(): Line 227.
    mode.js is called in the updateMonth() function: line 176.

The information in the JSON file contains grids that hold events. updateMonth() will pass in
the currentMonth(which is decided with the select menu on the calendar) to the requestCalendarJson() function. 
That month that is passed in will go through a switch statement, allowing me to return the proper month grid. When it returns, 
is uses a for loop to insert the events in the currect dates. This persists after changing months. If you insert new events in the json file, it
will show up on the Calendar Grid. Switch between months to see the changes take place and persist

The information will show up in the middle of the corresponding table cell. 

In displaying parsed data in the Calendar Grid, I am displaying the parsed data on the "game page". 

The entirety of the json file is parsed on the bottom of the game description page. If you add something to the json arrays,
the change will be updated on the description page. The function responsible for displaying that information is found in index.js

**IMPORTANT** Firefox was used for all testing

