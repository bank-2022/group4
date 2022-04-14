const db = require('../database');

const login={
  checkcardPIN: function(username, callback) {
      return db.query('SELECT password FROM pankkiautomaatti WHERE username = ?',[username], callback); 
    }
};
          
module.exports = login;