const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  add: function(account, callback) {
    return db.query(

      'insert into account (id_account,accountNumber,balance) values(?,?,?)',
      [account.id_account, account.accountNumber, account.balance],

      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(

      'update account set id_account=?, accountNumber=?, balance=? where id_account=?',
      [account.id_account, account.accountNumber, account.balance, id],



      callback
    );
  },
getBalance:function(cardNumber, callback){
  return db.query('select id_account, accountNumber, balance from account inner join card on account.id_account=card.accounts_idAccounts where cardNumber=?', [cardNumber], callback);
},

updateBalance:function(id_account, amount,  callback){
  return db.query(
          'update account set amount=?, balance=(balance - amount)  where id_account=?', [amount,id_account],
          callback) 
}
};
module.exports = account;