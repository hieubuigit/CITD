<?php
    include "../database/connect.php";
    $macasi = $_GET['macs'];
    $sql = "SELECT * FROM album where MaCaSi='$macasi'";
    $results = $connect->query($sql);
    echo "<table border='1'>";
    echo "<tr><th>Mã album</th><th>Tên album</th></tr>";
    while($rows = $results->fetch_row())
    {
        echo "<tr><td>$rows[0]</td><td>$rows[1]</td>";
    }
    echo "</table>"; 
?>