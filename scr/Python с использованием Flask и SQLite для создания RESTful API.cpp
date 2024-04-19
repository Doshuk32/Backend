# app.py
from flask import Flask, request, jsonify
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///mydatabase.db'
db = SQLAlchemy(app)

class Item(db.Model) :
    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.String(50), nullable = False)
    description = db.Column(db.String(255))

    @app.route('/items', methods = ['POST'])
    def create_item() :
    data = request.json
    new_item = Item(name = data['name'], description = data.get('description', ''))
    db.session.add(new_item)
    db.session.commit()
    return jsonify({ 'message': 'Item created successfully' })

    @app.route('/items', methods = ['GET'])
    def get_items() :
    items = Item.query.all()
    items_list = []
    for item in items :
items_list.append({ 'id': item.id, 'name' : item.name, 'description' : item.description })
return jsonify(items_list)

if __name__ == '__main__' :
    db.create_all()
    app.run(debug = True)