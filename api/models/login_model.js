const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT password FROM pankkiautomaatti WHERE username = ?',[username], callback); 
    }
};
          
module.exports = login;