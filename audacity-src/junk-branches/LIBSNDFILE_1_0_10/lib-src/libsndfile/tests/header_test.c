/*
** Copyright (C) 2001-2004 Erik de Castro Lopo <erikd@mega-nerd.com>
**
** This program is free software ; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation ; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY ; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program ; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <math.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#if (HAVE_DECL_S_IRGRP == 0)
#include <sf_unistd.h>
#endif

#if (defined (WIN32) || defined (_WIN32))
#include <io.h>
#include <direct.h>
#endif

#include	<sndfile.h>

#include	"utils.h"

#define	BUFFER_LEN		(1<<10)
#define LOG_BUFFER_SIZE	1024

static void	update_header_test (const char *filename, int typemajor) ;

static void	update_seek_short_test	(const char *filename, int filetype) ;
static void	update_seek_int_test	(const char *filename, int filetype) ;
static void	update_seek_float_test	(const char *filename, int filetype) ;
static void	update_seek_double_test	(const char *filename, int filetype) ;


static void extra_header_test (const char *filename, int filetype) ;

/* Force the start of this buffer to be double aligned. Sparc-solaris will
** choke if its not.
*/
static	int	data_out [BUFFER_LEN] ;
static	int	data_in	[BUFFER_LEN] ;

int
main (int argc, char *argv [])
{	int		do_all = 0 ;
	int		test_count = 0 ;

	if (argc != 2)
	{	printf ("Usage : %s <test>\n", argv [0]) ;
		printf ("    Where <test> is one of the following:\n") ;
		printf ("           wav  - test WAV file peak chunk\n") ;
		printf ("           aiff - test AIFF file PEAK chunk\n") ;
		printf ("           all  - perform all tests\n") ;
		exit (1) ;
		} ;

	do_all=!strcmp (argv [1], "all") ;

	if (do_all || ! strcmp (argv [1], "wav"))
	{	update_header_test ("header.wav", SF_FORMAT_WAV) ;
		update_seek_short_test ("header_short.wav", SF_FORMAT_WAV) ;
		update_seek_int_test ("header_int.wav", SF_FORMAT_WAV) ;
		update_seek_float_test ("header_float.wav", SF_FORMAT_WAV) ;
		update_seek_double_test ("header_double.wav", SF_FORMAT_WAV) ;
		extra_header_test ("extra.wav", SF_FORMAT_WAV) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "aiff"))
	{	update_header_test ("header.aiff", SF_FORMAT_AIFF) ;
		update_seek_short_test ("header_short.aiff", SF_FORMAT_AIFF) ;
		update_seek_int_test ("header_int.aiff", SF_FORMAT_AIFF) ;
		update_seek_float_test ("header_float.aiff", SF_FORMAT_AIFF) ;
		update_seek_double_test ("header_double.aiff", SF_FORMAT_AIFF) ;
		extra_header_test ("extra.aiff", SF_FORMAT_AIFF) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "au"))
	{	update_header_test ("header.au", SF_FORMAT_AU) ;
		update_seek_short_test ("header_short.au", SF_FORMAT_AU) ;
		update_seek_int_test ("header_int.au", SF_FORMAT_AU) ;
		update_seek_float_test ("header_float.au", SF_FORMAT_AU) ;
		update_seek_double_test ("header_double.au", SF_FORMAT_AU) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "nist"))
	{	update_header_test ("header.nist", SF_FORMAT_NIST) ;
		update_seek_short_test ("header_short.nist", SF_FORMAT_NIST) ;
		update_seek_int_test ("header_int.nist", SF_FORMAT_NIST) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "paf"))
	{	update_header_test ("header.paf", SF_FORMAT_PAF) ;
		update_seek_short_test ("header_short.paf", SF_FORMAT_PAF) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "ircam"))
	{	update_header_test ("header.ircam", SF_FORMAT_IRCAM) ;
		update_seek_short_test ("header_short.ircam", SF_FORMAT_IRCAM) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "w64"))
	{	update_header_test ("header.w64", SF_FORMAT_W64) ;
		update_seek_short_test ("header_short.w64", SF_FORMAT_W64) ;
		update_seek_int_test ("header_int.w64", SF_FORMAT_W64) ;
		update_seek_float_test ("header_float.w64", SF_FORMAT_W64) ;
		update_seek_double_test ("header_double.w64", SF_FORMAT_W64) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "mat4"))
	{	update_header_test ("header.mat4", SF_FORMAT_MAT4) ;
		update_seek_short_test ("header_short.mat4", SF_FORMAT_MAT4) ;
		update_seek_int_test ("header_int.mat4", SF_FORMAT_MAT4) ;
		update_seek_float_test ("header_float.mat4", SF_FORMAT_MAT4) ;
		update_seek_double_test ("header_double.mat4", SF_FORMAT_MAT4) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "mat5"))
	{	update_header_test ("header.mat5", SF_FORMAT_MAT5) ;
		update_seek_short_test ("header_short.mat5", SF_FORMAT_MAT5) ;
		update_seek_int_test ("header_int.mat5", SF_FORMAT_MAT5) ;
		update_seek_float_test ("header_float.mat5", SF_FORMAT_MAT5) ;
		update_seek_double_test ("header_double.mat5", SF_FORMAT_MAT5) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "pvf"))
	{	update_header_test ("header.pvf", SF_FORMAT_PVF) ;
		update_seek_short_test ("header_short.pvf", SF_FORMAT_PVF) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "avr"))
	{	update_header_test ("header.avr", SF_FORMAT_AVR) ;
		update_seek_short_test ("header_short.avr", SF_FORMAT_AVR) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "htk"))
	{	update_header_test ("header.htk", SF_FORMAT_HTK) ;
		update_seek_short_test ("header_short.htk", SF_FORMAT_HTK) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "svx"))
	{	update_header_test ("header.svx", SF_FORMAT_SVX) ;
		update_seek_short_test ("header_short.svx", SF_FORMAT_SVX) ;
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "voc"))
	{	update_header_test ("header.voc", SF_FORMAT_VOC) ;
		/*-update_seek_short_test ("header_short.voc", SF_FORMAT_VOC) ;-*/
		test_count++ ;
		} ;

	if (do_all || ! strcmp (argv [1], "sds"))
	{	update_header_test ("header.sds", SF_FORMAT_SDS) ;
		/*-update_seek_short_test ("header_short.sds", SF_FORMAT_SDS) ;-*/
		test_count++ ;
		} ;

	if (test_count == 0)
	{	printf ("Mono : ************************************\n") ;
		printf ("Mono : *  No '%s' test defined.\n", argv [1]) ;
		printf ("Mono : ************************************\n") ;
		return 1 ;
		} ;

	return 0 ;
} /* main */


