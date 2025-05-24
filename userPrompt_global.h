#ifndef USERPROMPT_GLOBAL_H
#define USERPROMPT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(USERPROMPT_LIBRARY)
#define USERPROMPT_EXPORT Q_DECL_EXPORT
#else
#define USERPROMPT_EXPORT Q_DECL_IMPORT
#endif

#endif // USERPROMPT_GLOBAL_H
