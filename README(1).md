# How to create MBED_CLI 2 PROJECT

## HOW TO INSTALL
Installation GCC_ARM
https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads

Installation Mbed Cli 2
Use this link to install
https://os.mbed.com/docs/mbed-os/v6.12/build-tools/install-or-upgrade.html

<br>

## HOW TO USE
Bisa menggunakan panduan pada https://os.mbed.com/docs/mbed-os/v6.12/build-tools/use.html, namun kekurangannya adalah setiap project akan memiliki besar lebih dari 1GB.

Jika ingin menggunakan shared mbed-os (1 mbed-os untuk seluruh project)
1. Letakkan directory cmd anda pada folder kerja

2. Import program menggunakan ```mbed-tools import mbed-os-example-blinky``` (ini akan membutuhkan waktu yang lama, akan mendownload 1GB file)

3. Keluarkan mbed-os dalam program mbed-os-example-blinky dengan mbed-os-example-blinky.
<br>
    Contoh :
    ```
    mbed-os-example-blinky
    --- mbed-os
    --- others
    ```
    Menjadi :
    ```
    mbed-os
    mbed-os-example-blinky
    --- others
    ```

4. Buat project baru menggunakan perintah ```mbed-tools new -c <NAMA_PROJECT>``` yang akan membuat folder baru berisi project tersebut.

5. Pada CMakeLists.txt pada folder project, ubah :
    ```
    (-) set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")
    (+) set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../mbed-os CACHE INTERNAL "")
    ```
    ```
    (-) add_subdirectory(${MBED_PATH})
    (+) add_subdirectory(${MBED_PATH} ${CMAKE_CURRENT_BINARY_DIR}/mbed-os)
    ```

6. Configure system dengan : ## in terminal
    ```
    mbed-tools configure -m NUCLEO_F446RE -t GCC_ARM --mbed-os-path "../mbed-os" 
    ```

7. Untuk build system : ## in terminal
    ```
    cmake -S . -B cmake_build/NUCLEO_F446RE/develop/GCC_ARM -GNinja
    ninja -C cmake_build/NUCLEO_F446RE/develop/GCC_ARM
    ```

8. Jika hanya perubahan kecil, maka dapat dilakukan dengan ninja saja ## in terminal
    ```
    ninja -C cmake_build/NUCLEO_F446RE/develop/GCC_ARM
    ```
   Dengan menggunakan command ninja maka proses building akan sangat cepat.
   Jika ada perubahan struktur file, penambahan library etc gunakan step 7.

9. Jika ingin debugging : ## in terminal
    ```
    cmake -S . -B cmake_build/NUCLEO_F446RE/develop/GCC_ARM -GNinja -DCMAKE_BUILD_TYPE=<profile>
    ```
    profile dapat berisi "release", "debug" atau "develop"

<br>

## How to Install in Linux using venv :
1. export PATH=$PATH:~/gcc-arm-none-eabi-10-2020-q4-major/bin
2. source ~/mbedvenv/mbedvenv/bin/activate

<br>

## Trik Compile
### Windows 
1. Buat file dengan extension *.bat <br>
    Example : run.bat
2. Masukkan kode yang diiingkan <br>
    Example : run.bat berisi
    ```
    ninja -C cmake_build/NUCLEO_F446RE/develop/GCC_ARM
    ```
3. Save file
4. Untuk menjalankan, tinggal ketik nama file dalam terminal
<br>
    Example : (In Terminal) <br>
    ```
    run.bat
    ```
   Otomatis akan menjalankan semua perintah dalam file batch tersebut
