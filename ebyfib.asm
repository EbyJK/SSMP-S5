.model small
.data

a1 db 00h
b1 db 01h
c1 db 06h
d1 db 06 DUP(?)

.code
mov ax,@data
mov ds,ax
mov si,offset a1
mov al,[si]
mov si,offset b1
mov bl,[si]
mov si,offset c1
mov cx,[si]
mov si,offset d1
L1:	add al,bl
	mov [si],al
	mov al,bl
	mov bl,[si]
	inc si
	loop L1
mov cx,06h
mov si,offset d1
L2:	mov al,[si]
	cmp al,0Ah
	jge AlPHA
	add al,30h
	jmp incre
ALPHA : add al,37h
INCRE:  mov dl,al

mov ah,02h
int 21h
inc si
loop L2
mov ah,4ch
int 21h
END	