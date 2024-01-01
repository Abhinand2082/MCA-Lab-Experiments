
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_REQUEST['name'];
        $email = $_REQUEST['email'];
        $address = $_REQUEST['address'];
        $gender = $_REQUEST['gender'];
        $dob = $_REQUEST['dob'];

        echo "<h3>Student Details:</h3>";
        echo "Name: $name<br>";
        echo "Email Id: $email<br>";
        echo "Address: $address<br>";
        echo "Gender: $gender<br>";
        echo "Date of Birth: $dob";
    }
    ?>
