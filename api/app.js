var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');

var indexRouter = require('./routes/index');
var accountRouter = require('./routes/account');

var transactionsRouter = require('./routes/transactions');

var clientRouter = require('./routes/client');
var cardRouter = require('./routes/card');



var app = express();

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/account', accountRouter);

app.use('/transactions',transactionsRouter);

app.use('/client', clientRouter);
app.use('/card', cardRouter);



module.exports = app;
