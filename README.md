
# Minitalk

The purpose of this project is to code a small data exchange program
using UNIX signals. 


## How to run

First we need to get the program :
```javascript
git clone https://github.com/DRACULATudor/Minitalk.git && cd Minitalk
```
Second step is running the program, by using the following command :
```javascript
make
```
Third step is running first the server executable, and preparing a new terminal for the client :
```javascript
./server 
```
Now that the server is running, and the new terminal/terminals are open, all there is left to do is running the client with the serever PID (
Process identifier)
```javascript
./client SERVER_PID "STRING TO SEND" || ./client SERVER_PID STRING_TO_SNED
```
 
