	.file	"new.cpp"
	.section	.text._ZnwjPv,"axG",@progbits,_ZnwjPv,comdat
	.weak	_ZnwjPv
	.type	_ZnwjPv, @function
_ZnwjPv:
.LFB269:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE269:
	.size	_ZnwjPv, .-_ZnwjPv
	.section	.text._ZdlPvS_,"axG",@progbits,_ZdlPvS_,comdat
	.weak	_ZdlPvS_
	.type	_ZdlPvS_, @function
_ZdlPvS_:
.LFB271:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE271:
	.size	_ZdlPvS_, .-_ZdlPvS_
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
.LC0:
	.string	" Test1 alive "
	.section	.text._ZN5Test1C2Ev,"axG",@progbits,_ZN5Test1C5Ev,comdat
	.align 2
	.weak	_ZN5Test1C2Ev
	.type	_ZN5Test1C2Ev, @function
_ZN5Test1C2Ev:
.LFB974:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE974:
	.size	_ZN5Test1C2Ev, .-_ZN5Test1C2Ev
	.weak	_ZN5Test1C1Ev
	.set	_ZN5Test1C1Ev,_ZN5Test1C2Ev
	.section	.text._ZN5Test2C2ESs,"axG",@progbits,_ZN5Test2C5ESs,comdat
	.align 2
	.weak	_ZN5Test2C2ESs
	.type	_ZN5Test2C2ESs, @function
_ZN5Test2C2ESs:
.LFB977:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, 4(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE977:
	.size	_ZN5Test2C2ESs, .-_ZN5Test2C2ESs
	.weak	_ZN5Test2C1ESs
	.set	_ZN5Test2C1ESs,_ZN5Test2C2ESs
	.section	.rodata
.LC1:
	.string	"memory ready"
.LC2:
	.string	"test2"
	.text
	.globl	main
	.type	main, @function
main:
.LFB979:
	.cfi_startproc
	.cfi_personality 0,__gxx_personality_v0
	.cfi_lsda 0,.LLSDA979
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	$1, (%esp)
	call	malloc
	movl	%eax, 28(%esp)
	movl	$.LC1, 4(%esp)
	movl	$_ZSt4cout, (%esp)
.LEHB0:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
.LEHE0:
	movl	28(%esp), %esi
	movl	%esi, 4(%esp)
	movl	$1, (%esp)
	call	_ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	.L7
	movl	%ebx, (%esp)
.LEHB1:
	call	_ZN5Test1C1Ev
.LEHE1:
	movl	%ebx, %eax
	jmp	.L8
.L7:
	movl	%ebx, %eax
.L8:
	movl	%eax, 32(%esp)
	movl	$1, (%esp)
	call	malloc
	movl	%eax, 36(%esp)
	movl	36(%esp), %esi
	movl	%esi, 4(%esp)
	movl	$1, (%esp)
	call	_ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	.L9
	movl	%ebx, (%esp)
.LEHB2:
	call	_ZN5Test1C1Ev
.LEHE2:
	movl	%ebx, %eax
	jmp	.L10
.L9:
	movl	%ebx, %eax
.L10:
	movl	%eax, 36(%esp)
	movl	$1, (%esp)
	call	malloc
	movl	%eax, 40(%esp)
	movl	$.LC1, 4(%esp)
	movl	$_ZSt4cout, (%esp)
.LEHB3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
.LEHE3:
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	_ZNSaIcEC1Ev
	leal	23(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC2, 4(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
.LEHB4:
	call	_ZNSsC1EPKcRKSaIcE
.LEHE4:
	leal	24(%esp), %edi
	movl	40(%esp), %esi
	movl	%esi, 4(%esp)
	movl	$1, (%esp)
	call	_ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	.L11
	movl	%edi, 4(%esp)
	movl	%ebx, (%esp)
.LEHB5:
	call	_ZN5Test2C1ESs
.LEHE5:
	movl	%ebx, %eax
	jmp	.L12
.L11:
	movl	%ebx, %eax
.L12:
	movl	%eax, 44(%esp)
	leal	24(%esp), %eax
	movl	%eax, (%esp)
.LEHB6:
	call	_ZNSsD1Ev
.LEHE6:
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	_ZNSaIcED1Ev
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	_ZdlPv
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	_ZdlPv
	movl	$0, %eax
	jmp	.L22
.L18:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
.LEHB7:
	call	_Unwind_Resume
.L19:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
	call	_Unwind_Resume
.LEHE7:
.L21:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	_ZdlPvS_
	movl	%edi, %ebx
	leal	24(%esp), %eax
	movl	%eax, (%esp)
	call	_ZNSsD1Ev
	jmp	.L17
.L20:
	movl	%eax, %ebx
.L17:
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	_ZNSaIcED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
.LEHB8:
	call	_Unwind_Resume
.LEHE8:
.L22:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE979:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA979:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE979-.LLSDACSB979
.LLSDACSB979:
	.uleb128 .LEHB0-.LFB979
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB979
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L18-.LFB979
	.uleb128 0
	.uleb128 .LEHB2-.LFB979
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L19-.LFB979
	.uleb128 0
	.uleb128 .LEHB3-.LFB979
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB979
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L20-.LFB979
	.uleb128 0
	.uleb128 .LEHB5-.LFB979
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L21-.LFB979
	.uleb128 0
	.uleb128 .LEHB6-.LFB979
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L20-.LFB979
	.uleb128 0
	.uleb128 .LEHB7-.LFB979
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB8-.LFB979
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSE979:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1020:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	.L23
	cmpl	$65535, 12(%ebp)
	jne	.L23
	movl	$_ZStL8__ioinit, (%esp)
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit, 4(%esp)
	movl	$_ZNSt8ios_base4InitD1Ev, (%esp)
	call	__cxa_atexit
.L23:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1020:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1021:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1021:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.section	.rodata
	.align 4
	.type	_ZZL18__gthread_active_pvE20__gthread_active_ptr, @object
	.size	_ZZL18__gthread_active_pvE20__gthread_active_ptr, 4
_ZZL18__gthread_active_pvE20__gthread_active_ptr:
	.long	_ZL28__gthrw___pthread_key_createPjPFvPvE
	.weakref	_ZL28__gthrw___pthread_key_createPjPFvPvE,__pthread_key_create
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.1-2ubuntu1~12.04) 4.8.1"
	.section	.note.GNU-stack,"",@progbits