/*============================================================================================
**	Here are the test functions.
*/

static void
update_header_sub (const char *filename, int typemajor, int write_mode)
{	SNDFILE		*outfile, *infile ;
	SF_INFO		sfinfo ;
	int			k, frames ;

	sfinfo.samplerate = 44100 ;
	sfinfo.format = (typemajor | SF_FORMAT_PCM_16) ;
	sfinfo.channels = 1 ;
	sfinfo.frames = 0 ;

	frames = BUFFER_LEN / sfinfo.channels ;

	outfile = test_open_file_or_die (filename, write_mode, &sfinfo, __LINE__) ;

	for (k = 0 ; k < BUFFER_LEN ; k++)
		data_out [k] = k + 1 ;
	test_write_int_or_die (outfile, 0, data_out, BUFFER_LEN, __LINE__) ;

	if (typemajor != SF_FORMAT_HTK)
	{	/* The HTK header is not correct when the file is first written. */
		infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, __LINE__) ;
		sf_close (infile) ;
		} ;

	sf_command (outfile, SFC_UPDATE_HEADER_NOW, NULL, 0) ;

	/*
	** Open file and check log buffer for an error. If header update failed
	** the the log buffer will contain errors.
	*/
	infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, __LINE__) ;
	check_log_buffer_or_die (infile, __LINE__) ;

	if (sfinfo.frames < BUFFER_LEN || sfinfo.frames > BUFFER_LEN + 50)
	{	printf ("\n\nLine %d : Incorrect sample count (%ld should be %d)\n", __LINE__, SF_COUNT_TO_LONG (sfinfo.frames), BUFFER_LEN) ;
		dump_log_buffer (infile) ;
		exit (1) ;
		} ;

	test_read_int_or_die (infile, 0, data_in, BUFFER_LEN, __LINE__) ;
	for (k = 0 ; k < BUFFER_LEN ; k++)
		if (data_out [k] != k + 1)
			printf ("Error : line %d\n", __LINE__) ;

	sf_close (infile) ;

	/* Set auto update on. */
	sf_command (outfile, SFC_SET_UPDATE_HEADER_AUTO, NULL, SF_TRUE) ;

	/* Write more data_out. */
	for (k = 0 ; k < BUFFER_LEN ; k++)
		data_out [k] = k + 2 ;
	test_write_int_or_die (outfile, 0, data_out, BUFFER_LEN, __LINE__) ;

	/* Open file again and make sure no errors in log buffer. */
	infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, __LINE__) ;
	check_log_buffer_or_die (infile, __LINE__) ;

	if (sfinfo.frames < 2 * BUFFER_LEN || sfinfo.frames > 2 * BUFFER_LEN + 50)
	{	printf ("\n\nLine %d : Incorrect sample count (%ld should be %d)\n", __LINE__, SF_COUNT_TO_LONG (sfinfo.frames), 2 * BUFFER_LEN) ;
		dump_log_buffer (infile) ;
		exit (1) ;
		} ;

	sf_close (infile) ;

	sf_close (outfile) ;

	unlink (filename) ;
} /* update_header_sub */

