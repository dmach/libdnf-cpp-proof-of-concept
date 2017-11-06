#include "dnf-swdb-pkg.h"

G_DEFINE_TYPE(DnfSwdbPkg, dnf_swdb_pkg, G_TYPE_OBJECT)

static void
dnf_swdb_pkg_finalize(GObject *object)
{
    DnfSwdbPkg *pkg = (DnfSwdbPkg *)object;
    g_free(pkg->name);
    g_free(pkg->version);
    g_free(pkg->release);
    g_free(pkg->arch);
    G_OBJECT_CLASS(dnf_swdb_pkg_parent_class)->finalize(object);
}

// SWDB Package Class initialiser
static void
dnf_swdb_pkg_class_init(DnfSwdbPkgClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);
    object_class->finalize = dnf_swdb_pkg_finalize;
}

// SWDB Package object initialiser
static void
dnf_swdb_pkg_init(DnfSwdbPkg *self)
{
}

gchar *
dnf_swdb_pkg_nevra(DnfSwdbPkg *self)
{
    return g_strdup_printf("%s-%d:%s-%s.%s", self->name, self->epoch, self->version, self->release, self->arch);
}

/**
 * dnf_swdb_pkg_new:
 *
 * Creates a new #DnfSwdbPkg.
 *
 * Returns: a #DnfSwdbPkg
 **/
DnfSwdbPkg *
dnf_swdb_pkg_new(const gchar *name, gint epoch, const gchar *version, const gchar *release, const gchar *arch)
{
    DnfSwdbPkg *swdbpkg = (DnfSwdbPkg *)g_object_new(DNF_TYPE_SWDB_PKG, NULL);
    swdbpkg->name = g_strdup(name);
    swdbpkg->epoch = epoch;
    swdbpkg->version = g_strdup(version);
    swdbpkg->release = g_strdup(release);
    swdbpkg->arch = g_strdup(arch);
    return swdbpkg;
}
