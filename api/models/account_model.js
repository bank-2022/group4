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

      'insert into account (fname,lname,username,password) values(?,?,?,?)',
      [account.fname, account.lname, account.username,account.password],

      'insert into account (id_account,accountNumber,balance) values(?,?,?,?)',
      [account.id_account, account.accountNumber],

      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(

      'update account set fname=?,lname=?, username=?, password=? where id_account=?',
      [account.fname, account.lname, account.username, account.password, id],

      'update account set id_account=?, accountNumber=?, balance? where id_account=?',
      [account.id_account, account.accountNumber, id],

      callback
    );
  }
};
module.exports = account;