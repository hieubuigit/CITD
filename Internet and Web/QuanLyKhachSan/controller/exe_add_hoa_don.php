<?php

include '../models/hoa_don.php';

$maKH = $_POST["maKH"];
$maHD = $_POST["maHD"];
$tenHD =  $_POST["tenHD"];
$tongTien = $_POST["tongTien"];

$hd = new HoaDon();
$resultAdd = $hd->addHoaDon($maHD, $tenHD, $maKH, $tongTien);
if ($resultAdd) {
    echo "Them thanh cong!";
} else {
    echo "Them that bai!";
}

?>