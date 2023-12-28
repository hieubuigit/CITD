<?php

include "../models/phong.php";

$phong = new Phong();
$dsPhong = $phong->getAllPhong();

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
    <table>
        <tr>
            <th>Mã phòng</th>
            <th>Tên phòng</th>
            <th>Tình trạng</th>
            <th>Loại phòng</th>
            <th>Chức năng</th>
        </tr>
        <!-- Loop here -->
        <?php
        $row = 1;
        foreach ($dsPhong as $phong) { ?>
            <tr class="row<?php $row ?>">
                <td><?php echo $phong["MAPHONG"] ?></td>
                <td><?php echo $phong["TENPHONG"] ?></td>
                <td><?php echo $phong["TINHTRANG"] ?></td>
                <td><?php echo $phong["LOAIPHONG"] ?></td>
                <td>
                    <a href="update_phong.php?<?php echo "maPhong=" . $phong['MAPHONG']
                                                    . "&tenPhong=" . $phong['TENPHONG']
                                                    . "&tinhTrang=" . $phong['TINHTRANG']
                                                    . "&loaiPhong=" . $phong['LOAIPHONG'];
                                                ?> ">
                        View</a>
                    <button type="button" class="btnDelete" onclick="deletePhong('<?php echo $phong['MAPHONG']; ?>', <?php echo $row; ?>)"> Delete </button>
                </td>
            </tr>
        <?php
            $row++;
        } ?>
    </table>

</body>

</html>

<script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
<script type="text/javascript">
    function deletePhong(maPhong, row) {
        let origin = window.location.origin;
        let link = origin + `/QuanLyKhachSan/controller/exe_delete_phong.php?maPhong=${maPhong}`;
        window.open(link, "_self");
        // location.reload(true);
    }
</script>