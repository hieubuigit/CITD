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
    </head>
    <script src="jquery.js"></script>
    <script>
    $(document).ready(function(){
        $(".tencs").blur(function(){
            var tencasi=$(this).val();  //lấy nội dung trong text field 
            $.post("timcs_ajax_post.php",
            {
                ten:tencasi
            },
            function(data,status){
                if(status=='success')
                    $(".thongbao").html(data); 
            });
            
        }); 
    });   
    </script>
    <body>
        Nhập tên ca si:<input type="text" name="tencasi" class="tencs"></input>
        
        <div class="thongbao"></div>
    </body>
</html>
