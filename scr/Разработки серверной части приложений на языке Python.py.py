import json
import requests

def get_data():
 url = 'https://api.example.com/data'
 headers = {'Content-Type': 'application/json'}
 response = requests.get(url, headers=headers)
 data = response.json()
 return data

def post_data(data):
 url = 'https://api.example.com/data'
 headers = {'Content-Type': 'application/json'}
 response = requests.post(url, headers=headers, data=json.dumps(data))
 return response.status_code

if __name__ == '__main__':
 data = get_data()
 print(data)
 status_code = post_data(data)
 print(status_code)
