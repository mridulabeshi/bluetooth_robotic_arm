# 🤖 Bluetooth Controlled Robotic Arm (MIT App Inventor)

## 📌 Project Overview

This project is an Android application developed using **MIT App Inventor** to control a robotic arm via Bluetooth communication. The app sends simple character-based commands to an 8051 microcontroller, which controls motors for base movement, arm motion, and gripper operation.

---

## ⚙️ Features

* 📡 Bluetooth connectivity (HC-05 module)
* 🎮 Real-time control using buttons
* 🤖 Control of:

  * Base movement (forward/backward)
  * Arm movement (up/down)
  * Gripper (open/close)
* 🔒 Safety stop functionality
* 📱 Simple and user-friendly interface

---

## 🧩 Components Used

### 📱 Software

* MIT App Inventor

### 🔌 Hardware (for reference)

* 8051 Microcontroller
* HC-05 Bluetooth Module
* Motor Driver (L293D / L298)
* DC Motors (Base, Arm, Gripper)

---

## 📲 App UI Components

### Buttons

* Forward
* Backward
* Stop
* Arm Up
* Arm Down
* Arm Stop
* Open Gripper
* Close Gripper

### Other Components

* ListPicker → Bluetooth device selection
* BluetoothClient → Communication module
* Label → Connection status

---

## 🔌 Bluetooth Connection Logic

### Before Picking Device

```
ListPicker1.BeforePicking
    → set ListPicker1.Elements to BluetoothClient1.AddressesAndNames
```

### After Selecting Device

```
ListPicker1.AfterPicking
    → call BluetoothClient1.Connect(address = ListPicker1.Selection)
```

---

## 🎮 Command Mapping

| Action        | Command Sent |
| ------------- | ------------ |
| Forward       | F            |
| Backward      | B            |
| Stop Base     | S            |
| Arm Up        | U            |
| Arm Down      | D            |
| Arm Stop      | A            |
| Open Gripper  | O            |
| Close Gripper | C            |

---

## 🧠 Button Logic (Core Implementation)

### Example: Forward Button

```
when Btn_Forward.Click
    if BluetoothClient1.IsConnected
        call BluetoothClient1.SendText("F")
```

### Other Buttons

```
Backward → "B"
Stop → "S"
Arm Up → "U"
Arm Down → "D"
Arm Stop → "A"
Open Grip → "O"
Close Grip → "C"
```

---

## 🔄 Optional Enhancements

### ✅ Connection Status Indicator

```
if BluetoothClient1.IsConnected
    set Label.Text = "Connected"
else
    set Label.Text = "Not Connected"
```

### 🎯 Smooth Control (Touch Release Stop)

```
when Btn_Forward.TouchUp
    send "S"
```

---

## 🚀 Working Principle

1. User opens the app
2. Connects to HC-05 via Bluetooth
3. Presses control buttons
4. App sends ASCII characters
5. 8051 microcontroller interprets commands
6. Motors perform corresponding actions

---

## ⚠️ Notes

* Ensure Bluetooth is enabled on the phone
* Pair HC-05 module before connecting
* Default HC-05 password: `1234` or `0000`
* Communication uses UART protocol

---

## 📌 Future Improvements

* Joystick-based control
* Voice control integration
* Speed control using PWM
* Camera integration for live feedback

---

## 👨‍💻 Authors

* Mridula B
* Harini Kamatchi
* Kiran Pradha



