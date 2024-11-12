.model small
.stack 100h
.data
    a dw 1200h      ; First input
    b dw 1600h      ; Second input

.code
    MOV AX, @data   ; Load the data segment
    MOV DS, AX      ; Initialize DS
    MOV SI, a       ; Load address of a
    MOV AX, [SI]    ; Load value of a into AX
    MOV SI, b       ; Load address of b
    MOV BX, [SI]    ; Load value of b into BX
   SUB AX, BX      ; AX = a + b

    ; Prepare for decimal conversion
    MOV CX, 0       ; Initialize digit counter
    MOV BX, 10      ; Set divisor to 10

L:  
    MOV DX, 0       ; Clear DX before division
    DIV BX           ; Divide AX by 10
    PUSH DX          ; Push remainder (next digit) onto stack
    INC CX           ; Increment digit count
    CMP AX, 0       ; Check if AX is zero
    JNZ L           ; Repeat if not zero

D:  
    POP DX          ; Pop the last digit from the stack
    ADD DL, '0'     ; Convert to ASCII (add '0' to the digit)
    MOV AH, 02h     ; Prepare to print character
    INT 21h         ; Print the character in DL
    DEC CX          ; Decrement digit count
    JNZ D           ; Repeat until all digits are printed

    MOV AX, 4C00h   ; Terminate program
    INT 21h
END