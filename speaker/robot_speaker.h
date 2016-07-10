#ifndef ROBOT_ROBOT_SPEAKER_H
#define ROBOT_ROBOT_SPEAKER_H

#include <alsa/asoundlib.h>

speaker_params* get_default_speaker_params();
void release_speaker_params(speaker_params *param);
void set_speaker_device_param(speaker_params *param,char *device);
void set_speaker_stream_param(speaker_params *param,snd_pcm_stream_t stream);
void set_speaker_open_mode_param(speaker_params *param,int open_mode);
void set_speaker_access_param(speaker_params *param,snd_pcm_access_t access_type);
void set_speaker_data_format_param(speaker_params *param,snd_pcm_format_t data_format);
void set_speaker_channel_param(speaker_params *param,unsigned int channel);
void set_speaker_rate_param(speaker_params *param,unsigned int rate);
void set_speaker_dir_param(speaker_params *param,int dir);

/**
 * 播放器操作相关
 */
snd_pcm_t* init_speaker();
snd_pcm_t* init_speaker_with_param(speaker_params* param);
void play_speaker_buffer(snd_pcm_t *playback_handle, void *buffer, int size);
void close_speaker(snd_pcm_t *playback_handle);

#endif