#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

const asyncChar = async function (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (error, response, body) {
      if (error) {
        console.log(error);
      }
      if (response.statusCode === 200) {
        resolve(body);
      }
    });
  });
};

request(url, function (error, response, body) {
  if (error) {
    console.log(error);
  }
  const chars = JSON.parse(body).characters;
  (async function () {
    for (let i = 0; i < chars.length; i++) {
      const response = await asyncChar(chars[i]);
      const name = JSON.parse(response);
      console.log(name.name);
    }
  })();
});
