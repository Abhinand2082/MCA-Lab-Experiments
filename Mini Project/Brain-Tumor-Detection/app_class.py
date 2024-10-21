from flask import Flask, request, jsonify, render_template
from keras.models import load_model
from keras.preprocessing.image import img_to_array, load_img
import numpy as np
import os

app = Flask(__name__)

# Load your pre-trained model
model = load_model('model/brain_tumor_classification_mobilenet.h5')

# Define image size
IMAGE_SIZE = (224, 224)

# Define a function to preprocess the uploaded image
def preprocess_image(image_path):
    image = load_img(image_path, target_size=IMAGE_SIZE)
    image = img_to_array(image)
    image = np.expand_dims(image, axis=0)
    image = image / 255.0  # Normalize the image
    return image

# Define a function to predict the tumor type
def predict_tumor(image_path):
    processed_image = preprocess_image(image_path)
    prediction = model.predict(processed_image)
    classes = ['Notumor', 'Glioma', 'Meningioma', 'Pituitary']  # Update class names as per your model
    predicted_class = classes[np.argmax(prediction)]
    return predicted_class

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload():
    if 'image' not in request.files:
        return jsonify({'error': 'No file part'}), 400

    file = request.files['image']
    if file.filename == '':
        return jsonify({'error': 'No selected file'}), 400

    # Save the file to a temporary location
    image_path = os.path.join('uploads', file.filename)
    file.save(image_path)

    # Make prediction
    result = predict_tumor(image_path)

    # Optionally, delete the uploaded image after prediction
    os.remove(image_path)

    return jsonify({'result': result})

if __name__ == '__main__':
    # Create uploads directory if it doesn't exist
    os.makedirs('uploads', exist_ok=True)
    app.run(debug=True)
