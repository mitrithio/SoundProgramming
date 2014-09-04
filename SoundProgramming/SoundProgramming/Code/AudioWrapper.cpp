#include "AudioWrapper.h"
#include "Framework\Framework.h"

AudioWrapper::AudioWrapper()
{
}

AudioWrapper::~AudioWrapper()
{
	UnloadResources();
}

ALboolean AudioWrapper::InitFramework()
{
	ALFWInit();

	if ( !ALFWInitOpenAL() )
	{
		ALFWShutdown();
		return false;
	}

	return true;
}

const ALuint& AudioWrapper::GenerateBuffer()
{
	alGenBuffers( 1, &m_uiBuffer );
	return m_uiBuffer;
}

const ALuint& AudioWrapper::GenerateSource()
{
	alGenSources( 1, &m_uiSource );
	return m_uiSource;
}

void AudioWrapper::AttachSourceToBuffer( unsigned int i_uiSource, unsigned int i_uiBuffer )
{
	alSourcei( i_uiSource, AL_BUFFER, i_uiBuffer );
}

bool AudioWrapper::LoadStatic( const char* i_szFilePath, unsigned int i_uiSource )
{
	return LoadMediaAudio( i_szFilePath, i_uiSource );
}

bool AudioWrapper::LoadForEffects( const char* i_szFilePath, unsigned int i_uiSource )
{
	bool bReturn = LoadMediaAudio( i_szFilePath, i_uiSource );
	if ( bReturn )
	{
		SetupNonStaticSource( i_uiSource );
	}

	return bReturn;
}

int AudioWrapper::GetSourceState()
{
	alGetSourcei( m_uiSource, AL_SOURCE_STATE, &m_iState);
	return m_iState;
}

void AudioWrapper::UnloadResources()
{
	alSourceStop(m_uiSource);
	alDeleteSources(1, &m_uiSource);
	alDeleteBuffers(1, &m_uiBuffer);

	ALFWShutdownOpenAL();

	ALFWShutdown();
}

void AudioWrapper::Play( unsigned int i_uiSource )
{
	alSourcePlay( i_uiSource );
}

void AudioWrapper::Pause( unsigned int i_uiSource )
{
	alSourcePause( i_uiSource );
}

void AudioWrapper::Stop( unsigned int i_uiSource )
{
	alSourceStop( i_uiSource );
}

void AudioWrapper::SetupNonStaticSource( unsigned int i_uiSource )
{
	alSourcei( i_uiSource, AL_SOURCE_RELATIVE, AL_TRUE );
	alSource3f( i_uiSource, AL_POSITION, 0.0f, -1.0f, 0.0f );
	alSourcef( i_uiSource, AL_GAIN, 1.0 );
}

bool AudioWrapper::LoadMediaAudio( const char* i_szFilePath, unsigned int i_uiBuffer )
{

	if (!ALFWLoadWaveToBuffer( (char*)ALFWaddMediaPath( i_szFilePath ), i_uiBuffer ))
	{
		alDeleteBuffers(1, &i_uiBuffer);
		ALFWShutdownOpenAL();
		ALFWShutdown();
		return false;
	}
	return true;
}
