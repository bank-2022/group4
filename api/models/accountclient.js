const db = require('../database');

const accountclient = {
  getById: function(id, callback) {
    return db.query('select * from accountclient where id_accountclient=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from accountclient', callback);
  },
  add: function(accountclient, callback) {
    return db.query(
      'insert into accountclient (accounts_idAccounts, client_idClient) values(?,?,?,?)',
      [accountclient.accounts_idAccounts, accountclient.client_idClient],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from accountclient where id_accountclient=?', [id], callback);
  },
  update: function(id, accountclient, callback) {
    return db.query(
      'update accountclient set accounts_idAccounts=?,client_idClient=?, where id_accountclient=?',
      [accountclient.accounts_idAccounts, accountclient.client_idClient, id],
      callback
    );
  }
};
module.exports = accountclient;