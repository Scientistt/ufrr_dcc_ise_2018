
<?php

$servername = "localhost";
$username = "root";
$password = "";
$dbname = "ufrr_dcc_ise2018";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "INSERT INTO acoes(tipo, data_e_hora) VALUES (2, now())";  //This is where I specify what data to query
$result = mysqli_query($conn, $sql);

location
?>