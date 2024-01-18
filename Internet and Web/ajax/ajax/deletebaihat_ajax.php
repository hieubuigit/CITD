<?php
    include "../database/connect.php";
    $mabaihat=$_GET['ma'];
    $str = "delete from baihat where MaBaiHat='$mabaihat'";
    $connect->query($str);      
?>
