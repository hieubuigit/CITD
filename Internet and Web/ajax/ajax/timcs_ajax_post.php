<?php
    include "../database/connect.php";
    $tencs = $_POST['ten'];
    
    $sql = "SELECT * FROM casi where TenCaSi='$tencs'";
    $results = $connect->query($sql);
    if($results->num_rows>0)
        echo "Tìm Thấy";
    else
        echo "Tìm không thấy";
?>