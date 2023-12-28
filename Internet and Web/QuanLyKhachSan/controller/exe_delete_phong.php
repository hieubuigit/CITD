<?php

include "../models/phong.php";

$maPhong = $_GET["maPhong"];

$phong = new Phong();
$result = $phong->deletePhong($maPhong);

if ($result) {
    echo "Delete phong successfully";
}
else {
    die("Delete phong failed");
}

?>