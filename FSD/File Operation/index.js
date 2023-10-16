// Node.js File Information Method:
// Syntax:   fs.stat(path, callback)  
// Parameter explanation:
// Path: This is string having file name including path.
// Callback: This is the callback function which gets two arguments (err, stats) where stats is an object of fs.Stats type.

const http = require('http');
const fs = require('fs');
http.createServer(function (req, res) {
    fs.readFile('form.html', function (err, data) {
        if (err) {
            return console.error(err);
        }
        console.log("Asynchronous read: " + data.toString());

        console.log("Going to get file info!");
        fs.stat('input.txt', function (err, stats) {
            if (err) {
                return console.error(err);
            }
            console.log(stats);
            console.log("Got file info successfully!");
            // Check file type  
            console.log("isFile ? " + stats.isFile());
            console.log("isDirectory ? " + stats.isDirectory());
        });

        res.writeHead(200, { 'Content-Type': 'text/html' });
        res.write(data);
        return res.end();

    });
}).listen(8080);