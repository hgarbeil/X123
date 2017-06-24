#ifndef X123DLL_GLOBAL_H
#define X123DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(X123DLL_LIBRARY)
#  define X123DLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define X123DLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // X123DLL_GLOBAL_H
