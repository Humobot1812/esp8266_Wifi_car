---

# 🚗 ESP8266 WiFi Controlled Car

A simple and efficient **WiFi-controlled robotic car** built using **ESP8266**. This project allows you to control your car wirelessly through a web interface or mobile device over WiFi.

---

## 📌 Features

* 📡 Control car via WiFi (no Bluetooth needed)
* 🌐 Web-based control interface
* ⚡ Real-time response
* 🔧 Simple and lightweight code
* 📱 Works with mobile & laptop browsers

---

## 🛠️ Hardware Required

* ESP8266 (NodeMCU / ESP-12E)
* Motor Driver (L298N / L293D)
* DC Motors (2 or 4)
* Robot Chassis
* Battery (7.4V / 12V recommended)
* Jumper wires

---

## 📂 Project Structure

```
esp8266_Wifi_car/
│── Humobots.ino        # Main Arduino code
│── Image/              # Project images
│── README.md           # Documentation
│── Video               # Project Videos
```

---

## ⚙️ Working Principle

1. ESP8266 creates or connects to a WiFi network.
2. A web server runs on ESP8266.
3. User sends commands (Forward, Backward, Left, Right, Stop).
4. ESP8266 processes commands and controls motors via driver.

---

## 🔌 Pin Configuration (Example)

| ESP8266 Pin | Motor Driver |
| ----------- | ------------ |
| D1          | IN1          |
| D2          | IN2          |
| D3          | IN3          |
| D4          | IN4          |

*(Modify according to your wiring)*

---

## 🚀 How to Run

1. Install Arduino IDE
2. Add ESP8266 board support
3. Open `Humobots.ino`
4. Update WiFi credentials (if needed)
5. Select correct board & port
6. Upload code to ESP8266

---

## 📱 How to Control

1. Connect to ESP8266 WiFi (or same network)
2. Open browser
3. Enter ESP8266 IP address
4. Use buttons to control car

---

## 📸 Project Preview

*(Add your images here from `/Image` folder)*

---

## 🔧 Future Improvements

* Add camera (FPV streaming)
* Integrate obstacle avoidance
* Add autonomous mode
* Mobile app control

---

## 🤝 Contribution

Feel free to fork this repo and improve it!

---

## 📄 License

This project is open-source and free to use.

---

## 👨‍💻 Author

**Abhinav Goel**
Robotics & ROS 2 Enthusiast 🚀

---
