# Lui Calculator

A simple, modern web-based calculator app with a C backend for computation and a Python Flask server for communication between the UI and backend.

## Project Structure

- `calculator_ui.html` — The frontend web interface for the calculator. Modern, responsive, and styled with CSS. Sends calculation requests to the backend.
- `calculator_backend.py` — Python Flask server. Receives calculation requests from the UI, calls the C calculator, and returns the result as JSON.
- `calculator.c` — The C program that performs the actual arithmetic calculations. Compiled as an executable and called by the backend.

## How It Works

1. **Frontend**: Users interact with the calculator UI in their browser (`calculator_ui.html`).
2. **Backend**: When a calculation is requested, the UI sends a POST request to the Flask server (`calculator_backend.py`).
3. **C Calculator**: The Flask server calls the compiled C program (`calculator`) with the numbers and operator as arguments, captures the output, and returns it to the frontend.

## Setup & Usage

### 1. Compile the C Calculator

```
gcc calculator.c -o calculator
```

### 2. Install Python Dependencies

```
pip install flask
```

### 3. Run the Flask Backend

```
python calculator_backend.py
```

### 4. Open the Frontend

Open `calculator_ui.html` in your web browser.

## Notes
- The backend expects the compiled C executable to be named `calculator` and located in the same directory.
- The Flask server runs on `http://127.0.0.1:5000` by default.
- The UI is modern and mobile-friendly.

## Author
Lui
