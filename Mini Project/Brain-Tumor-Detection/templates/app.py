from flask import Flask, render_template, request, redirect, url_for, send_from_directory
import os

app = Flask(__name__)

# Create an uploads folder
UPLOAD_FOLDER = 'uploads'
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

# Home page
@app.route('/')
def home():
    return render_template('index.html')

# Upload page
@app.route('/upload')
def upload():
    return render_template('upload.html')

# Handle results
@app.route('/results', methods=['POST'])
def results():
    if 'file' not in request.files:
        return redirect(request.url)
    
    file = request.files['file']
    if file.filename == '':
        return redirect(request.url)
    
    if file:
        # Save uploaded image
        filepath = os.path.join(app.config['UPLOAD_FOLDER'], file.filename)
        file.save(filepath)
        
        # Placeholder for prediction results
        results = {
            'Model 1': 'No Tumor',
            'Model 2': 'Tumor Detected'
        }
        
        return render_template('results.html', results=results, filename=file.filename)

# Serve uploaded files
@app.route('/uploads/<filename>')
def uploaded_file(filename):
    return send_from_directory(app.config['UPLOAD_FOLDER'], filename)

if __name__ == '__main__':
    app.run(debug=True)
