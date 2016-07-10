#include <stdlib.h>
#include "robot_ears.h"

typedef struct _ear_params{
    char *device = "default";//设备号
    snd_pcm_stream_t pcm_stream = SND_PCM_STREAM_CAPTURE;
    int open_mode=0;//打开模式
    snd_pcm_access_t access_type = SND_PCM_ACCESS_RW_INTERLEAVED ;//访问类型，默认为交错访问
    snd_pcm_format_t data_format = SND_PCM_FORMAT_S16_LE;//数据格式
    unsigned int channel = 2;//声道个数
    unsigned int rate = 44100;//采样频率
    int dir = 0;//near的最后一个参数
}ear_params;


/**
 * 默认的录音机参数
 */
ear_params* get_default_ear_params(){
    ear_params *param=(ear_params*)(malloc(sizeof(ear_params)));
    param->device="default";
    param->pcm_stream=SND_PCM_STREAM_PLAYBACK;
    param->open_mode=0;
    param->access_type=SND_PCM_ACCESS_RW_INTERLEAVED;
    param->data_format=SND_PCM_FORMAT_S16_LE;
    param->channel=2;
    param->rate=44100;
    param->dir=0;
    return param;
}

void release_ear_params(ear_params *param){
    if(param != NULL){
        free(param);
    }
}

void set_ear_device_param(ear_params *param,char *device){
    param->device=device;
}

void set_ear_stream_param(ear_params *param,snd_pcm_stream_t stream){
    param->pcm_stream = stream;
}

void set_ear_open_mode_param(ear_params *param,int open_mode){
    param->open_mode=open_mode;
}

void set_ear_access_param(ear_params *param,snd_pcm_access_t access_type){
    param->access_type=access_type;
}

void set_ear_data_format_param(ear_params *param,snd_pcm_format_t data_format){
    param->data_format=data_format;
}

void set_ear_channel_param(ear_params *param,unsigned int channel){
    param->channel=channel;
}

void set_ear_rate_param(ear_params *param,unsigned int rate){
    param->rate=rate;
}

void set_ear_dir_param(ear_params *param,int dir){
    param->dir=dir;
}