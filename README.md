# Arduino 学习记录

这是我学习 Arduino 时写的程序（sketch），每个文件夹是一个程序。文件夹名按日期命名，例如 `sketch_nov3a` 是 11 月 3 日的第一个程序。

| 文件夹 | 内容 | 硬件 |
|---|---|---|
| sketch_oct20c | 按钮切换三组灯（3、4、5 号引脚），每按一次切换一组，蜂鸣器（6 号引脚）按次数发出不同音调，按三次后回到开始 | 按钮（2 号）、LED、蜂鸣器 |
| sketch_nov3a | 读取 2 号引脚的输入，控制 3 号引脚的输出，两者状态相反 | 按钮或开关、LED |
| sketch_nov3b | 温度报警器：温度超过 30°C 时红灯闪烁、蜂鸣器响、风扇开启；正常时绿灯亮；按钮可以关闭报警；LCD 显示温度 | DS18B20 温度传感器（8 号）、LCD1602（I2C）、按钮（7 号）、风扇（6 号） |
| sketch_nov8a | 读取 RFID 卡的卡号（UID），通过串口输出 | MFRC522 读卡器 |

## 需要的库

这些程序用到的库没有放在仓库里，需要在 Arduino IDE 的库管理器中安装，或者放到你自己的 libraries 文件夹中：

- **OneWire**、**DallasTemperature**：温度传感器（`sketch_nov3b`）
- **LiquidCrystal_I2C**：LCD 显示（`sketch_nov3b`）
- **MFRC522**：RFID 读卡器（`sketch_nov8a`）

编译产生的 `build/`、`.hex` 等文件不纳入仓库，见 [.gitignore](.gitignore)。
