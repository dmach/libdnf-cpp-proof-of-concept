#ifndef SWDB_PKG_H
#define SWDB_PKG_H

#include <glib-object.h>

G_BEGIN_DECLS

#define DNF_TYPE_SWDB_PKG dnf_swdb_pkg_get_type()
G_DECLARE_FINAL_TYPE(DnfSwdbPkg, dnf_swdb_pkg, DNF, SWDB_PKG, GObject)

struct _DnfSwdbPkg
{
    GObject parent_instance;
    gchar *name;
    gint epoch;
    gchar *version;
    gchar *release;
    gchar *arch;
};

DnfSwdbPkg *
dnf_swdb_pkg_new(const gchar *name, gint epoch, const gchar *version, const gchar *release, const gchar *arch);

gchar *
dnf_swdb_pkg_nevra(DnfSwdbPkg *self);

G_END_DECLS

#endif
