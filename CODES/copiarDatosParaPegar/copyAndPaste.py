"""
  Copyright (c) 2023 [Yoel Castillo]
 
  Este código ha sido escrito por mí, Yoel Castillo, para que lo uses de manera libre.
  He dedicado horas y horas a su creación, así que por favor, aprovéchalo.
  No se requiere atribución ni se impone ninguna restricción. Disfrútalo y úsalo bien.
"""

import serial
import pyautogui
import pyperclip

# INICIALIZA LA COMUNICACION POR SERIE CON ARDUINO
arduino = serial.Serial('COM4', 9600)

while True:
    try:
        # LEE LO QUE DICE ARDUINO
        data = ser.readline().decode().strip()

        # COPIA LA LECTURA AL PORTAPAPELES
        pyperclip.copy(data)

        # PEGA LA LECTURA
        pyautogui.click(x=1000, y=973)  # USA EL SOFTWARE QUE TE DEJE PARA SABER LA COORDENADAS
        pyautogui.hotkey('ctrl', 'v')  # PEGA
        pyautogui.press('enter')  # ENTER

    except KeyboardInterrupt:
        break

ser.close()
