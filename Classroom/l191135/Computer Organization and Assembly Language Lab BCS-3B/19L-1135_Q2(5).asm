[org 0x100]

	jmp start

;---------------------------------------
start:	xor ax, ax
	push es
	mov es, ax
	mov ax, [es:0*4]	; Saving interrupt's offset
	push ax
	mov ax, [es:0*4+2]
	push ax
	mov word [es:0*4], int0	; Overwriting interrupt's offset
	mov [es:0*4+2], cs

Time:	mov ah, 0
	int 0x16
	cmp al, 27		; Press Lshift + e to exit
	je lev
	int 0x00		; calling interrupt
	jmp Time

lev:	pop word [es:0*4+2]	; Restoring interrupt's offset
	pop word [es:0*4]
	pop es

end:	mov ax, 0x4c00		; termination of program
	int 21h
;---------------------------------------
int0:	pusha
	push es

	push 358		; position where time is to be displayed
				; on the screen
	
lt:	mov ah,00	
	mov al,03h		; clear the screen
	int 10h				
	mov ah, 0
	int 0x16
	cmp al, 't'
	je TimeFormat
	cmp al, 27
	je exit0
	jmp lt	
	
exit0:	pop ax
	pop es
	popa
	iret
;---------------------------------------
TimeFormat:
	push bp
	mov bp, sp
	pusha
	push es

	push 0xB800
        pop es
	mov di, [bp+2]
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
	popa
	pop bp
	jmp lt
;---------------------------------------