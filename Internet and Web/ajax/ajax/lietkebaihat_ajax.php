<?php
    include "../database/connect.php";
    $maalbum = $_GET['ma'];
    $sql = "SELECT * FROM baihat where MaAlBum='$maalbum'";
    $results = $connect->query($sql);
    echo "<table border='1'>";
    echo "<tr><th>Mã album</th><th>Tên album</th><th>Chức năng</th></tr>";
    while($rows = $results->fetch_row())
    {
        echo "<tr><td>$rows[0]</td><td>$rows[1]</td>";
        echo "<td><input type='button' value='delete' class='classdelete' mabaihat='$rows[0]' ></input></td>";
        echo "</tr>";
    }
    echo "</table>"; 
?>