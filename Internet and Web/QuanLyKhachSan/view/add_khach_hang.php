<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Them Khach Hang</title>
</head>
<body>

    <h1>Thêm khách hàng</h1>
    <form action="../controller/exe_add_khach_hang.php" method="post">
        <label for="maKH">
            Mã khách hàng:
            <input type="text" name="maKH" id="maKH" placeholder="Mã khách hàng">
        </label>
        <br>
        <label for="tenKH">
            Tên khách hàng:
            <input type="text" name="tenKH" id="tenKH" placeholder="Tên khách hàng">
        </label>
        <br>
        <label for="sdt">
            Số điện thoại:
            <input type="text" name="sdt" id="sdt" placeholder="Số điện thoại">
        </label>
        <br>
        <label for="cccd">
            CCCD:
            <input type="text" name="cccd" id="cccd" placeholder="CCCD">
        </label>
        <br>
        <button type="submit">Thêm</button>
    </form>

</body>
</html>