# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


SET(CPACK_BINARY_BUNDLE "")
SET(CPACK_BINARY_CYGWIN "")
SET(CPACK_BINARY_DEB "")
SET(CPACK_BINARY_DRAGNDROP "")
SET(CPACK_BINARY_NSIS "")
SET(CPACK_BINARY_OSXX11 "")
SET(CPACK_BINARY_PACKAGEMAKER "")
SET(CPACK_BINARY_RPM "")
SET(CPACK_BINARY_STGZ "")
SET(CPACK_BINARY_TBZ2 "")
SET(CPACK_BINARY_TGZ "")
SET(CPACK_BINARY_TZ "")
SET(CPACK_BINARY_WIX "")
SET(CPACK_BINARY_ZIP "")
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_COMPONENTS_ALL "headers;libraries;libshogun-examples")
SET(CPACK_COMPONENTS_IGNORE_GROUPS "ON")
SET(CPACK_COMPONENT_GROUP_DEVELOPMENT_DESCRIPTION "All of the packages that's required for developing with Shogun")
SET(CPACK_COMPONENT_GROUP_DEVELOPMENT_EXPANDED "ON")
SET(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
SET(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
SET(CPACK_COMPONENT_cmdline_DEPENDS "libraries")
SET(CPACK_COMPONENT_cmdline_DESCRIPTION "Command Line interface of Shogun")
SET(CPACK_COMPONENT_cmdline_DISPLAY_NAME "Command Line Interface")
SET(CPACK_COMPONENT_cmdline_GROUP "Runtime")
SET(CPACK_COMPONENT_csharp_DEPENDS "libraries")
SET(CPACK_COMPONENT_csharp_DESCRIPTION "C# modular interface of Shogun")
SET(CPACK_COMPONENT_csharp_GROUP "Runtime")
SET(CPACK_COMPONENT_headers_DEPENDS "libraries")
SET(CPACK_COMPONENT_headers_DESCRIPTION "Development files for Shogun Machine Learning Toolbox")
SET(CPACK_COMPONENT_headers_DISPLAY_NAME "libshogun-dev")
SET(CPACK_COMPONENT_headers_GROUP "Development")
SET(CPACK_COMPONENT_java_DEPENDS "libraries")
SET(CPACK_COMPONENT_java_DESCRIPTION "Java modular interface of Shogun")
SET(CPACK_COMPONENT_java_GROUP "Runtime")
SET(CPACK_COMPONENT_libraries_DESCRIPTION "Shogun Machine Learning Toolbox")
SET(CPACK_COMPONENT_libraries_DISPLAY_NAME "libshogun17")
SET(CPACK_COMPONENT_libraries_GROUP "Runtime")
SET(CPACK_COMPONENT_libraries_REQUIRED "On")
SET(CPACK_COMPONENT_lua_DEPENDS "libraries")
SET(CPACK_COMPONENT_lua_DESCRIPTION "Lua modular interface of Shogun")
SET(CPACK_COMPONENT_lua_GROUP "Runtime")
SET(CPACK_COMPONENT_octave_DEPENDS "libraries")
SET(CPACK_COMPONENT_octave_DESCRIPTION "OCTAVE modular interface of Shogun")
SET(CPACK_COMPONENT_octave_GROUP "Runtime")
SET(CPACK_COMPONENT_python_DEPENDS "libraries")
SET(CPACK_COMPONENT_python_DESCRIPTION "Python modular interface of Shogun")
SET(CPACK_COMPONENT_python_DISPLAY_NAME "python-shogun")
SET(CPACK_COMPONENT_python_GROUP "Runtime")
SET(CPACK_COMPONENT_r_DEPENDS "libraries")
SET(CPACK_COMPONENT_r_DESCRIPTION "R modular interface of Shogun")
SET(CPACK_COMPONENT_r_GROUP "Runtime")
SET(CPACK_COMPONENT_ruby_DEPENDS "libraries")
SET(CPACK_COMPONENT_ruby_DESCRIPTION "Ruby modular interface of Shogun")
SET(CPACK_COMPONENT_ruby_GROUP "Runtime")
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libstdc++6, libsnappy1, zlib1g, liblzma5, libbz2-1.0, liblzo2-2, libxml2, libhdf5-8, libnlopt0, liblapack3, libglpk36, libcurl3-gnutls, libarpack2")
SET(CPACK_DEBIAN_PACKAGE_SECTION "science")
SET(CPACK_DEB_COMPONENT_INSTALL "ON")
SET(CPACK_GENERATOR "DEB")
SET(CPACK_INSTALL_CMAKE_PROJECTS "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake;shogun;ALL;/")
SET(CPACK_INSTALL_PREFIX "/usr/local")
SET(CPACK_MODULE_PATH "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake")
SET(CPACK_NSIS_DISPLAY_NAME "shogun 4.1.0")
SET(CPACK_NSIS_INSTALLER_ICON_CODE "")
SET(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
SET(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
SET(CPACK_NSIS_PACKAGE_NAME "shogun 4.1.0")
SET(CPACK_OUTPUT_CONFIG_FILE "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/CPackConfig.cmake")
SET(CPACK_PACKAGE_CONTACT "shogun@shogun-toolbox.org")
SET(CPACK_PACKAGE_DEFAULT_LOCATION "/")
SET(CPACK_PACKAGE_DESCRIPTION "Large Scale Machine Learning Toolbox
 SHOGUN - is a new machine learning toolbox with focus on large scale kernel
 methods and especially on Support Vector Machines (SVM) with focus to
 bioinformatics. It provides a generic SVM object interfacing to several
 different SVM implementations. Each of the SVMs can be combined with a variety
 of the many kernels implemented. It can deal with weighted linear combination
 of a number of sub-kernels, each of which not necessarily working on the same
 domain, where  an optimal sub-kernel weighting can be learned using Multiple
 Kernel Learning.  Apart from SVM 2-class classification and regression
 problems, a number of linear methods like Linear Discriminant Analysis (LDA),
 Linear Programming Machine (LPM), (Kernel) Perceptrons and also algorithms to
 train hidden markov models are implemented. The input feature-objects can be
 dense, sparse or strings and of type int/short/double/char and can be
 converted into different feature types. Chains of preprocessors (e.g.
 substracting the mean) can be attached to each feature object allowing for
 on-the-fly pre-processing.
 .
 SHOGUN comes in different flavours, a stand-a-lone version and also with
 interfaces to Matlab(tm), R, Octave, Readline and Python. This is the core
 library with the machine learning methods and ui helpers all interfaces are
 based on.")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-2.8/Templates/CPack.GenericDescription.txt")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Shogun Machine Learning Toolbox")
SET(CPACK_PACKAGE_FILE_NAME "shogun_4.1.0_x86_64")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "shogun 4.1.0")
SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "shogun 4.1.0")
SET(CPACK_PACKAGE_NAME "shogun")
SET(CPACK_PACKAGE_RELOCATABLE "true")
SET(CPACK_PACKAGE_VENDOR "shogun")
SET(CPACK_PACKAGE_VERSION "4.1.0")
SET(CPACK_PACKAGE_VERSION_MAJOR "4")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_RESOURCE_FILE_LICENSE "/usr/share/cmake-2.8/Templates/CPack.GenericLicense.txt")
SET(CPACK_RESOURCE_FILE_README "/usr/share/cmake-2.8/Templates/CPack.GenericDescription.txt")
SET(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake-2.8/Templates/CPack.GenericWelcome.txt")
SET(CPACK_SET_DESTDIR "OFF")
SET(CPACK_SOURCE_CYGWIN "")
SET(CPACK_SOURCE_GENERATOR "TGZ;TBZ2;TZ")
SET(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/CPackSourceConfig.cmake")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "shogun_4.1.0-")
SET(CPACK_SOURCE_TBZ2 "ON")
SET(CPACK_SOURCE_TGZ "ON")
SET(CPACK_SOURCE_TZ "ON")
SET(CPACK_SOURCE_ZIP "OFF")
SET(CPACK_STRIP_FILES "ON")
SET(CPACK_SYSTEM_NAME "Linux")
SET(CPACK_TOPLEVEL_TAG "Linux")
SET(CPACK_WIX_SIZEOF_VOID_P "8")
