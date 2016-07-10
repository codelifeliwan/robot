#include "robot_speaker.h"

/**
 * 无参数初始化扬声器
 */
snd_pcm_t* init_speaker(){
    speaker_params* param = get_default_speaker_params();

    snd_pcm_t* playback_handle = init_speaker_with_param(param);
    release_speaker_params(param);

    return playback_handle;
}

/**
 * 带参数初始化扬声器
 */
snd_pcm_t* init_speaker_with_param(speaker_params* param){
    snd_pcm_t *playback_handle;
    snd_pcm_hw_params_t *hw_params;
    int err;

    if(param == NULL){
        return NULL:
    }

    //打开PCM音频设备
    if ((err = snd_pcm_open (&playback_handle, param->device,param->pcm_stream, param->open_mode)) < 0) {
        fprintf (stderr, "cannot open audio device %s (%s)\n",param->device,snd_strerror (err));
        exit (1);
    }

    //分配snd_pcm_hw_params_t(hw_params)结构空间
    if ((err = snd_pcm_hw_params_malloc (&hw_params)) < 0) {
        fprintf (stderr, "cannot allocate hardware parameter structure (%s)\n",snd_strerror (err));
        exit (1);
    }

    //初始化hw_params,即初始化硬件播放参数
    if ((err = snd_pcm_hw_params_any (playback_handle, hw_params)) < 0) {
        fprintf (stderr, "cannot initialize hardware parameter structure (%s)\n",snd_strerror (err));
        exit (1);
    }

    //设置访问类型,SND_PCM_ACCESS_RW_INTERLEAVED:交错访问,在缓冲区的每个 PCM 帧都包含所有设置的声道的连续的采样数据。
    //比如声卡要播放采样长度是 16-bit 的 PCM 立体声数据，表示每个 PCM 帧中有 16-bit 的左声道数据，
    //然后是 16-bit 右声道数据

    //SND_PCM_ACCESS_RW_NONINTERLEAVED :非交错访问。每个 PCM 帧只是一个声道需要的数据，
    //如果使用多个声道，那么第一帧是第一个声道的数据，第二帧是第二个声道的数据，依此类推
    if ((err = snd_pcm_hw_params_set_access (playback_handle, hw_params, param->access_type)) < 0) {
        fprintf (stderr, "cannot set access type (%s)\n",snd_strerror (err));
        exit (1);
    }

    //设置数据格式，主要控制输入的音频数据的类型、无符号还是有符号、是 little-endian 还是 bit-endian
    if ((err = snd_pcm_hw_params_set_format (playback_handle, hw_params, param->data_format)) < 0) {
        fprintf (stderr, "cannot set sample format (%s)\n",snd_strerror (err));
        exit (1);
    }

    //设置音频数据的最接近目标的采样率
    if ((err = snd_pcm_hw_params_set_rate_near (playback_handle, hw_params, param->rate, param->dir)) < 0) {
        fprintf (stderr, "cannot set sample rate (%s)\n",snd_strerror (err));
        exit (1);
    }

    //设置音频设备的声道，常见的就是单声道和立体声，如果是立体声，设置最后一个参数为2
    if ((err = snd_pcm_hw_params_set_channels (playback_handle, hw_params, param->channel)) < 0) {
        fprintf (stderr, "cannot set channel count (%s)\n",snd_strerror (err));
        exit (1);
    }

    //从设备配置空间选择一个配置，让函数 snd_pcm_prepare() 准备好 PCM 设备，以便写入 PCM 数据
    if ((err = snd_pcm_hw_params (playback_handle, hw_params)) < 0) {
        fprintf (stderr, "cannot set parameters (%s)\n",snd_strerror (err));
        exit (1);
    }

    snd_pcm_hw_params_free (hw_params);//释放硬件配置结构所占空间

    //准备好PCM设备，以便写入PCM数据
    if ((err = snd_pcm_prepare (playback_handle)) < 0) {
        fprintf (stderr, "cannot prepare audio interface for use (%s)\n",snd_strerror (err));
        exit (1);
    }

    return playback_handle;
}

/**
 * 播放缓冲数据
 */
void play_speaker_buffer(snd_pcm_t *playback_handle, void *buffer, int size){
    int err;
    if((err = snd_pcm_writei(playback_handle,buffer,size)) != size){
            fprintf (stderr, "write to audio interface failed (%s)\n", snd_strerror (err));
            exit (1);
    }
}

 /**
  * 关闭音频设备
  */
void close_speaker(snd_pcm_t *playback_handle){
    snd_pcm_close(playback_handle);
}