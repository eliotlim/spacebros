.section .text

# _asm (q, r) div(int n, int d): divide two numbers, returning quotient and remainder
# parameters supplied in a0 and a1
# values returned in a0 and a1
# doesn't call any other functions, so no need to store return address register (ra)
# doesn't corrupt any callee-save registers, so no need to use the stack
.global div
div:                            # div procedure: ENTRY POINT
    # a0 : numerator
    # a1 : denominator
    # t0 : loop counter
    # t1 : quotient
    # t2 : remainder
    addi t1, zero, 0            # Initialise quotient and remainder to 0
    addi t2, zero, 0
    addi t0, zero, 31               # Initialise loop counter to 31 (bit-width of operands)
    beq zero, a1, divzero           # Raise ECALL if dividing by zero

divloop:                        # div procedure: loop
    slli t2, t2, 1                  # Shift remainder : R << 1
    srl t3, a0, t0                  # Select the (i)th bit of the numerator:
    andi t3, t3, 1
    or t2, t2, t3                   # Move the LSB of N[i] into R[0] : R[0] := N[i]
    blt t2, a1, divloopiter             # If R < D continue : if R >= D then
    sub t2, t2, a1                      # R := R - D
    addi t3, zero, 1                # Q[i] := 1
    sll t3, t3, t0
    or t1, t1, t3

divloopiter:                    # div procedure: loop iterator
    addi t0, t0, -1                  # Decrement loop counter
    bge t0, zero, divloop            # Loop condition : i >= 0

                                # div procedure: RETURN RESULT
    add a0, zero, t1                # Store quotient into a0
    add a1, zero, t2                # Store remainder into a1
    ret                             # return

divzero:                        # div procedure: handle division by zero
    ecall                           # Division by zero detected, raise exception

# int rem(int n, int d): divide two numbers, returning remainder in a0
# parameters supplied in a0 and a1
# remainder value returned in a0
# calls other functions, so we need to store return address register (ra)
# doesn't corrupt any callee-save registers, so no need to use the stack
.global rem
rem:                            # rem procedure: ENTRY POINT
    addi sp, sp, -32                # Allocate stack space
    sw ra, 0(sp)                    # Store return address on stack
    call div                        # Call division subroutine
    add a0, zero, a1                # Move return value to return register
    lw ra, 0(sp)                    # Load return address from stack
    addi sp, sp, 32                 # Deallocate stack space
    ret                             # rem procedure: RETURN RESULT
