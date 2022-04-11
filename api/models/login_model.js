const db = require('../database');

const login={

  checkPassword: function(cardNumber, callback) {
      return db.query('SELECT cardPIN FROM card WHERE cardNumber = ?',[cardNumber], callback); 

  checkPassword: function(username, callback) {
      return db.query('SELECT password FROM pankkiautomaatti WHERE username = ?',[username], callback); 

    }
};
          
module.exports = login;