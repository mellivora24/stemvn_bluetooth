STEMVN_BLUETOOTH Library
=======================

Thư viện StemvnBluetooth giúp dễ dàng giao tiếp Bluetooth trên các bo mạch Arduino.

Tính năng:
----------
- Gửi và nhận dữ liệu qua Serial Bluetooth.
- Linh hoạt cài đặt tốc độ baud.

Hướng dẫn sử dụng:
------------------
1. Bao gồm thư viện vào chương trình:
```cpp
#include <stemvn_bluetooth.h>
```
2. Khởi tạo đối tượng và bắt đầu Bluetooth:
```cpp
StemvnBluetooth bluetooth;
bluetooth.begin(9600); // Khởi động với tốc độ 9600 baud
```
3. Gửi và nhận dữ liệu:
```cpp
// Gửi dữ liệu
bluetooth.write("Hello from Arduino!");

// Nhận dữ liệu
String data = bluetooth.read();
if (data != "") {
    Serial.println("Received: " + data);
}
```
4. Liên hệ:
   Nếu bạn có bất kỳ vấn đề hoặc ý tưởng nào, vui lòng liên hệ nhóm STEMVN.
