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
      'insert into card (fname,lname,username,password) values(?,?,?,?)',
      [card.fname, card.lname, card.username,card.password],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, card, callback) {
    return db.query(
      'update card set fname=?,lname=?, username=?, password=? where id_card=?',
      [card.fname, card.lname, card.username, card.password, id],
      callback
    );
  }
};
module.exports = card;