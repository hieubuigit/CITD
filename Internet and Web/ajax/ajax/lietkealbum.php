<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
          <script src="jquery.js"></script>
    <script>
    $(document).ready(function(){
        $(".classtenalbum").change(function(){
            var maalbum=$(this).val();  //lấy nội dung trong text field 
            $.get("lietkebaihat_ajax.php?ma="+maalbum,function(data,status){
                if(status=='success')
                    $(".ketqua").html(data); 
                
                    $(".classdelete").click(function(){
                        var mabh=$(this).attr('mabaihat');
                        $(this).parent().parent().remove();
                        //----
                        $.get("deletebaihat_ajax.php?ma="+mabh,function(data,status){
                        
                        });
                        //---
                        
                    });
            });
            
        }); 
    });   
    </script>
    </head>
    <body>
         <?php
            include "../database/connect.php";
            $sql = "SELECT * FROM album";
            $results = $connect->query($sql);
            echo "Tên album <select class='classtenalbum'>";
            while($rows = $results->fetch_row())
            {
                echo "<option value='$rows[0]'>$rows[1]</option>";
            }
            echo "</select>";    
            $connect->close();//Đóng kết nối CSDL.
            echo "<div class='ketqua'></div>";
        ?>
    </body>
    
</html>
