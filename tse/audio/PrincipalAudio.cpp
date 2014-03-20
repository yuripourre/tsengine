#include "PrincipalAudio.h"

PrincipalAudio::PrincipalAudio()
{

	amostrAudio = 44100;			//Frequencia do playback do audio
	canaisAudio = 2;				//2 canais = stereo
	bufferAudio = 4096;				//Tamanho do buffer de Audio na memória
	formatoAudio = AUDIO_S16SYS; 	//Formato do audio

	pistas = 16;

	iniciaAudio();

}
PrincipalAudio::~PrincipalAudio(void)
{
	Mix_CloseAudio();
}
void PrincipalAudio::iniciaAudio()
{

	if(Mix_OpenAudio(amostrAudio, formatoAudio, canaisAudio, bufferAudio) != 0)
	{
		//LOG
		//printf("Nao foi possivel iniciar o audio: %s\n", Mix_GetError());
		//exit(1);
	}
	//Levemente Bugado
	//if(Mix_AllocateChannels(pistas) != 0)
	//{
	//	printf("Nao foi possivel alocar as pistas: %s\n", Mix_GetError());
	//	exit(1);
	//}
	//Mix_Volume(1, 64);
	//Mix_Volume(2, 64);
	//Mix_Volume(3, 64);

}

