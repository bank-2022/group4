const db = require('../database');

const transactions = {
  getById: function(id, callback) {
    return db.query('select * from transactions where id_transactions=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from transactions', callback);
  },
  add: function(transactions, callback) {
    return db.query(

      'insert into transactions (accountNumber, cardNumber, date_and_time, transaction, sum, accounts_idaccounts ) values(?,?,?,?,?,?)',
      [transactions.accountNumber, transactions.cardNumber, transactions.date_and_time, transactions.transaction, transactions.sum, transactions.accounts_idaccounts],

      'insert into transactions (accountNumber, cardNumber, date_and_time, transaction, sum) values(?,?,?,?,?)',
      [transactions.accountNumber, transactions.cardNumber, transactions.date_and_time, transactions.transaction,transactions.sum],

      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where id_transactions=?', [id], callback);
  },
  update: function(id, transactions, callback) {
    return db.query(

      'update transactions set accountNumber=?,cardNumber=?, date_and_time=?, transaction=?, sum=?, accounts_idaccounts=?, where id_transactions=?',
      [transactions.accountNumber, transactions.cardNumber, transactions.date_and_time, transactions.transaction, transactions.sum, transactions.accounts_idaccounts, id],

      'update transactions set accountNumber=?,cardNumber=?, date_and_time=?, transaction=?, sum=?, =?, where id_transactions=?',
      [transactions.accountNumber, transactions.cardNumber, transactions.date_and_time, transactions.transaction, transactions.sum, id],

      callback
    );
  }
};
module.exports = transactions;