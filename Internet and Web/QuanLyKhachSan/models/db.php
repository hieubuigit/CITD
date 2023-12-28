<?php

include "config.php";

class DB
{
    public static $connection = NULL;
    public function __construct()
    {
        self::$connection = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);
        if (self::$connection->connect_error) {
            die("Connection failed: " . self::$connection->connect_error);
        }
    }

    public function select($sql)
    {
        $result = self::$connection->query($sql) or die(self::$connection->error);
        $items = array();
        while ($item = $result->fetch_assoc()) {
            $items[] = $item;
        }
        return $items;
    }

    public function selectNonQuery($sql)
    {
        $result = self::$connection->query($sql) or die(self::$connection->error);
        if ($result) {
            return true;
        } else {
            return false;
        }
    }
}
