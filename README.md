# trial-tubes-magang2
UwU

Komponen kontrol
1. Servo Turret:
    - use 60 kg/cm servo
    - angle
        - dikontrol oleh Joystick
        - menyesuaikan dengan target yang nanti akan diberi
        - e.g. 15deg, 50deg, 90deg

2. Arm
    - use BDC PG45
    - speed
        - dikontrol oleh Joystick
    - degree
        - max nya constant
        - use two limit switch, both for calibration (reset encoder)

3. Gripper
    - use pneumatic
    - use pulse from encoder, will converted to deg
        - open and close at a certain deg

Kontroller
Joystick
1. 

Guys, gw ganti nama folder "tubes-magang-2" ke "src" karena ribet nama repo sama folder sama, ada beberapa hal yang harus kalian lakuin ulang:
1. Delete folder CmakeBuild
2. Configure ulang
3. Cmake ulang
4. Ninja ulang
5. Sekian, terima kasih
-Carlios
