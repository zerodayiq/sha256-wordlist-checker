# SHA-256 Wordlist Checker

A simple C++ tool that checks a SHA-256 hash against a wordlist file to find a matching plaintext password.

## ⚠️ Disclaimer

This tool is for **educational purposes only**.
Do not use it on systems you do not own or have permission to test.

---

## 📌 How It Works

- The program takes a SHA-256 hash as input
- It reads words from `wordlist.txt`
- Each word is hashed using SHA-256
- The result is compared with the target hash
- If a match is found, the original word is displayed

---

## 🛠 Requirements

- C++ compiler (g++)
- OpenSSL library

Install OpenSSL on Debian/Ubuntu:
```bash
sudo apt install libssl-dev

Install OpenSSL on Arch Linux

sudo pacman -S openssl

## Demo

![Demo](images/demo.png)
