# Rot Cipher

>Rot Ciphers' encryption and decryption algorithm written in C. 

Compile:

```powershell
gcc rotcipher.c -o rot
```
---
Ask For Help:
```powershell
rot -h
```
Output:
```
Usage: rot -s <string> -m (enc|dec) -r <int>     

Options:-
    -s  set data string     
    -m  set mode to encrypt or decrypt the message     
    -r  set rotate value [-1 to print all possibilities]
```
---
## Encryption:
```powershell
rot -s "Hack Teh World!" -m enc -r 10
```
Output:
```
Rkmu Dor Gybvn!
```
---
## Decryption:
```powershell
rot -s "Rkmu Dor Gybvn!" -m dec -r 10 
```
Output:
```
Hack Teh World!
```
___