//==============================================================================
#ifndef _CAMADASONORA_H_
    #define _CAMADASONORA_H_

#include <SDL/SDL_mixer.h>
#include "Musica.h"
#include "Som.h"
//==============================================================================
class PrincipalAudio{

      private:

             int amostrAudio;
	         int canaisAudio;
	         int bufferAudio;
   	         Uint16 formatoAudio;

   	         int pistas;

      public:
            PrincipalAudio();
            ~PrincipalAudio();

            int getAmostrAudio();
            int getCanaisAudio();
            int getBufferAudio();
            Uint16 getFormatoAudio();

            void iniciaAudio();

            void setCanaisAudio(int canal);
            void setAmostrAudio(int amostra);
            void setBufferAudio(int tamBufferAudio);


};
//==============================================================================

#endif
