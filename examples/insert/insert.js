const fs = require('fs')
 
for(var i=0;i<100000;i++) {
    fs.writeFileSync("/tmp/db/d"+i+".json.part", '{ "test": 1 }');
    fs.renameSync("/tmp/db/d"+i+".json.part", "/tmp/db/d"+i+".json");
}
