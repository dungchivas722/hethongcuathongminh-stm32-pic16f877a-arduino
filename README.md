# hethongcuathongminh-stm32-pic16f877a-arduino
[Bấm vào đây](https://www.youtube.com/watch?v=pdlXQQF5UMQ))
## Các module sử dụng:

1. stm32f4 discovery
2. pic16f877a
3. LCD 16x2 GPIO
4. Joystick
5. 2 motor step nema 17
6. 2 module điểu kiển motor a4988
7. 1 đèn 5v
8. 1 relay 4 kênh
9. arduino uno r3
10. moduke cảm biến vân tay c608
11. 2 module lora as32-100

## Phần mềm sử dụng : 

- MPLAB với xc8
- Keli uVision5 với STM32CubeMX

## Chức năng :
### Mở cửa - đóng cửa tự động
#### 8 chức năng :
+ Mở cửa
+ Đóng cửa
+ Mode 1 : On/Off
+ Mode 2 : On/Off
+ Mode 3 : On/Off
+ All Off ( Các mode đều tăt )
+ All On ( các mode đều mở )
+ Chế độ chủ xe ( Để xác nhận xe gia đình đến gần cửa sẽ mở )
#### 3 Mode :
+ Chế độ xác định xe gia đình
+ chế độ bật bảo mật vân tay : bảo mật vân tay gồm 3 chế độ : thêm vân tay, xóa vân tay, xác nhận mở cửa
+ Chế độ đóng cửa tự động : đóng cửa sau 2 s
