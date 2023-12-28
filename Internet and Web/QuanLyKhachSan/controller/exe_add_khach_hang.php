<?php

include "../models/khach_hang.php";

$maKH = $_POST["maKH"];
$tenKH = $_POST["tenKH"];
$sdt =  $_POST["sdt"];
$cccd = $_POST["cccd"];

// Add to database here
$kh = new KhachHang();
$resultAdd = $kh->addKhachHang($maKH, $tenKH, $sdt, $cccd);
if ($resultAdd) {
    echo "Add successfully";
} else {
    die("Add failed");
}

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title></title>
</head>

<body>
    <h1>Thông tin khách hàng đã thêm: </h1>
    <p>Mã KH: <?php echo $maKH ?></p>
    <p>Tên KH: <?php echo $tenKH ?></p>
    <p>Số điện thoại: <?php echo $sdt; ?></p>
    <p>CCCD: <?php echo $cccd ?></p>

</body>

</html>