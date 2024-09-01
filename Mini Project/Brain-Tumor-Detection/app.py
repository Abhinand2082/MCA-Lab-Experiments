from flask import Flask, render_template, request, redirect, url_for
import os
from tensorflow.keras.models import load_model
import cv2
import numpy as np
from werkzeug.utils import secure_filename

app = Flask(__name__)

# Set upload folder inside static for easier access
UPLOAD_FOLDER = 'static/uploads'
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

# Load the trained model
model = load_model('model/brain_tumor_detection_cnn.h5')

# Image size (ensure this matches your model's input shape)
img_width, img_height = 150, 150

# Function to process the image
def prepare_image(filepath):
    image = cv2.imread(filepath)
    image = cv2.resize(image, (img_width, img_height))
    image = np.expand_dims(image, axis=0)  # Add batch dimension
    return image / 255.0  # Normalize the image

@app.route('/', methods=['GET', 'POST'])
def upload_predict():
    if request.method == 'POST':
        if 'file' not in request.files:
            return redirect(request.url)
        
        file = request.files['file']
        
        if file.filename == '':
            return redirect(request.url)
        
        if file:
            # Save the uploaded file in the static/uploads folder
            filename = secure_filename(file.filename)
            filepath = os.path.join(app.config['UPLOAD_FOLDER'], filename)
            file.save(filepath)
            
            # Prepare the image and make a prediction
            image = prepare_image(filepath)
            prediction = model.predict(image)
            
            # Access the first prediction value
            prediction_value = prediction[0][0]
            
            # Determine result based on prediction value
            if prediction_value < 0.5:  # No tumor
                result_text = "No Tumor"
                result_color = "green"
            else:  # Tumor detected
                result_text = "Tumor Detected"
                result_color = "red"
            
            # Show the result
            return render_template('result.html', user_image=filename, result_text=result_text, result_color=result_color)
    
    return render_template('upload.html')

if __name__ == '__main__':
    app.run(debug=True)
