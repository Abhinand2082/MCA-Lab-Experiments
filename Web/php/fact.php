<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $number = $_POST['number'];

        
        if (is_numeric($number) && $number >= 0 && floor($number) == $number) {
            $factorial = 1;

            for ($i = 1; $i <= $number; $i++) {
                $factorial *= $i;
            }

            echo "<p>The factorial of $number is $factorial.</p>";
        } else {
            echo "<p>Please enter a non-negative integer.</p>";
        }
    }
    ?>


