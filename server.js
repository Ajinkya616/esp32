const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

app.use(bodyParser.text());

app.post('/data', (req, res) => {
  const receivedData = req.body;
  console.log('Received data:', receivedData);
  // Process the received data here, you can simply log it for now

  res.send('Data received successfully');
});

app.listen(port, () => {
    console.log(Server running at http://localhost:${port});
});
