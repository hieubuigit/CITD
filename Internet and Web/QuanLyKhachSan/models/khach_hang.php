<?php

include "../models/db.php";

class KhachHang extends DB
{
    public function addKhachHang($maKH, $tenKH, $sdt, $cccd)
    {
        $sql = "INSERT INTO khachhang (MAKH, TENKH, SDT, CCCD)
                VALUES ('$maKH', '$tenKH', '$sdt', '$cccd')";
        return $this->selectNonQuery($sql);
    }

    public function dropdownListKH()
    {
        $sql = "SELECT kh.MAKH, kh.TENKH from khachhang kh;";
        return $this->select($sql);
    }

    public function getAllKhLimit($limit)
    {
        $sql = "SELECT kh.MAKH, kh.TENKH, SUM(hd.TONGTIEN) as TONGTIEN
                from khachhang kh
                left join hoadon hd on kh.MAKH = hd.MAKH
                left join thue t on hd.MAHD = t.MAHD
                group by kh.MAKH
                order by SUM(hd.TONGTIEN) desc";
        if (isset($limit)) {
            $sql .= " limit $limit;";
        }
        return $this->select($sql);
    }
}
