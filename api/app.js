var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var accountRouter = require('./routes/account');

var transactionsRouter = require('./routes/transactions');

var clientRouter = require('./routes/client');
var cardRouter = require('./routes/card');
var accountclientRouter = require('./routes/accountclient');
var loginRouter = require('./routes/login');
const { JsonWebTokenError } = require('jsonwebtoken');


var app = express();

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/login', loginRouter);
app.use(authenticateToken);
app.use('/account', accountRouter);

app.use('/transactions',transactionsRouter);

app.use('/client', clientRouter);
app.use('/card', cardRouter);
app.use('/accountclient', accountclientRouter);


function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]

    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)

    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
        console.log(err)
        if (err) return res.sendStatus(403)

        req.user = user

        next()
    })
}


module.exports = app;
