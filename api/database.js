const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'pankkiuser',
  password: 'pankkipass',
  database: 'pankkiautomaatti'
});
module.exports = connection;