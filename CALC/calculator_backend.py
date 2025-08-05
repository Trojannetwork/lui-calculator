# Simple Flask backend for Lui Calculator
# This server receives calculation requests from the web UI, calls the C calculator, and returns the result.

from flask import Flask, request, jsonify
import subprocess
import os

app = Flask(__name__)

# Path to your compiled C calculator
CALCULATOR_PATH = os.path.join(os.path.dirname(__file__), 'calculator')

@app.route('/calculate', methods=['POST'])
def calculate():
    data = request.json
    num1 = str(data.get('num1'))
    op = str(data.get('op'))
    num2 = str(data.get('num2'))
    try:
        # Call the C calculator as a subprocess
        result = subprocess.check_output([CALCULATOR_PATH, num1, op, num2], stderr=subprocess.STDOUT)
        output = result.decode('utf-8').strip()
        return jsonify({'result': output})
    except subprocess.CalledProcessError as e:
        return jsonify({'result': 'Error'}), 400

if __name__ == '__main__':
    app.run(host='127.0.0.1', port=5000, debug=True)
