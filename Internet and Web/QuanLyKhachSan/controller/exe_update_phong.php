<?php

include "../models/phong.php";

$maPhong = $_POST["maPhong"];
$tenPhong = $_POST["tenPhong"];
$tinhTrang =  $_POST["tinhTrang"];
$loaiPhong = $_POST["loaiPhong"];

$phong = new Phong();
$resultUpdate = $phong->updatePhong($maPhong, $tenPhong, $tinhTrang, $loaiPhong);
if ($resultUpdate) {
    echo "Update phong successfully";
} else {
    die("Update phong failed");
}

?>