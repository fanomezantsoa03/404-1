#include "../../inc/fahaleovantena.h"

void play_audio(const char *file)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf("Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_AudioSpec wav_spec;
    Uint32 wav_length;
    Uint8 *wav_buffer;
    if (SDL_LoadWAV(file, &wav_spec, &wav_buffer, &wav_length) == NULL)
    {
        printf("Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    if (SDL_OpenAudio(&wav_spec, NULL) < 0)
    {
        printf("Error: %s\n", SDL_GetError());
        SDL_FreeWAV(wav_buffer);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    SDL_PauseAudio(0);
    SDL_QueueAudio(1, wav_buffer, wav_length);
    while (SDL_GetQueuedAudioSize(1) > 0)
    {
        SDL_Delay(100);
    }
    SDL_CloseAudio();
    SDL_FreeWAV(wav_buffer);
    SDL_Quit();
}