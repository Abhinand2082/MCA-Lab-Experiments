  <?php
    if(isset($_GET["click"]))
    {
        $n = $_GET['EvenOdd'];
        if($n % 2 == 0)
        {
            echo "$n is even number";
        }
        else
        {
            echo "$n is odd number";
        }
    }
    ?>
