
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

$sql = "SELECT * FROM main_data WHERE id = (SELECT MAX(id) FROM main_data)";  //This is where I specify what data to query
$result = mysqli_query($conn, $sql);

$data = array();
while($enr = mysqli_fetch_assoc($result)){
    $a = array(
        $enr['sensor_de_luz'], 
        $enr['constante_sensor_de_luz'],
        $enr['sensor_de_presenca'],
        $enr['sensor_de_vibracao'],
        $enr['constante_sensor_de_vibracao'],
        $enr['data_e_hora'],
        $enr['contador_de_tempo'],
        $enr['sensor_de_temperatura']
    );
    array_push($data, $a);
}

echo json_encode($data);

?>