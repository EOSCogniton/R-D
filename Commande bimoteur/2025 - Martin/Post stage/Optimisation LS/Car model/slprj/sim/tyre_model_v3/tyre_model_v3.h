#ifndef tyre_model_v3_h_
#define tyre_model_v3_h_
#ifndef tyre_model_v3_COMMON_INCLUDES_
#define tyre_model_v3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "tyre_model_v3_types.h"
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#include <stddef.h>
typedef struct { real_T lct42tatoy ; real_T ei44suc5c3 ; real_T fqa5mbgyqs ;
real_T dy4t2jxyhg ; real_T ko0kh01f00 ; real_T cxe34l2z2j ; real_T iokb55mnql
; boolean_T cv1bc5rv2n ; boolean_T jhsrxr2qhc ; } gma25kkctb ; typedef struct
{ real_T l50gof4un3 ; boolean_T ahj5le1ih5 ; int8_T ovizfkrupo ; int8_T
e1wpm1ixxs ; int8_T ns0rq1s4hq ; int8_T kfhlanvtu0 ; int8_T mag22junxe ;
int8_T gvdrtrfikl ; uint8_T nuqytltz2r ; uint8_T ohwcdguj5x ; boolean_T
bl3irskckc ; boolean_T emeik3foev ; } ov2snqzwyb ; typedef struct { real_T
m2ls2nvsjm ; } p4mxahnttj ; typedef struct { real_T m2ls2nvsjm ; } ajwcjnqfef
; typedef struct { boolean_T m2ls2nvsjm ; } n1frjly5vk ; typedef struct {
gma25kkctb h0jsss4leb ; } nyisian3vz ; typedef struct { ov2snqzwyb h0jsss4leb
; } of3wnswvbh ; typedef struct { p4mxahnttj h0jsss4leb ; } cfzypzqi0j ;
typedef struct { ajwcjnqfef h0jsss4leb ; } ehnpzlddm4 ; typedef struct {
n1frjly5vk h0jsss4leb ; } oyy3nll20s ; typedef struct { real_T igjedshoe4 ;
real_T pcdkojx0fp ; real_T kxslg41o4t ; real_T nutklrrq5d ; real_T e233cbx50i
; real_T ilikk2jnki ; real_T h1teptunzh ; real_T jqxvoduvxg ; real_T
ft3iy4spnc ; real_T ovdevzzrsn ; nyisian3vz jmjnhe2dwp [ 1 ] ; } kbi1kbewk0 ;
typedef struct { int_T ppstgdg0z4 ; boolean_T gyq3vd01l4 ; of3wnswvbh
jmjnhe2dwp [ 1 ] ; } cpepv4pomu ; typedef struct { real_T pqho1itqp2 ; real_T
hefyhheelt ; real_T fzqtz4mp3r [ 2 ] ; real_T kbmxmkxuee ; real_T a1ntnbdeq2
; cfzypzqi0j jmjnhe2dwp [ 1 ] ; } e3e2pluf2v ; typedef struct { real_T
pqho1itqp2 ; real_T hefyhheelt ; real_T fzqtz4mp3r [ 2 ] ; real_T kbmxmkxuee
; real_T a1ntnbdeq2 ; ehnpzlddm4 jmjnhe2dwp [ 1 ] ; } cwovm3tzto ; typedef
struct { boolean_T pqho1itqp2 ; boolean_T hefyhheelt ; boolean_T fzqtz4mp3r [
2 ] ; boolean_T kbmxmkxuee ; boolean_T a1ntnbdeq2 ; oyy3nll20s jmjnhe2dwp [ 1
] ; } gu4pq1n4un ; struct kei4gm5dju_ { real_T P_0 ; real_T P_1 ; real_T P_2
; real_T P_3 ; real_T P_4 ; boolean_T P_5 ; boolean_T P_6 ; boolean_T P_7 ;
boolean_T P_8 [ 8 ] ; } ; struct hctsax3iza_ { real_T P_0 ; kei4gm5dju
h0jsss4leb ; } ; struct hrwk52cm0s2_ { real_T P_3 ; real_T P_4 ; real_T P_5 ;
real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11
; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ; real_T P_16 ;
real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T P_21 ; real_T
P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T P_26 ; real_T P_27 ;
real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T P_32 ; real_T
P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 ; real_T P_38 ;
real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T
P_44 ; real_T P_45 ; real_T P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ;
real_T P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T
P_55 ; real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ;
real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T
P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ;
real_T P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T
P_77 ; real_T P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ;
real_T P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T
P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ;
real_T P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T
P_99 ; real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T
P_104 ; real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T
P_109 ; real_T P_110 ; real_T P_111 ; real_T P_112 ; real_T P_113 ; real_T
P_114 ; real_T P_115 ; real_T P_116 ; real_T P_117 ; real_T P_118 ; real_T
P_119 ; real_T P_120 ; real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T
P_124 ; real_T P_125 ; real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T
P_129 ; real_T P_130 ; real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T
P_134 ; real_T P_135 ; real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T
P_139 ; real_T P_140 ; real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T
P_144 ; real_T P_145 ; real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T
P_149 ; real_T P_150 ; real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T
P_154 ; real_T P_155 ; real_T P_156 ; real_T P_157 ; real_T P_158 ; real_T
P_159 ; real_T P_160 ; real_T P_161 ; real_T P_162 ; real_T P_163 ; real_T
P_164 ; real_T P_165 ; real_T P_166 ; real_T P_167 ; real_T P_168 ; real_T
P_169 ; real_T P_170 ; real_T P_171 ; real_T P_172 ; real_T P_173 ; real_T
P_174 ; real_T P_175 ; real_T P_176 ; real_T P_177 ; real_T P_178 ; real_T
P_179 ; real_T P_180 ; real_T P_181 ; real_T P_182 ; real_T P_183 ; real_T
P_184 ; real_T P_185 ; real_T P_186 ; real_T P_187 ; real_T P_188 ; real_T
P_189 ; real_T P_190 ; real_T P_191 ; real_T P_192 ; real_T P_193 ; real_T
P_194 ; real_T P_195 ; real_T P_196 ; real_T P_197 ; real_T P_198 ; real_T
P_199 ; real_T P_200 ; real_T P_201 ; real_T P_202 ; real_T P_203 ; real_T
P_204 ; real_T P_205 ; real_T P_206 ; real_T P_207 ; real_T P_208 ; real_T
P_209 ; real_T P_210 ; real_T P_211 ; real_T P_212 [ 279 ] ; real_T P_213 ;
real_T P_214 ; real_T P_215 ; real_T P_216 ; real_T P_217 ; real_T P_218 ;
real_T P_219 ; real_T P_220 ; real_T P_221 ; real_T P_222 ; real_T P_223 ;
real_T P_224 ; real_T P_225 ; real_T P_226 ; real_T P_227 ; real_T P_228 ;
real_T P_229 ; real_T P_230 ; real_T P_231 ; real_T P_232 ; real_T P_233 ;
real_T P_234 ; real_T P_235 ; real_T P_236 ; real_T P_237 ; real_T P_238 ;
real_T P_239 ; real_T P_240 ; real_T P_241 ; real_T P_242 ; real_T P_243 ;
real_T P_244 ; real_T P_245 [ 27 ] ; real_T P_246 ; real_T P_247 ; real_T
P_248 ; real_T P_249 ; real_T P_250 ; hctsax3iza jmjnhe2dwp ; } ; struct
i2oppvus03 { struct SimStruct_tag * _mdlRefSfcnS ; struct { boolean_T
mr_nonContSig0 [ 1 ] ; boolean_T mr_nonContSig1 [ 1 ] ; } NonContDerivMemory
; ssNonContDerivSigInfo nonContDerivSignal [ 2 ] ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 5 ] ; int32_T * vardimsAddress [ 5
] ; RTWLoggingFcnPtr loggingPtrs [ 5 ] ; sysRanDType * systemRan [ 10 ] ;
int_T systemTid [ 10 ] ; } DataMapInfo ; struct { int_T mdlref_GlobalTID [ 3
] ; time_T tStart ; } Timing ; } ; typedef struct { kbi1kbewk0 rtb ;
cpepv4pomu rtdw ; ilpumsz4jk rtm ; } mpynaegtodz ; extern real_T rtP_J ;
extern real_T rtP_Re ; extern real_T rtP_v0 ; extern void c32f4zxe52 ( SimStruct
* _mdlRefSfcnS , ssNonContDerivSigFeedingOutports * * mr_nonContOutputArray ,
int_T mdlref_TID0 , int_T mdlref_TID1 , int_T mdlref_TID2 , ilpumsz4jk *
const mge4gz3cxc , kbi1kbewk0 * localB , cpepv4pomu * localDW , e3e2pluf2v *
localX , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) ; extern void mr_tyre_model_v3_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) ; extern mxArray *
mr_tyre_model_v3_GetDWork ( const mpynaegtodz * mdlrefDW ) ; extern void
mr_tyre_model_v3_SetDWork ( mpynaegtodz * mdlrefDW , const mxArray * ssDW ) ;
extern void mr_tyre_model_v3_RegisterSimStateChecksum ( SimStruct * S ) ;
extern mxArray * mr_tyre_model_v3_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * tyre_model_v3_GetCAPIStaticMap ( void
) ; extern void mfxzccj4ak ( real_T e3vrcfiltp , gma25kkctb * localB ,
ov2snqzwyb * localDW , kei4gm5dju * localP , p4mxahnttj * localX ) ; extern
void drnetozaxs ( gma25kkctb * localB , ov2snqzwyb * localDW ) ; extern void
kzmi5yl3ll ( gma25kkctb * localB ) ; extern void nzjp0uqguk ( gma25kkctb *
localB , ov2snqzwyb * localDW , ajwcjnqfef * localXdot ) ; extern void
dzrewlxlzm ( ilpumsz4jk * const mge4gz3cxc , real_T ljwhnneujn , real_T
c0lt5bbuvg , real_T efzxwcoris , real_T e3vrcfiltp , real_T aegakspck3 ,
real_T fz1cyaeoip , real_T erouy1wkuv , gma25kkctb * localB , ov2snqzwyb *
localDW , kei4gm5dju * localP , p4mxahnttj * localX ) ; extern void
dzrewlxlzmTID2 ( real_T aegakspck3 , gma25kkctb * localB , kei4gm5dju *
localP ) ; extern void ctj0dr1dia ( kbi1kbewk0 * localB , cpepv4pomu *
localDW , e3e2pluf2v * localX ) ; extern void b33kdovnog ( kbi1kbewk0 *
localB , cpepv4pomu * localDW , e3e2pluf2v * localX ) ; extern void
md0tlitb5s ( kbi1kbewk0 * localB ) ; extern void mu3r0ofjgl ( kbi1kbewk0 *
localB , cpepv4pomu * localDW , e3e2pluf2v * localX , cwovm3tzto * localXdot
) ; extern void jj2kuw0p0x ( ilpumsz4jk * const mge4gz3cxc ) ; extern void
tyre_model_v3 ( ilpumsz4jk * const mge4gz3cxc , const real_T * hngao5bd5a ,
const real_T * jjbr3waavj , const real_T * b0xm141yrs , const real_T *
lp4lztkd0p , const real_T * hp5v1yavgt , const real_T * djgnqgz3jn , const
real_T * mhoetbzx42 , real_T * cnit1zvd03 , real_T * e1kbecdoe5 , real_T *
bustwiimgx , real_T * aykuz34ojv , kbi1kbewk0 * localB , cpepv4pomu * localDW
, e3e2pluf2v * localX ) ; extern void tyre_model_v3TID2 ( kbi1kbewk0 * localB
) ; extern void bpwqvb04id ( ilpumsz4jk * const mge4gz3cxc ) ;
#endif
