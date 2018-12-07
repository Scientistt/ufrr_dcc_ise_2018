var myImg = document.getElementById("lampada"),
    myBtn = document.getElementsByTagName("button");

myBtn[0].onclick = function () {
    
    "use strict";

    console.log(myImg.src);
    
    if (myImg.src === "http://localhost/ise/images/lampoff.gif") {
        
        console.log("ligou");
        myImg.src = "http://localhost/ise/images/lampon.gif";
        
        myBtn[0].innerHTML = "Desligar Lâmpada";
        
    } else {
    	console.log("desligou");
        myImg.src = "http://localhost/ise/images/lampoff.gif";
        myBtn[0].innerHTML = "Ligar Lâmpada";
    }
};