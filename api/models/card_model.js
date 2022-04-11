const db = require('../database');

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where id_card=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(card, callback) {
    return db.query(
      'insert into card (accounts_idAccounts,client_idClient,cardNumber,cardPIN) values(?,?,?,?)',
      [card.accounts_idAccounts, card.name, card.cardNumber, card.cardPIN],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, card, callback) {
    return db.query(
      'update card set accounts_idAccounts=?,name=?, cardNumber=?, cardPIN=?, where id_card=?',
      [card.accounts_idAccounts, card.name, card.cardNumber, card.cardPIN, id],
      callback
    );
  }
};
module.exports = card;