static void
update_header_test (const char *filename, int typemajor)
{
	print_test_name ("update_header_test", filename) ;

#if 0 /*-(OS_IS_WIN32 == 0)-*/
	if (typemajor == SF_FORMAT_PAF)
	{	/*
		** I think this is a bug in the win32 file I/O code in src/file_io.c.
		** I didn't write that code and I don't have the time to debug and
		** fix it. Patches will gladly be accepted. Erik
		*/
		puts ("doesn't work on win32") ;
		return ;
		} ;
#endif

	update_header_sub (filename, typemajor, SFM_WRITE) ;
	update_header_sub (filename, typemajor, SFM_RDWR) ;

	unlink (filename) ;
	puts ("ok") ;
} /* update_header_test */

/*==============================================================================
*/

static void
update_seek_short_test	(const char *filename, int filetype)
{	SNDFILE *outfile, *infile ;
	SF_INFO sfinfo ;
    sf_count_t frames ;
    short buffer [8] ;
	int k ;

	print_test_name ("update_seek_short_test", filename) ;

	memset (buffer, 0, sizeof (buffer)) ;

	/* Create sound outfile with no data. */
	sfinfo.format = filetype | SF_FORMAT_PCM_16 ;
	sfinfo.samplerate = 48000 ;
	sfinfo.channels = 2 ;

	if (sf_format_check (&sfinfo) == SF_FALSE)
		sfinfo.channels = 1 ;

	outfile = test_open_file_or_die (filename, SFM_WRITE, &sfinfo, __LINE__) ;
	sf_close (outfile) ;

	/* Open again for read/write. */
	outfile = test_open_file_or_die (filename, SFM_RDWR, &sfinfo, __LINE__) ;

	/*
	** In auto header update mode, seeking to the end of the file with
    ** SEEK_SET will fail from the 2nd seek on.  seeking to 0, SEEK_END
	** will seek to 0 anyway
	*/
	if (sf_command (outfile, SFC_SET_UPDATE_HEADER_AUTO, NULL, SF_TRUE) == 0)
    {	printf ("\n\nError : sf_command (SFC_SET_UPDATE_HEADER_AUTO) return error : %s\n\n", sf_strerror (outfile)) ;
		exit (1) ;
		} ;

	/* Now write some frames. */
	frames = ARRAY_LEN (buffer) / sfinfo.channels ;

	for (k = 0 ; k < 6 ; k++)
	{	test_seek_or_die (outfile, k * frames, SEEK_SET, k * frames, sfinfo.channels, __LINE__) ;
		test_seek_or_die (outfile, 0, SEEK_END, k * frames, sfinfo.channels, __LINE__) ;

		/* Open file again and make sure no errors in log buffer. */
		infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, __LINE__) ;
		check_log_buffer_or_die (infile, __LINE__) ;
		sf_close (infile) ;

		if (sfinfo.frames != k * frames)
		{	printf ("\n\nLine %d : Incorrect sample count (%ld should be %ld)\n", __LINE__, SF_COUNT_TO_LONG (sfinfo.frames), SF_COUNT_TO_LONG (k + frames)) ;
			dump_log_buffer (infile) ;
			exit (1) ;
			} ;

		if ((k & 1) == 0)
			test_write_short_or_die (outfile, k, buffer, sfinfo.channels * frames, __LINE__) ;
		else
			test_writef_short_or_die (outfile, k, buffer, frames, __LINE__) ;
		} ;

	sf_close (outfile) ;
	unlink (filename) ;

	puts ("ok") ;
	return ;
} /* update_seek_short_test */
static void
update_seek_int_test	(const char *filename, int filetype)
{	SNDFILE *outfile, *infile ;
	SF_INFO sfinfo ;
    sf_count_t frames ;
    int buffer [8] ;
	int k ;

	print_test_name ("update_seek_int_test", filename) ;

	memset (buffer, 0, sizeof (buffer)) ;

	/* Create sound outfile with no data. */
	sfinfo.format = filetype | SF_FORMAT_PCM_32 ;
	sfinfo.samplerate = 48000 ;
	sfinfo.channels = 2 ;

	if (sf_format_check (&sfinfo) == SF_FALSE)
		sfinfo.channels = 1 ;

	outfile = test_open_file_or_die (filename, SFM_WRITE, &sfinfo, __LINE__) ;
	sf_close (outfile) ;

	/* Open again for read/write. */
	outfile = test_open_file_or_die (filename, SFM_RDWR, &sfinfo, __LINE__) ;

	/*
	** In auto header update mode, seeking to the end of the file with
    ** SEEK_SET will fail from the 2nd seek on.  seeking to 0, SEEK_END
	** will seek to 0 anyway
	*/
	if (sf_command (outfile, SFC_SET_UPDATE_HEADER_AUTO, NULL, SF_TRUE) == 0)
    {	printf ("\n\nError : sf_command (SFC_SET_UPDATE_HEADER_AUTO) return error : %s\n\n", sf_strerror (outfile)) ;
		exit (1) ;
		} ;

	/* Now write some frames. */
	frames = ARRAY_LEN (buffer) / sfinfo.channels ;

	for (k = 0 ; k < 6 ; k++)
	{	test_seek_or_die (outfile, k * frames, SEEK_SET, k * frames, sfinfo.channels, __LINE__) ;
		test_seek_or_die (outfile, 0, SEEK_END, k * frames, sfinfo.channels, __LINE__) ;

		/* Open file again and make sure no errors in log buffer. */
		infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, __LINE__) ;
		check_log_buffer_or_die (infile, __LINE__) ;
		sf_close (infile) ;

		if (sfinfo.frames != k * frames)
		{	printf ("\n\nLine %d : Incorrect sample count (%ld should be %ld)\n", __LINE__, SF_COUNT_TO_LONG (sfinfo.frames), SF_COUNT_TO_LONG (k + frames)) ;
			dump_log_buffer (infile) ;
			exit (1) ;
			} ;

		if ((k & 1) == 0)
			test_write_int_or_die (outfile, k, buffer, sfinfo.channels * frames, __LINE__) ;
		else
			test_writef_int_or_die (outfile, k, buffer, frames, __LINE__) ;
		} ;

	sf_close (outfile) ;
	unlink (filename) ;

	puts ("ok") ;
	return ;
} /* update_seek_int_test */
static void
update_seek_float_test	(const char *filename, int filetype)
{	SNDFILE *outfile, *infile ;
	SF_INFO sfinfo ;
    sf_count_t frames ;
    float buffer [8] ;
	int k ;

	print_test_name ("update_seek_float_test", filename) ;

	memset (buffer, 0, sizeof (buffer)) ;

	/* Create sound outfile with no data. */
	sfinfo.format = filetype | SF_FORMAT_FLOAT ;
	sfinfo.samplerate = 48000 ;
	sfinfo.channels = 2 ;

	if (sf_format_check (&sfinfo) == SF_FALSE)
		sfinfo.channels = 1 ;

	outfile = test_open_file_or_die (filename, SFM_WRITE, &sfinfo, __LINE__) ;
	sf_close (outfile) ;

	/* Open again for read/write. */
	outfile = test_open_file_or_die (filename, SFM_RDWR, &sfinfo, __LINE__) ;

	/*
	** In auto header update mode, seeking to the end of the file with
    ** SEEK_SET will fail from the 2nd seek on.  seeking to 0, SEEK_END
	** will seek to 0 anyway
	*/
	if (sf_command (outfile, SFC_SET_UPDATE_HEADER_AUTO, NULL, SF_TRUE) == 0)
    {	printf ("\n\nError : sf_command (SFC_SET_UPDATE_HEADER_AUTO) return error : %s\n\n", sf_strerror (outfile)) ;
		exit (1) ;
		} ;

	/* Now write some frames. */
	frames = ARRAY_LEN (buffer) / sfinfo.channels ;

	for (k = 0 ; k < 6 ; k++)
	{	test_seek_or_die (outfile, k * frames, SEEK_SET, k * frames, sfinfo.channels, __LINE__) ;
		test_seek_or_die (outfile, 0, SEEK_END, k * frames, sfinfo.channels, __LINE__) ;

		/* Open file again and make sure no errors in log buffer. */
		infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, __LINE__) ;
		check_log_buffer_or_die (infile, __LINE__) ;
		sf_close (infile) ;

		if (sfinfo.frames != k * frames)
		{	printf ("\n\nLine %d : Incorrect sample count (%ld should be %ld)\n", __LINE__, SF_COUNT_TO_LONG (sfinfo.frames), SF_COUNT_TO_LONG (k + frames)) ;
			dump_log_buffer (infile) ;
			exit (1) ;
			} ;

		if ((k & 1) == 0)
			test_write_float_or_die (outfile, k, buffer, sfinfo.channels * frames, __LINE__) ;
		else
			test_writef_float_or_die (outfile, k, buffer, frames, __LINE__) ;
		} ;

	sf_close (outfile) ;
	unlink (filename) ;

	puts ("ok") ;
	return ;
} /* update_seek_float_test */
static void
update_seek_double_test	(const char *filename, int filetype)
{	SNDFILE *outfile, *infile ;
	SF_INFO sfinfo ;
    sf_count_t frames ;
    double buffer [8] ;
	int k ;

	print_test_name ("update_seek_double_test", filename) ;

	memset (buffer, 0, sizeof (buffer)) ;

	/* Create sound outfile with no data. */
	sfinfo.format = filetype | SF_FORMAT_DOUBLE ;
	sfinfo.samplerate = 48000 ;
	sfinfo.channels = 2 ;

	if (sf_format_check (&sfinfo) == SF_FALSE)
		sfinfo.channels = 1 ;

	outfile = test_open_file_or_die (filename, SFM_WRITE, &sfinfo, __LINE__) ;
	sf_close (outfile) ;

	/* Open again for read/write. */
	outfile = test_open_file_or_die (filename, SFM_RDWR, &sfinfo, __LINE__) ;

	/*
	** In auto header update mode, seeking to the end of the file with
    ** SEEK_SET will fail from the 2nd seek on.  seeking to 0, SEEK_END
	** will seek to 0 anyway
	*/
	if (sf_command (outfile, SFC_SET_UPDATE_HEADER_AUTO, NULL, SF_TRUE) == 0)
    {	printf ("\n\nError : sf_command (SFC_SET_UPDATE_HEADER_AUTO) return error : %s\n\n", sf_strerror (outfile)) ;
		exit (1) ;
		} ;

	/* Now write some frames. */
	frames = ARRAY_LEN (buffer) / sfinfo.channels ;

	for (k = 0 ; k < 6 ; k++)
	{	test_seek_or_die (outfile, k * frames, SEEK_SET, k * frames, sfinfo.channels, __LINE__) ;
		test_seek_or_die (outfile, 0, SEEK_END, k * frames, sfinfo.channels, __LINE__) ;

		/* Open file again and make sure no errors in log buffer. */
		infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, __LINE__) ;
		check_log_buffer_or_die (infile, __LINE__) ;
		sf_close (infile) ;

		if (sfinfo.frames != k * frames)
		{	printf ("\n\nLine %d : Incorrect sample count (%ld should be %ld)\n", __LINE__, SF_COUNT_TO_LONG (sfinfo.frames), SF_COUNT_TO_LONG (k + frames)) ;
			dump_log_buffer (infile) ;
			exit (1) ;
			} ;

		if ((k & 1) == 0)
			test_write_double_or_die (outfile, k, buffer, sfinfo.channels * frames, __LINE__) ;
		else
			test_writef_double_or_die (outfile, k, buffer, frames, __LINE__) ;
		} ;

	sf_close (outfile) ;
	unlink (filename) ;

	puts ("ok") ;
	return ;
} /* update_seek_double_test */






