<?php

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Liet ke khach hang</title>
</head>
<style>
    table,
    th,
    td {
        border: 1px solid black;
    }
</style>
<body>

    <h1>Liet ke khach hang</h1>
    <a href="./index.php">Home</a>
    <table>
        <tr>
            <th>STT</th>
            <th>Mã khách hàng</th>
            <th>Tên khách hàng</th>
            <th>Tổng tiền thuê</th>
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