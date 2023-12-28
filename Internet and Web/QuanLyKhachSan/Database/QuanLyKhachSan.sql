CREATE TABLE KHACHHANG (
    MAKH VARCHAR(10) NOT NULL PRIMARY KEY,
    TENKH VARCHAR(200),
    SDT VARCHAR(14),
    CCCD DECIMAL(50)
);

CREATE TABLE PHONG (
    MAPHONG VARCHAR(10) NOT NULL PRIMARY KEY,
    TENPHONG VARCHAR(200),
    TINHTRANG VARCHAR(50),
    LOAIPHONG VARCHAR(7)
);

CREATE TABLE HOADON (
    MAHD VARCHAR(10) NOT NULL PRIMARY KEY,
    TENHD VARCHAR(200),
    TONGTIEN DECIMAL NOT NULL
);

CREATE TABLE THUE (
    MAHD VARCHAR(10) NOT NULL PRIMARY KEY,
    MAPHONG VARCHAR(10),
    NGAYTHUE DATE,
    NGAYTRA DATE,
    GIATHUE DECIMAL NOT NULL
);

alter table hoadon
add column MAKH VARCHAR(10);

select *
from hoadon;

# alter table phong
# drop column MAKH;

alter table khachhang
modify CCCD VARCHAR(20);

update khachhang
set TENKH = 'Nguyen B'
where MAKH = 'KH02';

-- Change database

-- Add new khach hang
insert into khachhang (MAKH, TENKH, SDT, CCCD)
values ('KH01', 'Nguyen A', '0121212121', '1212121212');


-- Add new hoa don
insert into hoadon (MAHD, TENHD, TONGTIEN, hoadon.MAKH)
values ('HD01', 'Hoa don 1', 50000, @maKH);


-- Get all khach hang
select kh.MAKH, kh.TENKH
from khachhang kh;


-- Get all danh sach phong
select *
from phong;


-- Delete phong by id
delete from phong
where MAPHONG = @maPhong;


-- Get phong by id
select *
from phong
where MAPHONG = @maPhong
limit 1;


-- Update phong
update phong
set MAPHONG = @maPhong, TENPHONG = @tenPhong, TINHTRANG = @tinhTrang, LOAIPHONG = @loaiPhong
where MAPHONG = @maPhong;


-- Get all khach hang and tong tien thue
select kh.MAKH, kh.TENKH, hd.TONGTIEN
from thue t
join hoadon hd on t.MAHD = hd.MAHD
join khachhang kh on hd.MAKH = kh.MAKH
limit @limit
order by hd.TONGTIEN desc;

select *
from phong;

insert into phong (MAPHONG, TENPHONG, TINHTRANG, LOAIPHONG)
values ('P03', 'Phong 03', 'Con trong', 'Single'),
       ('P04', 'Phong 04', 'Da thue', 'Double');

SELECT kh.MAKH, kh.TENKH, SUM(hd.TONGTIEN)
from khachhang kh
left join hoadon hd on kh.MAKH = hd.MAKH
left join thue t on hd.MAHD = t.MAHD
group by kh.MAKH
order by SUM(hd.TONGTIEN) desc
limit 10;