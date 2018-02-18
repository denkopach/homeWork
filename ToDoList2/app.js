var express = require('express');
var app = express();
var path = require('path');
var bodyParser = require('body-parser');
var id = 0;
var mysql = require('mysql');

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, 'public')));

app.use(function(req, res, next){
    res.setHeader('Access-Control-Allow-Origin', 'http://localhost:3000');
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With, content-type');
    res.setHeader('Acces-Control-Allow-Credentials', true);
    next();
});

app.get('/', function (req, res) {
    res.header('Content-type: text/html');
    res.sendFile(path.join(__dirname + '/public/index.html'));
});

app.post('/newtask', function(req, res){

    var newmessage = {
        task: req.body.task.task,
        id: id++
    };
    addTaskInDB(newmessage.task);
    res.send(JSON.stringify(newmessage));
});

app.post('/removeTask', function(req, res){
    console.log(req.body.task.task);

    var connection = getMySQL_connection();
    var sql = 'DELETE FROM `tasks` WHERE task = \'' + req.body.task.task + '\'';
    connection.query(sql, function (err, rows) {
        if (err) {
            throw err
        }else{
            connection.end();
            res.send("status:200");
        }
    });
});

app.post('/addAllTasks', function(req, res){
    var connection = getMySQL_connection();
    var sql = "SELECT task FROM tasks";
    connection.query(sql, function (err, rows) {
        if (err) {
            throw err
        }else{
            connection.end();
            res.send((JSON.parse(JSON.stringify(rows))));

        }
    });
});


app.listen(3000, function () {
    console.log('Example app listening on port 3000')
});

function getMySQL_connection(){
    var con = mysql.createConnection({
        host: 'localhost',
        user: 'admin',
        password: 'admin',
        database: 'toDoList'
    });

    con.connect(function (err) {
        if (err) throw err;
        console.log("Connected mysql OK!");
    });
    return(con);
}

function addTaskInDB(task){
    var connection = getMySQL_connection();
    var sql = "INSERT INTO tasks (task) VALUES ('" + task + "')";
    connection.query(sql, function (err, rows) {
        if (err) {
            throw err
        }
        connection.end();
    });
}