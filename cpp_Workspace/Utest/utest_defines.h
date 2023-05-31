#pragma once
#ifdef UTEST
#define PUBLIC_4_UTEST(VisInProdCode) public
#else
#define PUBLIC_4_UTEST(VisInProdCode) VisInProdCode
#endif
