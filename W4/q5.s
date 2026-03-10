main:
main_prologue:
	begin				# open stack frame
	push	$ra

main_body:
	# sum4(11, 13, 17, 19);
		
	# load arguments into $a registers to prep for function call
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19

	# jump to function and link current location
	jal	sum4

	# result = $t0
	move	$t0, $v0
	# printf("%d", sum4(11, 13, 17, 19));
	li	$v0, 1
	move	$a0, $t0
	syscall

	# printf("\n");
	li	$v0, 11
	li	$a0, '\n'
	syscall

main_epilogue:

	pop	$ra

	li	$v0, 0			# return 0;
	jr	$ra


sum4:
	# li	$a0, a
	# li	$a1, b
	# li	$a2, c
	# li	$a3, d
sum4_prologue:
	begin 	
	push	$ra
	push	$s0
	push	$s1
	push	$s2

	move	$s1, $a2
	move	$s2, $a3

sum4_body:
	# move	$a0, $a0
	# move	$a1, $a1
	jal	sum2

	# res1 = $t0
	move	$s0, $v0

	move	$a0, $s1
	move	$a1, $s2
	jal	sum2

	# res2 = $t1
	move	$t1, $v0

	move	$a0, $s0
	move	$a1, $t1
	jal	sum2
	# move	$v0, $v0

sum4_epilogue:
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra
	end

	jr	$ra

sum2:
sum2_prologue:
sum2_body:
	add	$v0, $a0, $a1

sum2_epilogue:
	jr	$ra

