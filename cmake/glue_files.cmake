# This module contains functions which
# are meant to combine the content of multiple files into one.
# Specifically, these can be used to make a single header out of
# multiple header files, or to make a single c file out of multiple ones.

function(glue_cfiles dirpath outputfile)
     if(IS_DIRECTORY ${dirpath})
        file(WRITE ${outputfile} "// \n")
        file(GLOB c_dir_files "${dirpath}/*.c")
        foreach(cfile ${c_dir_files})
            file(APPEND ${outputfile} "${cfile} ")
        endforeach()
     else(IS_DIRECTORY ${dirpath})
        message(FATAL_ERROR "Attempted to glue c files in ${dirpath}, but that is not a directory.")
     endif(IS_DIRECTORY ${dirpath})
endfunction()