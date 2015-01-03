#!/usr/bin/python

import os
import binascii

# FNAMES
dir_movies = "movies/"
fname_movies_h = "inc/movies.h"
fname_movies_c = "src/movies.c"

files_list = []

for (root, dirs, files) in os.walk(dir_movies):
    for name in files:
	files_list += [os.path.join(root, name)]


# .H
fh = open(fname_movies_h, "w")
fh.write("#ifndef MOVIES_H\n")
fh.write("#define MOVIES_H\n")
fh.write("\n")
fh.write('#include "types.h"\n')
fh.write("\n")

fh.write("extern const uint32_t count_bin_files;\n")
fh.write("\n")
fh.write("extern const uint8_t* array_bin_ptrs[];\n")

fh.write("\n")
fh.write("#endif\n")
fh.close()


# .C
fc = open(fname_movies_c, "w")
fc.write('#include "movies.h"\n')
fc.write("\n")

for fname in files_list:
    cfname = fname.replace("/", "_").replace(".", "_")
    fc.write("const uint8_t bin_%s[] = {\n" % cfname)

    with open(fname, "rb") as f:
	i = 0
	for b in f.read():
	    if (i % 0x10 == 0):
		fc.write("    ")
	    i = i + 1
	    fc.write("0x%s, " % binascii.hexlify(b))
	    if (i % 0x10 == 0):
		fc.write("\n")

	if (i % 0x10 != 0):
	    fc.write("\n")

    fc.write("};\n")
    fc.write("\n")

fc.write("\n")
fc.write("\n")
fc.write("const uint32_t count_bin_files = %d;\n" % len(files_list))
fc.write("\n")
fc.write("const uint8_t* array_bin_ptrs[] = {\n")
for fname in files_list:
    cfname = fname.replace("/", "_").replace(".", "_")
    fc.write("    (uint8_t*) &bin_%s, \n" % cfname)
fc.write("};\n");

fc.close()

