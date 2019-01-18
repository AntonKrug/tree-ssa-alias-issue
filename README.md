With a specific steps and optimalizations (-O2 -ftree-loop-vectorize -fpredictive-commoning) the 
compiler terminates with an internal error:

```
internal compiler error: tree check: expected ssa_name, have integer_cst in ptr_deref_may_alias_decl_p, at tree-ssa-alias.c:211
```

Example to execute the script:
```
GCC_TOOLCHAIN_PATH=/opt/riscv-gcc7.2/riscv-unknown-elf-gcc/bin/riscv64-unknown-elf-gcc ./compile.sh
```

The behaviour can be changed depending on how many iterations the loop should be executed. Interestingly if the
structures are nested more the iteration count can be higher before failing.

Can be replicated with the 2018-12 release of Freedom Studio (https://www.sifive.com/boards containing gcc 7.2) and with gcc 8.1 build from https://github.com/gnu-mcu-eclipse/riscv-none-gcc/tree/v8.1.0-2-20181019.

Very quick experiments with crosstool-ng 7.4 and 8.2 can't replicate the issue, nor I couldn't replicate it on x86 gcc (from few arbitrary choosen distributions). 

internal compiler error: tree check: expected ssa_name, have integer_cst in ptr_deref_may_alias_decl_p, at tree-ssa-alias.c:211

```
akrug@barbra-xeon32:~/projects/tree-ssa-alias-issue$ GCC_TOOLCHAIN_PATH=/opt/riscv-gcc7.2/riscv-unknown-elf-gcc/bin/riscv64-unknown-elf-gcc ./compile.sh 

Using LOOP_ITERATIONS 5 should compile without issues:

Using LOOP_ITERATIONS 6 might fail:
tree-ssa-alias-issue.c: In function 'main':
tree-ssa-alias-issue.c:23:5: internal compiler error: tree check: expected ssa_name, have integer_cst in ptr_deref_may_alias_decl_p, at tree-ssa-alias.c:211
 int main(int argc, const char* argv[]) {
     ^~~~

Please submit a full bug report,
with preprocessed source if appropriate.
See <https://gcc.gnu.org/bugs/> for instructions.
```
