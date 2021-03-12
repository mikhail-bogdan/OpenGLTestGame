#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>

#pragma pack(1)

#define NO_ERRORS					0
#define ILLEGAL_HEADER				1
#define ILLEGAL_FORMAT				2
#define FILE_READ_ERROR				3
#define INPUT_FILE_OPEN_ERROR		4
#define INPUT_FILE_NOT_FOUND		5
#define OUTPUT_FILE_OPEN_ERROR		6
#define FILE_WRITE_ERROR			7
#define MEMORY_ALLOC_ERROR			8
#define BUFFER_OVERFLOW_ERROR		9

#define MAXHDRLEN			1000


typedef unsigned short word;
typedef unsigned long dword;

struct Wave_Header
{
	/*  ������������ RIFF  */
	byte	riff[4];		// ��� ������ ���� ����� RIFF
	dword	riffsize;		// ������ ����� - 8

	/* ������������ FORMAT, ��������� ������ WAV �����  */
	byte	wawefmt[8];			// ��� ������ ���� ����� "WAVEfmt "
	dword	fmtsize;			// ������ ������������ FORMAT - ����� ���� ������ 16 ��� 18
								// ��� ������������ ��������� WAV ���������� �������� 16
	word	wFormatTag;			// ������ ����� , ��� ���������� ������ WAVE_FORMAT_PCM ( == 1 )
	word	nChannels;			// ����� ������� ( 1 ��� 2 )
	dword	nSamplesPerSec;		// ����� �������� � ������� ( 8000, 11025, 22050 ��� 44100 )
	dword	nAvgBytesPerSec;	// ����� ���� � �������. 
	word	nBlockAlign;		// ������������ ����� ������
	short	wBitsPerSample;		// ����� ��� �� ������ ( 8 ��� 16 )
};

struct Data_Chunk
{
	byte	data[4];
	dword	datasize;
	void* samples;
};

dword load_wav_file(std::string filename, Wave_Header* wav_hdr, Data_Chunk* data_chunk);

dword read_wave_header(FILE* file, Wave_Header* wav_hdr);

dword read_data_chunk(FILE* file, Data_Chunk* dat_hdr);

dword process_wav_file(Wave_Header* wav_hdr, Data_Chunk* data_chunk, int first, int last);

dword save_wav_file(std::string filename, Wave_Header* wav_hdr, Data_Chunk* data_chunk);

