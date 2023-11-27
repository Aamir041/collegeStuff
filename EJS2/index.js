// EXPRESS CONNECTION
const express = require("express");
const bodyParser = require("body-parser");
const ejs = require("ejs");
const mysql = require("mysql2");

const conn = mysql.createConnection({
    host:"localhost",
    user:"root",
    password:"",
    database:"ejstodo"
});

let todos;

const app = express();
app.set('view engine','ejs');
app.use(bodyParser.urlencoded({extended:true}));

app.get("/",(req,res)=>{
    conn.query("SELECT * FROM lists", (err,res,feilds) => {
        todos = res;
    })
    console.log(todos);
    res.render("list",{ todoList:todos});
})

app.post("/", (req,res) => {
    let name = req.body.name;
    let email = req.body.email;
    let city = req.body.city ;
    let state = req.body.state;
    conn.query(`INSERT INTO lists VALUES('${name}','${email}','${city}','${state}')`,(err,res,feilds) => {
        if(err) console.log("INSERT ERR: ",err);
        else console.log("INSERT RES: ",res)
    });
    res.redirect("/");
})



app.listen(4000,() =>{
    console.log("Server Running At Port 4000!");
})