/* NODE JS CONNECTION */

// const http = require("http");
// const url = require("url");

// http.createServer((req,res) => {
//     res.writeHead(200,{'Content-Type':'text/plain'});
//     let args = url.parse(req.url,true).query;
//     let txt = args.year+ " "+ args.month; // pass localhost:4000/?year=2023&month=October   
//     res.write(txt);
//     res.end();  
// }).listen(4000);
// console.log("PORT Started at 4000");


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
    let date = new Date();
    let todayDate = date.toLocaleDateString("en-US"); 
    console.log(date.toLocaleDateString("en-US"));
    conn.query("SELECT * FROM list", (err,res,feilds) => {
        todos = res;
    })
    res.render("list",{kindOfDay:todayDate, todoList:todos});
})

app.post("/", (req,res) => {
    let newItem = req.body.newItem;
    conn.query(`INSERT INTO list VALUES('${newItem}')`,(err,res,feilds) => {
        if(err) console.log("INSERT ERR: ",err);
        else console.log("INSERT RES: ",res)
    });
    res.redirect("/");
})



app.listen(4000,() =>{
    console.log("Server Running At Port 4000!");
})