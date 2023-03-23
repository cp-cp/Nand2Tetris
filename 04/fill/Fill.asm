// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


(CHECK)
@16384
D=A//获取屏幕下限
@0
M=D//把R0作为循环起点，并作为循环变量的初始值，随过程递增

@24575
D=A//获取屏幕上限
@1
M=D//把R1作为循环终点

@24576
D=M
@CLEAR
D;JEQ//直接判断,如果为0那么就去清空，如果为1则继续执行。


(FILL)
@1
D=M-D//判断是否超过M
@CHECK
D;JLT
@0
D=M//返还D的值
A=M
M=-1
D=D+1
@0
M=D//用来存D的目前值
@FILL
0;JEQ

(CLEAR)
@1
D=M-D//判断是否超过M
@CHECK
D;JLT
@0
D=M//返还D的值
A=D
M=0
D=D+1
@0
M=D//用来存D的目前值
@CLEAR
0;JEQ
