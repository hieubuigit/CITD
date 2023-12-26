<?php

// Get customers in database fill to select


?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Thêm hoá đơn</title>
</head>

<body>

    <h1>Thêm hoá đơn</h1>
    <a href="./index.php">Home</a>
    <form action="../controller/exe_add_hoa_don.php" method="post">
        <label for="tenKH">
            Tên khách hàng:
            <select name="maKH" id="maKH" placeholder="Tên khách hàng">
                <option value="<?php echo "mKH"; ?>">value 1</option>
            </select>
        </label>
        <br>
        <label for="maHD">
            Mã hoá đơn:
            <input type="text" name="maHD" id="maHD" placeholder="Mã hoá đơn">
        </label>
        <br>
        <label for="tenHD">
            Tên hoá đơn:
            <input type="text" name="tenHD" id="tenHD" placeholder="Tên hoá đơn">
        </label>
        <br>
        <label for="tongTien">
            Tổng tiền:
            <input type="number" name="tongTien" id="tongTien" placeholder="Tổng tiền">
        </label>
        <br>
        <button type="submit">Thêm</button>
    </form>

</body>

</html>