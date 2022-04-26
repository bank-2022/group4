const db = require('../database');

const login={
  
  checkcardPIN: function(cardNumber, callback) {
      return db.query('SELECT cardPIN FROM card WHERE cardNumber = ?',[cardNumber], callback); 
    }
};
          
module.exports = login;