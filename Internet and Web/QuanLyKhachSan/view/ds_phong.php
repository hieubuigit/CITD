<?php

// Get data here
$danhSachPhong = array();

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Danh sach cac phong</title>
</head>
<style>
    table,
    th,
    td {
        border: 1px solid black;
    }
</style>

<body>

    <h1>Danh sach cac phong</h1>
    <a href="./index.php">Home</a>
    <table>
        <tr>
            <th>Mã phòng</th>
            <th>Tên phòng</th>
            <th>Tình trạng</th>
            <th>Loại phòng</th>
            <th>Chức năng</th>
        </tr>
        <tr>
            <!-- Loop here -->
            <?php foreach ($danhSachPhong as $phong => $value) {
                if (isset($phong)) {
                    echo "<td>$value</td>";
                }
            }
            ?>
        </tr>
    </table>

</body>

</html>