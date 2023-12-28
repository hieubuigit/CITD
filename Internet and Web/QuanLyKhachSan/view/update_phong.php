<?php

$maPhong = $_GET["maPhong"];
$tenPhong = $_GET["tenPhong"];
$tinhTrang =  $_GET["tinhTrang"];
$loaiPhong = $_GET["loaiPhong"];

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Update phong</title>
</head>

<body>
    <h1>Cap nhat phong</h1>
    <form action="../controller/exe_update_phong.php" method="post">
        <label for="maPhong">
            Mã phòng:
            <input type="text" name="maPhong" value="<?php echo $maPhong; ?>" id="maPhong" placeholder="Mã phòng">
        </label>
        <br>
        <label for="tenPhong">
            Tên phòng:
            <input type="text" name="tenPhong" value="<?php echo $tenPhong; ?>" id="tenPhong" placeholder="Tên phòng">
        </label>
        <br>
        <label for="tinhTrang">
            Tình trạng:
            <input type="text" name="tinhTrang" value="<?php echo $tinhTrang; ?>" id="tinhTrang" placeholder="Tình trạng">
        </label>
        <br>
        <label for="loaiPhong">
            Loại phòng:
            <input type="text" name="loaiPhong" value="<?php echo $loaiPhong; ?>" id="loaiPhong" placeholder="Loại phòng">
        </label>
        <br>
        <button type="submit">Update</button>
    </form>

</body>

</html>
