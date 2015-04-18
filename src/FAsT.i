%module FAsT

%{
/* 相关引用 */
    #define SWIG_FILE_WITH_INIT
    #include "FAsT.h"
%}

/* 对STL的支持 */
%include stl.i
%include numpy.i

%init %{
    import_array();
%}

/* Wrapper并生成代码 */
%include "FAsT.h"

double match(unsigned char * IN_ARRAY2, int DIM1, int DIM2,
     unsigned char * IN_ARRAY2, int DIM1, int DIM2);




