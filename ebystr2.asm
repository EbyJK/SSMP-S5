.model small
.data
msg1 db "hello$"
msg2 db "hi$"
.code
mov ax,@data
mov ds,ax
lea si,msg1
lea di,msg2
mov al,'$'
UP:	cmp al,[si]
	jz next
	inc si
	jmp up

NEXT:	cmp al,[di]
	jz EXIT
	
	mov bl,[di]
	mov [si],bl
	inc si
	inc di
	jmp NEXT
EXIT:	mov [si],al
	lea dx,msg1
	mov ah,09h
	int 21h
	mov ah,4ch
	int 21h
	END
