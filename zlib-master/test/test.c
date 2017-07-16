#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strlen
#include <assert.h>
#include "zlib.h"
//avoid corruption of input and output data on windows systems so if another user decides to run this in windows there wont be any issues
#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif
//buffer size for feeding data to and pulling data from zlib routines
#define CHUNK 16384 

#ifdef STDC
#  include <string.h>
#  include <stdlib.h>
#endif

#if defined(VMS) || defined(RISCOS)
#  define TESTFILE "foo-gz"
#else
#  define TESTFILE "foo.gz"
#endif

#define CHECK_ERR(err, msg) { \
    if (err != Z_OK) { \
        fprintf(stderr, "%s error: %d\n", msg, err); \
        exit(1); \
    } \
}

static z_const char hello[] = "hello, hello!";//goal is to print this string out
static const char dict[] = "hello";
static uLong dictId;//only available in this file
//test if this stack can be put into header
void test_deflate       OF((Byte *compr, uLong comprLen));
void test_inflate       OF((Byte *compr, uLong comprLen,
                            Byte *uncompr, uLong uncomprLen));
void test_large_deflate OF((Byte *compr, uLong comprLen,
                            Byte *uncompr, uLong uncomprLen));
void test_large_inflate OF((Byte *compr, uLong comprLen,
                            Byte *uncompr, uLong uncomprLen));
void test_flush         OF((Byte *compr, uLong *comprLen));
void test_sync          OF((Byte *compr, uLong comprLen,
                            Byte *uncompr, uLong uncomprLen));
void test_dict_deflate  OF((Byte *compr, uLong comprLen));
void test_dict_inflate  OF((Byte *compr, uLong comprLen,
                            Byte *uncompr, uLong uncomprLen));
int  main               OF((int argc, char *argv[]));
struct data{
	int ret, flush;//ret used for return codes.flush will keep track of flush state for deflate().
	unsigned have;
    z_stream strm;//struct
	unsigned char in[CHUNK];//assign var CHUNK TO in
	unsigned char out[CHUNK];

}dat;
//functions
//compress from file source to file destination
int def(FILE *source,FILE *destination,void const *lhs, void const *rhs, int level){
	/*int ret, flush;//ret used for return codes.flush will keep track of flush state for deflate().
	unsigned have;
    z_stream strm;//struct
	unsigned char in[CHUNK];//assign var CHUNK TO in
	unsigned char out[CHUNK];*/
	struct dat const *const l = lhs;
    dat.strm.zalloc = Z_NULL;//this needs to be tested
	
	
	
}
//test
#ifdef Z_SOLO


#endif
int main(){










}
