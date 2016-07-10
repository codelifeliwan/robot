#ifndef ROBOT_ROBOT_EARS_H
#define ROBOT_ROBOT_EARS_H

#include <alsa/asoundlib.h>

ear_params* get_default_ear_params();
void release_ear_params(ear_params *param);
void set_ear_device_param(ear_params *param,char *device);
void set_ear_stream_param(ear_params *param,snd_pcm_stream_t stream);
void set_ear_open_mode_param(ear_params *param,int open_mode);
void set_ear_access_param(ear_params *param,snd_pcm_access_t access_type);
void set_ear_data_format_param(ear_params *param,snd_pcm_format_t data_format);
void set_ear_channel_param(ear_params *param,unsigned int channel);
void set_ear_rate_param(ear_params *param,unsigned int rate);
void set_ear_dir_param(ear_params *param,int dir);

snd_pcm_t* init_ear();
snd_pcm_t* init_ear_with_param(ear_params* param);
void recode_to_buffer(snd_pcm_t *playback_handle, void *buffer, int size);
void close_ear(snd_pcm_t *playback_handle);

#endif