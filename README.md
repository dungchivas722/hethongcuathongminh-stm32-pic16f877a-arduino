# hethongcuathongminh-stm32-pic16f877a-arduino
## VIdeo minh họa :

[Bấm vào đây](https://www.youtube.com/watch?v=pdlXQQF5UMQ)
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
12. cảm biến tiệm cận 1 chân tín hiệu 0 hoặc 1

## Phần mềm sử dụng : 

- MPLAB với xc8
- Keli uVision5 với STM32CubeMX
- Arduino IDE

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
## Các chân cắm trên board :
### Pic16f877a :
+ RC6,RC7 ứng với UART rx,tx lora 1
+ RA0,RA1 ứng với vrx,vry joystick, RB1 ứng với input
+  LCD : RDO - RS, RD2- E , RD4->RD7 - D4->D7
### Arduino :
+ 2,3 ứng với Uart vân tay rx,tx
+ 10,11 ứng vowus Uart stm32 rx,tx
### Stm32 :
+ PD2,PC12 ứng với uart lora 2 rx tx
+  PA0,PA1 ứng với uart arduino rx tx
+  PC5 ứng với output cảm biến tiệm cận
+  PE14 ứng với output relay
+  PE13 ( bỏ )
+  PE2, PE3 ứng với 1 module a4988 dir, step ( prj này chỉ dùng 1 cái )
+  PC0, P1 ứng với 1 module a4988 dir, step
