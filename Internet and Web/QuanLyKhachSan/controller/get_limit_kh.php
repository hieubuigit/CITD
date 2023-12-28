<?php

include "../models/khach_hang.php";

$limit = $_GET["limit"];
$kh = new KhachHang();

$listKH = $kh->getAllKhLimit((int)$limit);
$html = "
  <tr>
            <th>STT</th>
            <th>Mã khách hàng</th>
            <th>Tên khách hàng</th>
            <th>Tổng tiền thuê</th>
        </tr>
";
$stt = 0;
foreach ($listKH as $kh) {
    $stt++;
    $html .= "
    <tr>
        <td> $stt </td>
        <td>" . $kh["MAKH"] . "</td>
        <td>" . $kh["TENKH"] . "</td>
        <td>" . $kh["TONGTIEN"] . "</td>
    </tr>
    ";
}
echo $html;
