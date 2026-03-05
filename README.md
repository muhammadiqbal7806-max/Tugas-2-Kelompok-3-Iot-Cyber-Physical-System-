## Smart Factory Monitoring System (IoT)

## Deskripsi Proyek
Proyek ini merupakan sistem monitoring suhu berbasis Internet of Things (IoT) yang digunakan untuk memantau kondisi suhu mesin pada lingkungan industri secara real-time. Sistem ini menggunakan sensor suhu untuk membaca kondisi lingkungan dan mengirimkan data tersebut ke platform IoT sehingga dapat dipantau oleh pengguna melalui dashboard.

Sistem menggunakan Arduino Uno sebagai node sensor dan ESP32 sebagai gateway IoT. Komunikasi antara Arduino dan ESP32 menggunakan protokol UART, sedangkan pengiriman data ke platform IoT menggunakan protokol MQTT.

Selain melakukan monitoring suhu, sistem ini juga menyediakan fitur kontrol LED sebagai indikator peringatan yang dapat dikendalikan melalui dashboard.

## Alur Kerja Sistem
Alur kerja sistem pada proyek ini adalah sebagai berikut:

1. Sensor DHT11 membaca data suhu dari lingkungan.
2. Arduino Uno menerima dan memproses data suhu dari sensor.
3. Arduino mengirimkan data suhu ke ESP32 menggunakan komunikasi UART.
4. ESP32 menerima data suhu dari Arduino.
5. ESP32 menampilkan data suhu pada LCD menggunakan komunikasi I2C.
6. ESP32 mengirimkan data suhu ke platform IoT menggunakan protokol MQTT.
7. Pengguna dapat memantau data suhu melalui dashboard.
8. Pengguna dapat mengirimkan perintah untuk menyalakan atau mematikan LED.
9. ESP32 menerima perintah dari dashboard dan mengontrol LED sebagai indikator.

## Komponen Perangkat Keras

- Arduino Uno
- ESP32
- Sensor DHT11
- LCD I2C
- LED
- Resistor 220Ω
- Baterai 9V
- Breadboard
- Kabel jumper

## Konfigurasi Pin

### Sensor DHT11 ke Arduino Uno


| VCC to 5V |
| GND to GND |
| DATA to D2 |

### Komunikasi UART Arduino ke ESP32

| TX (Pin 1) to RX2 (GPIO16) |
| RX (Pin 0) to TX2 (GPIO17) |
| GND to GND |

### LCD I2C ke ESP32

| VCC to 5V |
| GND to GND |
| SDA to GPIO21 |
| SCL to GPIO22 |

### LED ke ESP32

| Anoda to GPIO4 |
| Katoda to GND melalui resistor 220Ω |


