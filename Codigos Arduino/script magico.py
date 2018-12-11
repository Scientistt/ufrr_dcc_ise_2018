#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import serial
comport = serial.Serial('COM5', 9600) 
print ('Serial Iniciada...')
 
import mysql.connector
cnx = mysql.connector.connect(user='root', password='', host='localhost', database='ufrr_dcc_ise2018')
cursor = cnx.cursor()
add_sinais = ("INSERT INTO main_data(data_e_hora, sensor_de_luz, constante_sensor_de_luz, sensor_de_presenca, sensor_de_vibracao, constante_sensor_de_vibracao, sensor_de_temperatura, contador_de_tempo) VALUES (now(), %s, %s, %s, %s, %s, %s, %s)")
get_sinais = ("SELECT * FROM acoes");
counter = 10
while(counter > 0):
    serialValue = comport.readline()
    counter -= 1
    
while (True):
    serialValue = comport.readline()
    valuesToDB = str(serialValue).split(" ")
    del(valuesToDB[0])
    del(valuesToDB[7])
    print(valuesToDB)
    cursor.execute(add_sinais, valuesToDB)
    cnx.commit()

    cursor.execute(get_sinais)

    for i in cursor:
        print("Enviando Comando para o Arduino = " + str(i[1]))
        comport.write(int(i[1]));
        cursor.execute("DELETE FROM acoes WHERE id = '" + str(i[0]) + "'");
        cnx.commit()
 
cursor.close()
cnx.close()
comport.close()
