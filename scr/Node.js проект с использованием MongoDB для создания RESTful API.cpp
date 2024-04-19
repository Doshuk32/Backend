// app.js
const express = require('express');
const bodyParser = require('body-parser');
const mongoose = require('mongoose');

const app = express();

app.use(bodyParser.json());

mongoose.connect('mongodb://localhost/mydatabase', {
  useNewUrlParser: true,
  useUnifiedTopology : true
    });
const db = mongoose.connection;

db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function() {
    console.log('Connected to MongoDB');
});

const itemSchema = new mongoose.Schema({
  name: String,
  description : String
    });

const Item = mongoose.model('Item', itemSchema);

app.post('/items', (req, res) = > {
    const newItem = new Item({
      name: req.body.name,
      description : req.body.description
        });
    newItem.save((err, item) = > {
        if (err) {
            res.status(500).send(err);
        }
        else {
            res.status(201).json(item);
        }
    });
});

app.get('/items', (req, res) = > {
    Item.find((err, items) = > {
        if (err) {
            res.status(500).send(err);
        }
        else {
            res.json(items);
        }
    });
});

app.listen(3000, () = > {
    console.log('Server running on port 3000');
});