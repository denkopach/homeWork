function makeCounter() {
    var currentCount = 1;

    return function() {
        return currentCount++;
    };
}
var counter = makeCounter();
function addFieldTask(response){
    var count = counter();
    var newdiv = document.createElement('div');
    newdiv.setAttribute("id", 'div' + count);
    document.getElementById('history').appendChild(newdiv);

    var newmsg = response;
    var newlabel = document.createElement('label');
    var textnode = document.createTextNode(newmsg.task);
    newlabel.appendChild(textnode);
    newlabel.setAttribute("id", 'label' + count);
    document.getElementById('div' + count).appendChild(newlabel);

    var btn = document.createElement("button");
    var t = document.createTextNode("x");
    btn.setAttribute("id", 'btn' + count);
    var delTask = 'removeTask(' + count + ')';
    btn.setAttribute("onclick", delTask);
    btn.appendChild(t);
    document.getElementById('div' + count).appendChild(btn);
}

function addTaskFromDB(){
    fetch('/addAllTasks', {
        method: "POST",
        headers: new Headers({
            'Content-Type': 'application/json'
        })
    }).then(function(response){
        console.log(response);
        return response.json();
    }).then(function(response) {
        var i = 0;
        while(response[i]){
            addFieldTask(response[i]);
            i++;
        }
    }, function(error) {
        console.log(error)
    });
}

function removeTask(id){
    var el = document.getElementById('div' + id);
    var valEl = document.getElementById('label' + id).textContent;

    fetch('/removeTask', {
        body: JSON.stringify({
            task: {
                task: valEl
            }
        }),
        method: "POST",
        headers: new Headers({
            'Content-Type': 'application/json'
        })

    });

    el.parentNode.removeChild(el);
}
function createNewTask(){
    var newtask = document.getElementById("task").value;
    fetch('/newtask', {
        method: "POST",
        body: JSON.stringify({
            task: {
                task: newtask
            }
        }),
        headers: new Headers({
            'Content-Type': 'application/json'
        })
    }).then(function(response){
        return response.json();
    }).then(function(response) {
        addFieldTask(response);
    }, function(error) {
        console.log(error) //=> String
    });
}