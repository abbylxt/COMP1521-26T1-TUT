
main:
# n = $t0, fac = $t1, i = $t2			# int n;

	li	$v0, 4				# printf("n  = ");
	la	$a0, input_str			# syscall 4: print string
	syscall

	li	$v0, 5				# scanf("%d", &n);
	syscall					# syscall 5: scan int
	move	$t0, $v0

	li	$t1, 1				# int fac = 1;

	li	$t2, 1				# int i = 1;

loop:
	bgt	$t2, $t0, loop_end		# if (i > n) goto loop_end;

	mul	$t1, $t1, $t2			# fac *= i;

	add	$t2, 1				# i++;

	b	loop				# goto loop

loop_end:

	li	$v0, 4				# printf("n! = ");
	la	$a0, printout_str		# # syscall 4: print string
	syscall

	li	$v0, 1				# printf("%d", fac);
	move	$a0, $t1			# syscall 1: print int
	syscall

	li	$v0, 11				# printf("\n");
	li	$a0, '\n'			# syscall 11: print char
	syscall

epilogue:
	li	$v0, 0				# return 0;
	jr	$ra


.data

input_str:
	.asciiz "n  = "

printout_str:
	.asciiz "n! = "