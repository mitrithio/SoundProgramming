#pragma once
#include "al.h"

class AudioWrapper
{
public:
	AudioWrapper();
	~AudioWrapper();

	ALboolean InitFramework();
	const ALuint& GenerateBuffer();
	const ALuint& GenerateSource();
	void AttachSourceToBuffer( unsigned int i_uiSource, unsigned int i_uiBuffer );
	bool LoadStatic( const char* i_szFilePath, unsigned int i_uiSource );
	bool LoadForEffects( const char* i_szFilePath, unsigned int i_uiSource );
	int GetSourceState();
	void UnloadResources();
	void Play( unsigned int i_uiSource );
	void Pause( unsigned int i_uiSource );
	void Stop( unsigned int i_uiSource );

private:
	bool LoadMediaAudio( const char* i_szFilePath, unsigned int i_uiBuffer );
	void SetupNonStaticSource( unsigned int i_uiSource );

private:
	ALuint      m_uiBuffer;
	ALuint      m_uiSource; 
	ALint       m_iState;

};