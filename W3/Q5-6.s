# CONSTANTS
N_SIZE = 10

.text

main:
# $t0 = i
	li	$t0, 0

scan_loop:
scan_loop_init:					
scan_loop_cond:
	bge	$t0, N_SIZE, scan_loop_end
scan_loop_body:		
	li	$v0, 5
	syscall

	# &array[index] = &array + (index * 4)
	# la	$t1, numbers
	# mul	$t2, $t0, 4
	# add	$t1, $t1, $t2
	# sw	$v0, ($t1)
	mul	$t1, $t0, 4
	sw	$t0, numbers($t1)
	
scan_loop_incr:
	addi	$t0, 1

	b 	scan_loop_cond
scan_loop_end:	

print_loop:

print_loop_init:
	li	$t0, 0			
	
print_loop_cond:
	bge	$t0, N_SIZE, print_loop_end

print_loop_body:

	la	$t1, numbers
	mul	$t2, $t0, 4
	add	$t1, $t1, $t2
	lw	$a0, ($t1)

	li	$v0, 1
	syscall
	
print_loop_incr:
	addi	$t0, 1

	b	print_loop_cond
	
print_loop_end:

end:
	jr	$ra				# return


.data

numbers:	.word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0