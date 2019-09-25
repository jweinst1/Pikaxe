
# Header Check Script #

# This file is meant to be run as part of a CMakeLists.txt
# Do not run this directly



find_file(HAVE_STDINT_HEADER stdint.h)

if(HAVE_STDINT_HEADER)
   message("** stdint.h found")
   add_definitions(-DHAVE_STDINT)
else(HAVE_STDINT_HEADER)
   message("** stdint.h not found")
endif(HAVE_STDINT_HEADER)


find_file(HAVE_WCHAR_HEADER wchar.h)

if(HAVE_WCHAR_HEADER)
   message("** wchar.h found")
   add_definitions(-DHAVE_WCHAR_H)
else(HAVE_WCHAR_HEADER)
   message("** wchar.h not found")
endif(HAVE_WCHAR_HEADER)

find_file(HAVE_STDBOOL_HEADER stdbool.h)

if(HAVE_STDBOOL_HEADER)
   message("** stdbool.h found")
   add_definitions(-DHAVE_STDBOOL)
else(HAVE_STDBOOL_HEADER)
   message("** stdbool.h not found")
endif(HAVE_STDBOOL_HEADER)
