FILE(REMOVE_RECURSE
  "libshogun.pdb"
  "libshogun.so"
  "libshogun.so.17.1"
  "libshogun.so.17"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/shogun.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
