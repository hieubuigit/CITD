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
    <br>
    <label for="soKH">Số khách hàng: </label>
    <input id="soKH" type="number" name="soKH" value="" placeholder="Số khách hàng">

    <table id="dsKH">
        <tr>
            <th>STT</th>
            <th>Mã khách hàng</th>
            <th>Tên khách hàng</th>
            <th>Tổng tiền thuê</th>
        </tr>
            <?php
            include "../models/khach_hang.php";
            $kh = new KhachHang();
            $listKH = $kh->getAllKhLimit(null);

            $stt = 0;
            foreach ($listKH as $kh) {
                $stt++;
            ?>
                <tr>
                    <td><?php echo $stt; ?></td>
                    <td><?php echo $kh["MAKH"] ?></td>
                    <td><?php echo $kh["TENKH"] ?></td>
                    <td><?php echo $kh["TONGTIEN"] ?></td>
                </tr>
            <?php } ?>
    </table>
</body>

</html>

<script src="https://code.jquery.com/jquery-3.7.1.js" integrity="sha256-eKhayi8LEQwp4NKxN+CfCh+3qOVUtJn3QNZ0TciWLP4=" crossorigin="anonymous"></script>
<script type="text/javascript">
    $("#soKH").on("keydown", function(res) {
        if (res.keyCode == 9) { // 9 is Tab

            let value = $(this).val();
            let origin = window.location.origin;
            let url = origin + `/QuanLyKhachSan/controller/get_limit_kh.php?limit=${value}`;

            $.ajax({
                type: "GET",
                url: url,
                dataType: "html",
                success: function(res) {
                    $('#dsKH').html(res);
                }
            });
        }
    });
</script>