import cv2
import numpy as np
from tensorflow.keras.models import load_model
import matplotlib.pyplot as plt
import os

# Load the trained model from the specified path
model_path = 'Models/brain_tumor_detection_cnn.h5'
model = load_model(model_path)

# Function to predict tumor in an image
def predict_tumor(image_name):
    # Get the current working directory (where the dataset is located)
    current_directory = os.getcwd()
    
    # Create the full path to the image
    image_path = os.path.join(current_directory, image_name)
    
    # Load the image
    image = cv2.imread(image_path)
    
    # Check if image was correctly loaded
    if image is None:
        print(f"Error: Image {image_name} not found.")
        return
    
    original_image = image.copy()

    # Resize the image to the size the model was trained on
    img_size = (150, 150)
    image_resized = cv2.resize(image, img_size)

    # Normalize pixel values to [0, 1]
    image_resized = image_resized / 255.0

    # Add an extra dimension to match the input shape of the model (1, 150, 150, 3)
    image_resized = np.expand_dims(image_resized, axis=0)

    # Predict the result using the loaded model
    prediction = model.predict(image_resized)

    # Check the model's prediction
    if prediction < 0.5:
        label = 'No Tumor Detected'
        color = (0, 255, 0)  # Green rectangle for no tumor
    else:
        label = 'Tumor Detected'
        color = (0, 0, 255)  # Red rectangle for tumor

    # Draw a rectangle around the image
    start_point = (10, 10)
    end_point = (original_image.shape[1] - 10, original_image.shape[0] - 10)
    thickness = 5

    # Draw the rectangle
    cv2.rectangle(original_image, start_point, end_point, color, thickness)

    # Add label text to the image
    font = cv2.FONT_HERSHEY_SIMPLEX
    font_scale = 1
    font_thickness = 2
    text_size = cv2.getTextSize(label, font, font_scale, font_thickness)[0]
    text_x = int((original_image.shape[1] - text_size[0]) / 2)
    text_y = original_image.shape[0] - 20

    # Put text on the image
    cv2.putText(original_image, label, (text_x, text_y), font, font_scale, color, font_thickness)

    # Display the result using matplotlib
    plt.figure(figsize=(8, 8))
    plt.imshow(cv2.cvtColor(original_image, cv2.COLOR_BGR2RGB))
    plt.axis('off')
    plt.show()

# Example usage
if __name__ == '__main__':
    # Image name to be predicted
    image_name = 'an.jpg'
    
    # Call the prediction function
    predict_tumor(image_name)
