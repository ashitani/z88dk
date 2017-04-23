/* codegen.c */
extern void comment(void);
extern void header(void);
extern void DoLibHeader(void);
extern void trailer(void);
extern void outname(char *sname, char pref);
extern void getmem(SYMBOL *sym);
extern void StoreTOS(char);
extern int getloc(SYMBOL *sym, int off);
extern void putmem(SYMBOL *sym);
extern void putstk(char typeobj);
extern void puttos(void);
extern void put2tos(void);
extern void loadargc(int n);
extern void indirect(LVALUE *lval);
extern void swap(void);
extern void immed(void);
extern void immed2(void);
extern void immedlit(int lab);
extern void lpush(void);
extern void lpush2(void);
extern void zpushde(void);
extern void zpush(void);
extern void dpush(void);
extern void dpush_under(int val_type);
extern void mainpop(void);
extern void zpop(void);
extern void zpopbc(void);
extern void doexx(void);
extern void doexaf(void);
extern void swapstk(void);
extern void sw(char type);
extern void zcallop(void);
extern void zclibcallop(void);
extern char dopref(SYMBOL *sym);
extern void callrts(char *sname);
extern void zret(void);
extern void callstk(int n);
extern void jump0(LVALUE *lval,int label);
extern void jump(int label);
extern void opjump(char *, int);
extern void testjump(LVALUE *,int label);
extern void zerojump(void (*oper)(LVALUE *,int), int label, LVALUE *lval);
extern void defbyte(void);
extern void defstorage(void);
extern void defword(void);
extern void deflong(void);
extern void defmesg(void);
extern void point(void);
extern int modstk(int newsp, int save,int saveaf);
extern void scale(int type, TAG_SYMBOL *tag);
extern void zadd_const(LVALUE *lval, int32_t value);;
extern void zadd(LVALUE *);
extern void zsub(LVALUE *);
extern void mult(LVALUE *);
extern void mult_const(LVALUE *lval, int32_t value);
extern void zdiv(LVALUE *);
extern void zdiv_const(LVALUE *lval, int32_t value);
extern void zmod(LVALUE *);
extern void zmod_const(LVALUE *lval, int32_t value);
extern void zor(LVALUE *);
extern void zor_const(LVALUE *lval, int32_t value);
extern void zxor(LVALUE *);
extern void zand(LVALUE *);
extern void zand_const(LVALUE *lval, int32_t value);
extern void asr(LVALUE *);
extern void asr_const(LVALUE *lval, int32_t value);
extern void asl(LVALUE *);
extern void asl_const(LVALUE *lval, int32_t value);
extern void lneg(LVALUE *);
extern void neg(LVALUE *);
extern void com(LVALUE *);
extern void inc(LVALUE *);
extern void dec(LVALUE *);
extern void zeq(LVALUE *);
extern void eq0(LVALUE *,int label);
extern void zne(LVALUE *);
extern void zlt(LVALUE *);
extern void lt0(LVALUE *,int label);
extern void zle(LVALUE *);
extern void le0(LVALUE *,int label);
extern void zgt(LVALUE *);
extern void gt0(LVALUE *,int label);
extern void zge(LVALUE *);
extern void ge0(LVALUE *,int label);
extern void convUint2long(void);
extern void convSint2long(void);
extern void convSint2doub(void);
extern void convUint2doub(void);
extern void convSlong2doub(void);
extern void convUlong2doub(void);
extern void convdoub2int(void);
extern void DoubSwap(void);
extern void vlongconst(uint32_t val);
extern void vlongconst_noalt(uint32_t val);
extern void vconst(int32_t val);
extern void const2(int32_t val);
extern void constbc(int32_t val);
extern void addbchl(int val);
extern void GlobalPrefix(char);
extern void jumpc(int);
extern void jumpnc(int);
extern void zpushflags(void);
extern void zpopflags(void);
extern void jumpnc(int);
extern void jumpc(int);
extern void jumpr(int);
extern void opjumpr(char *, int);
extern void setcond(int);
extern void dummy(LVALUE *);
extern void LoadAccum(void);
extern void CpCharVal(int);
extern void EmitLine(int);
extern void OutIndex(int);
extern void popframe(void);
extern void pushframe(void);
extern void FrameP(void);
extern void PutFrame(char,int);
extern void RestoreSP(char);
extern int CheckOffset(int);
extern void zcarryconv(void);
extern void convUint2char(void);
extern void convSint2char(void);
extern void savehl(void);
extern void savede(void);
extern void restorehl(void);
extern void restorede(void);
extern void output_section(char *section_name);
extern void function_appendix(SYMBOL *func);
extern void gen_builtin_strcpy(); 
extern void gen_builtin_strchr(int32_t c); 
extern void gen_builtin_memset(int32_t c, int32_t s);
extern void gen_builtin_memcpy(int32_t src, int32_t n);
extern void intrinsic_in(SYMBOL *sym);
extern void intrinsic_out(SYMBOL *sym);
