const db = require('../database');

const client = {
  getById: function(id, callback) {
    return db.query('select * from client where id_client=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from client', callback);
  },
  add: function(client, callback) {
    return db.query(
      'insert into client (username,name,address,password) values(?,?,?,?)',
      [client.username, client.name, client.address, client.password],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from client where id_client=?', [id], callback);
  },
  update: function(id, client, callback) {
    return db.query(
      'update client set username=?,name=?, address=?, password=?, where id_client=?',
      [client.username, client.name, client.address, client.password, id],
      callback
    );
  }
};
module.exports = client;