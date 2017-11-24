#ifndef DNF_REPO_PRIVATE_HPP
#define DNF_REPO_PRIVATE_HPP

#include <string>
#include <vector>

#include "repo.hpp"

/// Nonpublic implementation part of class representing a repository.
/**
 * Here goes the detailed description.
 * It can span multiple lines in the comment block.
 *
 * Paragraphs are delimited with blank lines.
 * Markdown is supported.
 */
class Repo::Impl {
public:
    /// Sets the id of this repository.
    /**
     * A more elaborate description of the setter.
     * \param value the string to use as the new id
     */
    void set_repoid(const std::string &value) { repoid = value; }

    /// Returns the id of this repository.
    /**
     * A more elaborate description of the getter.
     * \return the id of this repository
     */
    const std::string &get_repoid() const { return repoid; }

    /// Sets the baseurl of this repository.
    void set_baseurl(const std::vector<std::string> &value) { baseurl = value; }
    /// Returns the baseurl of this repository.
    const std::vector<std::string> &get_baseurl() const { return baseurl; }
    /// Returns the packages in this repository.
    const std::vector<Package *> &getPackages() const { return packages; }
    /// Sets the packages in this repository.
    void setPackages(std::vector<Package *> &value) { packages = value; }

private:
    std::string repoid;
    std::string name;
    std::vector<std::string> baseurl;
    std::vector<Package *> packages;
};

#endif
