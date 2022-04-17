const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.cardNumber && request.body.cardPIN){
      const cardNumber = request.body.cardNumber;
      const cardPIN = request.body.cardPIN;
        login.checkPassword(cardNumber, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(cardPIN,dbResult[0].cardPIN, function(err,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  const token = generateAccessToken({ cardNumber: cardNumber });
                  response.send(token);
                }
                else {
                    console.log("wrong cardPIN");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("cardNumber or cardPIN missing");
      response.send(false);
    }
  }
);

function generateAccessToken(cardNumber) {
  dotenv.config();
  return jwt.sign(cardNumber, process.env.MY_TOKEN, { expiresIn: '1800s'});
}
module.exports=router;