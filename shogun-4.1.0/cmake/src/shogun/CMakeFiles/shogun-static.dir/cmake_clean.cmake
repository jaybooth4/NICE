FILE(REMOVE_RECURSE
  "libshogun.pdb"
  "libshogun.a"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/shogun-static.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