static void
extra_header_test (const char *filename, int filetype)
{	SNDFILE *outfile, *infile ;
	SF_INFO sfinfo ;
    sf_count_t frames ;
    short buffer [8] ;
	int k = 0 ;

	print_test_name ("extra_header_test", filename) ;

	sfinfo.samplerate = 44100 ;
	sfinfo.format = (filetype | SF_FORMAT_PCM_16) ;
	sfinfo.channels = 1 ;

	memset (buffer, 0xA0, sizeof (buffer)) ;

	/* Now write some frames. */
	frames = ARRAY_LEN (buffer) / sfinfo.channels ;

	/* Test the file with extra header data. */
	outfile = test_open_file_or_die (filename, SFM_WRITE, &sfinfo, 399) ;
	sf_set_string (outfile, SF_STR_TITLE, filename) ;
	test_writef_short_or_die (outfile, k, buffer, frames, 401) ;
	sf_set_string (outfile, SF_STR_COPYRIGHT, "(c) 1980 Erik") ;
	sf_close (outfile) ;

#if 1
	/*
	**  Erik de Castro Lopo <erikd@mega-nerd.com> May 23 2004.
	**
	** This file has extra string data in the header and therefore cannot
	** currently be opened in SFM_RDWR mode. This is fixable, but its in
	** a part of the code I don't want to fiddle with until the Ogg/Vorbis
	** integration is done.
	*/

	if ((infile = sf_open (filename, SFM_RDWR, &sfinfo)) != NULL)
	{	printf ("\n\nError : should not be able to open this file in SFM_RDWR.\n\n") ;
		exit (1) ;
		} ;

	unlink (filename) ;
	puts ("ok") ;
	return ;
#else

	hexdump_file (filename, 0, 100000) ;

	/* Open again for read/write. */
	outfile = test_open_file_or_die (filename, SFM_RDWR, &sfinfo, 428) ;

	/*
	** In auto header update mode, seeking to the end of the file with
    ** SEEK_SET will fail from the 2nd seek on.  seeking to 0, SEEK_END
	** will seek to 0 anyway
	*/
	if (sf_command (outfile, SFC_SET_UPDATE_HEADER_AUTO, NULL, SF_TRUE) == 0)
    {	printf ("\n\nError : sf_command (SFC_SET_UPDATE_HEADER_AUTO) return error : %s\n\n", sf_strerror (outfile)) ;
		exit (1) ;
		} ;

	/* Now write some frames. */
	frames = ARRAY_LEN (buffer) / sfinfo.channels ;

	for (k = 1 ; k < 6 ; k++)
	{
		printf ("\n*** pass %d\n", k) ;
		memset (buffer, 0xA0 + k, sizeof (buffer)) ;


		test_seek_or_die (outfile, k * frames, SEEK_SET, k * frames, sfinfo.channels, 449) ;
		test_seek_or_die (outfile, 0, SEEK_END, k * frames, sfinfo.channels, 450) ;

		/* Open file again and make sure no errors in log buffer. */
		if (0)
		{	infile = test_open_file_or_die (filename, SFM_READ, &sfinfo, 454) ;
			check_log_buffer_or_die (infile, 455) ;
			sf_close (infile) ;
			} ;

		if (sfinfo.frames != k * frames)
		{	printf ("\n\nLine %d : Incorrect sample count (%ld should be %ld)\n", 460, SF_COUNT_TO_LONG (sfinfo.frames), SF_COUNT_TO_LONG (k + frames)) ;
			dump_log_buffer (infile) ;
			exit (1) ;
			} ;

		if ((k & 1) == 0)
			test_write_short_or_die (outfile, k, buffer, sfinfo.channels * frames, 466) ;
		else
			test_writef_short_or_die (outfile, k, buffer, frames, 468) ;
		hexdump_file (filename, 0, 100000) ;
		} ;

	sf_close (outfile) ;
	unlink (filename) ;

	puts ("ok") ;
	return ;
#endif
} /* extra_header_test */

