<?php

include "../models/db.php";

class HoaDon extends DB {

    public function addHoaDon($maHD, $tenHD, $maKH, $tongTien) {
        $sql = "INSERT INTO hoadon (MAHD, TENHD, TONGTIEN, MAKH)
                VALUES ('$maHD', '$tenHD', '$tongTien', '$maKH')";
       return $this->selectNonQuery($sql);
    }

}
