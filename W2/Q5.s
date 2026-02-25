# Squares a number, unless its square is too big for a 32-bit integer.
# If it is too big, prints an error message instead.

# CONSTANT
SQUARE_MAX = 46340

main:
	# $t0 = x, $t1 = y
						# Note this is the same as our previous program
        li      $v0, 4                  	# printf("Enter a number: ");
        la      $a0, prompt_str
        syscall                         	# syscall 4: print_string

	li	$v0, 5				# scanf("%d", &x);
	syscall					# syscall 5: scan int
	move	$t0, $v0			# scanned value into $v0 --> $t0 = x

if_condition:
	ble	$t0, SQUARE_MAX, else_body	# if (x <= SQUARE_MAX) goto else_body;

if_body:
	li	$v0, 4				# printf("square too big for 32 bits\n");
	la	$a0, too_big_str		# syscall 4: print_string
	syscall

	b	if_end				# goto if_end;

else_body:
	mul	$t1, $t0, $t0			# y = x * x;
	
	li	$v0, 1				# printf("%d", y);
	move	$a0, $t1
	syscall
    
	li	$v0, 11				# printf("\n");
	li	$a0, '\n'			# syscall 11: print char
	syscall

if_end:

epilogue:
	li	$v0, 0				# return 0;
	jr	$ra

.data

prompt_str:
        .asciiz "Enter a number: "

too_big_str:
	.ascii "square too big for 32 bits\n\0"