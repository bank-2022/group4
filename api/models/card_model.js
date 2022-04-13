const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where accounts_idAccounts=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(card, callback) {
    bcrypt.hash(card.cardPIN, saltRounds, function(err, hash) {
      return db.query('insert into card (accounts_idAccounts, client_idClient, cardNumber, cardPIN) values(?,?,?,?)',
      [card.accounts_idAccounts, card.client_idClient, card.cardNumber, hash], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from card where accounts_idAccounts=?', [id], callback);
  },
  update: function(id, card, callback) {
    bcrypt.hash(card.cardPIN, saltRounds, function(err, hash) {
      return db.query('update card set accounts_idAccounts=?, client_idClient=?, cardNumber=?, cardPIN=? WHERE accounts_idAccounts=?',
      [card.accounts_idAccounts, card.client_idClient, card.cardNumber, hash, id], callback);
    });
  }
};
module.exports = card;