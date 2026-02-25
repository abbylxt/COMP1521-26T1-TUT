# Prints the square of a number

# First look at the variables that are used in your code
# are there any strings?? global var
# each line of assembly can only be one instruction

main:
	# define the registers you are using at the start of each section
	# $t0 = x
	# $t1 = y

        li      $v0, 4                  # printf("Enter a number: ");
        la      $a0, prompt_str
        syscall                         # syscall 4: print_string

	li	$v0, 5			# scanf("%d", &x);
	syscall				# syscall 5: scan int
	move	$t0, $v0		# scanned value into $v0 --> $t0 = x

    	mul	$t1, $t0, $t0		# y = x * x;
	
	li	$v0, 1			# printf("%d", y);
	move	$a0, $t1
	syscall
    
	li	$v0, 11			# printf("\n");
	li	$a0, '\n'
	syscall

epilogue:
	li	$v0, 0			# return 0;
	jr	$ra

.data

prompt_str:
	.asciiz	"Enter a number: "

# alternatively
# prompt_number:
# 	.ascii "Enter a number: \0"