AUTOMAKE_OPTIONS = subdir-objects foreign
check_PROGRAMS = decode_id3 decode_vorbis print
TESTS = $(check_PROGRAMS)

decode_id3_SOURCES = test_decode_id3.cpp ../src/transcoder.cpp
decode_vorbis_SOURCES = test_decode_vorbis.cpp ../src/transcoder.cpp
print_SOURCES = test_print.cpp ../src/transcoder.cpp