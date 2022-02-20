# Rot Cipher

>Rot Ciphers' encryption and decryption algorithm written in C. 

Compile:

```powershell
gcc rotcipher.c -o rc
```
---
Ask For Help:
```powershell
rc -h 'or' rc --help
```
Output:
```

Usage: rc.exe <string> --<mode> --<rotval>
|CLI options|:-
        <data> = A plaintext or ciphertext.
        <mode>:
                --encrypt = Encrypts the string
                --decrypt = Decrypts the string
        <rotval>:
                --rot<int> = Rotates according to given value.|<int> should be between 1-25|
                --allpos = prints all possibilities by rotating the values between 1-25.
```
---
## Encryption:
```powershell
rc "Hack Teh World!" --encrypt --rot10
```
Output:
```
Rkmu Dor Gybvn!
```
---
## Decryption:
```powershell
vc "Rkmu Dor Gybvn!" --decrypt --rot10 
```
Output:
```
Hack Teh World!
```
___
