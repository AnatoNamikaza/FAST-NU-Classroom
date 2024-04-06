[org 0x100]

	jmp start

oldisr: dw 0
;---------------------------------------
start:	mov ah,00    
	mov al,03h        ; clear the screen
	int 10h

	xor ax, ax
	mov es, ax
	mov ax, [es:0*4]	; Saving interrupt's offset
	mov [oldisr], ax
	mov ax, [es:0*4+2]
	mov [oldisr], ax
	cli	
	mov word [es:0*4], TimeFormat
	mov [es:0*4+2], cs
	sti

end:	mov dx, start
	add dx, 15
	mov cl, 4
	shr dx, cl
	mov ax, 0x3100		; terminate and stay resident
	int 19h; int 21h
;---------------------------------------
TimeFormat:
	push ax
	push es

	push 0xB800
        pop es
	mov di, 318
	mov bx, 16

	xor ax, ax	
	mov al, 4
	out 0x70, al		; Load hours in "al" register
	jmp h1	
h1:	in al, 0x71
	push ax
	xor ax, ax	
	mov al, 2	
	out 0x70, al		; Load minutes in "al" register
	jmp m1	
m1:	in al, 0x71
	push ax
	xor ax, ax	
	mov al, 0	
	out 0x70, al		; Load seconds in "al" register
	jmp s1	
s1:	in al, 0x71
	div bx
	
	mov cx, 3

dis:	mov dh, 0x25
	add dl, 0x30	
	mov [es:di], dx
	sub di, 2
	mov ah, 0x25
	add al, 0x30	
	mov [es:di], ax
	sub di, 2
	sub cx, 1
	cmp cx, 0
	je levfun
	mov al, ":"
	mov [es:di], ax
	mov dx, 0
	pop ax
	div bx
	jmp dis	

levfun:	pop es
	pop ax
	iret
;---------------------------------------