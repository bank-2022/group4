const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'pankkiautomaattiuser',
  password: 'netpass',
  database: 'pankkiautomaatti'
});
module.exports = connection;