#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import serial
comport = serial.Serial('COM5', 9600) 
print ('Serial Iniciada...')
 
import mysql.connector
cnx = mysql.connector.connect(user='root', password='', host='localhost', database='ufrr_dcc_ise2018')
cursor = cnx.cursor()
add_sinais = ("INSERT INTO main_data(data_e_hora, sensor_de_luz, sensor_de_presenca, constante_sensor_de_luz) VALUES (now(), %s, %s, %s)")

counter = 10
while(counter > 0):
    serialValue = comport.readline()
    counter -= 1
    
while (False):
    serialValue = comport.readline()
    valuesToDB = str(serialValue).split(" ")
    del(valuesToDB[0])
    del(valuesToDB[2])
    del(valuesToDB[3])
    del(valuesToDB[3])
    print (valuesToDB)
    cursor.execute(add_sinais, valuesToDB)
    cnx.commit()
 
cursor.close()
cnx.close()
comport.close()
