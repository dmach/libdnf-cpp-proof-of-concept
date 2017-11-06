/*
   Copyright (C) 2017 Jaroslav Rohel <jrohel@redhat.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef _BGETTEXT_LIB_H_
#define _BGETTEXT_LIB_H_

#ifndef GETTEXT_DOMAIN
#error You must define GETTEXT_DOMAIN before including dnf18n-lib.h.
#endif

#include "bgettext-common.h"

#define _(msgId) ((const char *)dgettext(GETTEXT_DOMAIN, msgId))
#define P_(msgId, msgIdPlural, n) ((const char *)dngettext(GETTEXT_DOMAIN, msgId, msgIdPlural, n))
#define C_(context, msgId) dnf_dpgettext2(GETTEXT_DOMAIN, context "\004" msgId, sizeof(context))
#define CP_(context, msgId, msgIdPlural, n) ((const char *)dnf_dnpgettext2(GETTEXT_DOMAIN, context "\004" msgId, sizeof(context), msgIdPlural, n))

#define TM_(markedMsg, n) dnf_dmgettext(GETTEXT_DOMAIN, markedMsg, n)

#endif // _BGETTEXT_LIB_H_
