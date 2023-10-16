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

const app = express();
app.use(bodyParser.urlencoded({extended:true}));

app.get("/",(req,res)=>{
    res.send("Hello World!");
})

app.listen(4000,() =>{
    console.log("Server Running At Port 4000!");
})