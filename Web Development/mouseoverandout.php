<!DOCTYPE html>
<html>
<body>
<div style="margin-top:70px;" >
<center>

<img id="image1" src="C:\Users\Rashi\Desktop\Pal\AWD\bg1.jpg"
width="500px;" id="image1" onmouseover = "mouseOver()" onmouseout = "mouseOut()">

</center>
</div>
</body>
<script>
function mouseOver()
{
var e=document.getElementById("image1");
e.src="bg2.jpg"
}
function mouseOut()
{
var e=document.getElementById("image1");
e.src="bg1.jpg"
}
</script>
</html>
