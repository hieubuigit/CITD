<?php
include "db.php";

class Phong extends DB
{
    public function getAllPhong()
    {
        $sql = "SELECT * FROM phong;";
        return $this->select($sql);
    }

    public function getPhongByMaPhong($maPhong)
    {
        $sql = "SELECT * from phong where MAPHONG = $maPhong limit 1;";
        return $this->select($sql);
    }

    public function updatePhong($maPhong, $tenPhong, $tinhTrang, $loaiPhong)
    {
        $sql = "UPDATE phong SET MAPHONG = '$maPhong', TENPHONG = '$tenPhong', TINHTRANG = '$tinhTrang', LOAIPHONG = '$loaiPhong' WHERE MAPHONG = '$maPhong'";
        return $this->selectNonQuery($sql);
    }

    public function deletePhong($maPhong) {
        $sql = "DELETE from phong where MAPHONG = '$maPhong';";
        return $this->selectNonQuery($sql);
    }
}

?>
