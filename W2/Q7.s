
main:
	# $t0 = x
	li	$t0, 24			# int x = 24;

loop:
loop_con:
	bge	$t0, 42, loop_end	# if (x >= 42) goto loop_end;

loop_body:
	li	$v0, 1			# printf("%d", y);
	move	$a0, $t0
	syscall

	li	$v0, 11			# printf("\n");
	li	$a0, '\n'
	syscall

loop_incr:
	add	$t0, 3			# x += 3;
	# add	$t0, $t0, 3

	b	loop_con		# goto loop_con;

loop_end:

epilogue:
	li	$v0, 0			# return 0;
	jr	$ra
