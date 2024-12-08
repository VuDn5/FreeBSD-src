.include <bsd.own.mk>

# OpenSSL version used for manual page generation
<<<<<<< HEAD
OPENSSL_VER=	3.0.15
OPENSSL_DATE=	2024-09-03
=======
OPENSSL_VER=	3.0.12
OPENSSL_DATE=	2023-10-24
>>>>>>> 8d2b56da39cec2f5241b41f35fd70b125ace1c0a

LCRYPTO_SRC=	${SRCTOP}/crypto/openssl
LCRYPTO_DOC=	${LCRYPTO_SRC}/doc

CFLAGS+=	-I${LCRYPTO_SRC}
CFLAGS+=	-I${LCRYPTO_SRC}/include
CFLAGS+=	-I${LCRYPTO_SRC}/providers/common/include
CFLAGS+=	-I${LCRYPTO_SRC}/providers/implementations/include

.include "Makefile.common"

.for pcfile in ${PCFILES}
${pcfile}:	${pcfile}.in
	sed -e 's,@openssl_ver@,${OPENSSL_VER},g' ${.ALLSRC} > ${.TARGET}
.endfor
CLEANFILES+=	${PCFILES}
