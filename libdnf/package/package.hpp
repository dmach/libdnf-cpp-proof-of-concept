#ifndef DNF_PACKAGE_HPP
#define DNF_PACKAGE_HPP

#include <string>

/// Class representing a package.
/**
 * Here goes the detailed description.
 * It can span multiple lines in the comment block.
 *
 * Paragraphs are delimited with blank lines.
 * Markdown is supported.
 */
class Package {
public:

    /// Default contructor.
    /** A more elaborate description of the constructor. */
    Package() = default;

    /// Default destructor.
    /** A more elaborate description of the destructor. */
    virtual ~Package() = default;

    // class is small enough for now, is it ok to leave getters in header ??

    /// Returns the name of this package.
    /**
     * A more elaborate description of the getter.
     * \return the name of this package
     */
    const std::string &getName() const { return name; }

    /// Sets the name of this package.
    /**
     * A more elaborate description of the setter.
     * \param value the string to use as the new name
     */
    void setName(const std::string &value) { name = value; }

protected:
    std::string name;
};

#endif
