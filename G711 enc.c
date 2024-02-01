/*#include "esp_g711_enc.h"
#include "esp_audio_enc_def.h"
#include "esp_audio_def.h"
// This is an example of using a simple encoder interface to encode audio.
void aac_encoder_test(void)
{
    esp_audio_err_t ret;
   /void *enc_handle = NULL;
    FILE *in_file = NULL;
    FILE *out_file = NULL;
    uint8_t *inbuf = NULL; 
    uint8_t *outbuf = NULL;
    int in_read = 0;
    int in_frame_size = 0;
    int out_frame_size = 0;
    int times = 0;
    // Open stream
    // User need to initialize sdcard module before
    in_file = fopen("/sdcard/pcm/thetest8_1.pcm", "rb");
    if (in_file == NULL) {
        printf("in_file open failed\n");
        goto audio_encoder_exit;
    }
    out_file = fopen("/sdcard/out_music/thetest1.aac", "w+");
    if (out_file == NULL) {
        printf("out_file open failed\n");
        goto audio_encoder_exit;
    }
    // Set configuration
    esp_g711_enc_config_t config = ESP_G711_ENC_CONFIG_DEFAULT();
    config.sample_rate = 8000;
    config.channel = 1;
    config.bitrate = 90000;
    config.adts_used = 1;
    // Create encoder handle
    ret = esp_aac_enc_open(&config, sizeof(esp_g711_enc_config_t), &enc_handle);
    if (ret != 0) {
        printf("Fail to create encoder handle.");
        goto audio_encoder_exit;
    }
    // Get in/out buffer size and malloc in/out buffer
    ret = esp_aac_enc_get_frame_size(enc_handle, &in_frame_size, &out_frame_size);
    times = 4;
    in_frame_size *= times;
    out_frame_size *= times;
    inbuf = calloc(1, in_frame_size);
    if (inbuf == NULL) {
        printf("inbuf malloc failed.\n");
        goto audio_encoder_exit;
    }
    outbuf = calloc(1, out_frame_size);
    if (outbuf == NULL) {
        printf("outbuf malloc failed.\n");
        goto audio_encoder_exit;
    }
    // Encode process
    esp_audio_enc_in_frame_t in_frame = { 0 };
    esp_audio_enc_out_frame_t out_frame = { 0 };
    in_frame.buffer = inbuf;
    in_frame.len = in_frame_size;
    out_frame.buffer = outbuf;
    out_frame.len = out_frame_size;
    while ((in_read = fread(inbuf, 1, in_frame_size, in_file)) > 0) {
        if (in_read < in_frame_size) {
            memset(inbuf + in_read, 0, in_frame_size - in_read);
        }
        ret = esp_aac_enc_process(enc_handle, &in_frame, &out_frame);
        if (ret != ESP_AUDIO_ERR_OK) {
            printf("audio encoder process failed.\n");
            goto audio_encoder_exit;
        }
        fwrite(outbuf, 1, out_frame.encoded_bytes, out_file);
    }
audio_encoder_exit:
    if (in_file) {
        fclose(in_file);
    }
    if (out_file) {
        fclose(out_file);
    }
    if (inbuf) {
        free(inbuf);
    }
    if (outbuf) {
        free(outbuf);
    }
    if (enc_handle) {
        esp_aac_enc_close(enc_handle);
    }
    return;
}
*/