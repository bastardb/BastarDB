const fs = require('fs')
 
for(var i=0;i<100000;i++) {
    fs.writeFile("/tmp/db/d"+i+".json.part", '{ "test": 1 }', "utf8", function () {
        fs.rename("/tmp/db/d"+i+".json.part", "/tmp/db/d"+i+".json");
    });
}
