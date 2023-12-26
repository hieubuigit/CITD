<?php

include './config.php';

class DB
{
    public static $connection = NULL;
    public function __construct()
    {
        $connection = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);

        // Check connection
        if ($connection->connect_error) {
            die("Connection failed: " . $connection->connect_error);
        }
        echo "Connected successfully";
    }

    public function select($sql)
    {
        $result = self::$connection->query($sql) or die(self::$connection->error); //hien thi chi tiet loi
        $items = array();
        //echo "number of rows: " . $result->num_rows;    //hien thong tin so cua cot
        while ($item = $result->fetch_assoc()) { //Lay mot mang ket qua tra ve sau khi thuc hien cau truy van
            $items[] = $item;
        }
        return $items;
    }

    public function selectNonQuery($sql)
    {
        $result = self::$connection->query($sql) or die(self::$connection->error); //hien thi chi tiet loi
        if ($result) {
            return true;
        } else {
            return false;
        }
    }
}
