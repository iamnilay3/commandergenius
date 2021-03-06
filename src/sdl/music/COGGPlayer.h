/*
 * COGGPlayer.h
 *
 *  Created on: 17.02.2011
 *      Author: gerstrong
 */

#ifndef COGGPLAYER_H_
#define COGGPLAYER_H_

#if defined(OGG) || defined(TREMOR)

#include <cstdio>
#include <iostream>

#include "sdl/music/CMusicPlayer.h"

#ifdef OGG
#include <vorbisfile.h>
#elif defined  TREMOR
#include <ivorbisfile.h>
#endif

#include <SDL.h>
#include <string>

class COGGPlayer : public CMusicPlayer {
public:
	COGGPlayer(const std::string& filename, const SDL_AudioSpec& AudioSpec);
	virtual ~COGGPlayer();

	bool open();
	void readBuffer(Uint8* buffer, Uint32 length);
	void close();

private:
	bool readOGGStream( OggVorbis_File  &oggStream, char *buffer, const size_t &size, const SDL_AudioSpec &OGGAudioSpec );
	bool readOGGStreamAndResample( OggVorbis_File  &oggStream, char *buffer, const size_t output_size, const size_t input_size, const SDL_AudioSpec &OGGAudioSpec );

	OggVorbis_File  m_oggStream;
	const std::string m_filename;
	const SDL_AudioSpec &m_AudioSpec;
	SDL_AudioSpec m_AudioFileSpec;
	SDL_AudioCVT m_Audio_cvt;
	Uint32 m_pcm_size;
	Uint32 m_music_pos;
	bool m_reading_stream;
	int m_bitStream;
};

#if defined(TREMOR)
int ov_fopen(char *path,OggVorbis_File *vf);
#endif

#endif

#endif /* COGGPLAYER_H_ */
