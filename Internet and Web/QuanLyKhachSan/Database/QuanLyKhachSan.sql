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