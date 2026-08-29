from os import system 
import sys
import os

out = system("make re -C ../.; echo ----------------; echo")

if out != 0:
	print("Failed to compile woody")
	sys.exit(1)

def	osystem(command):
	out = system(command)
	return os.waitstatus_to_exitcode(out)

def reality_check(check_me, expected, succes_message="😎 Test Passed", 
				  fail_message="😱 Test failed"):
	if check_me == expected:
		print(succes_message)
	else:
		print(fail_message)

def	test_check_x86_64_bit(file, expected):
	out = osystem(f"../woody_woodpacker resources/{file}")
	reality_check(out, expected, "😎 Test Passed : x86-64 file check", f"😱 Test failed: x86-64 file check: file {file}, expected {expected} got {out}")

def	test_args(arg="resources/sample", expected=0):
	expected = 1
	out = osystem(f"../woody_woodpacker ")
	reality_check(out, expected, "😎 Test Passed : giving no arguments", f"😱 Test failed: giving no arguments: , expected {expected} got {out}")
	out = osystem(f"../woody_woodpacker arg1 arg2")
	reality_check(out, expected, "😎 Test Passed : giving 2 args", f"😱 Test failed: giving 2 args: , expected {expected} got {out}")
	expected = 0
	out = osystem(f"../woody_woodpacker resources/s64")
	reality_check(out, expected, "😎 Test Passed : accepting elf 64 bits files only", f"😱 Test failed: accepting elf 64 bits files only: , expected {expected} got {out}")


	


test_check_x86_64_bit("s64", 0)
test_check_x86_64_bit("sarm", 1)
test_args()


