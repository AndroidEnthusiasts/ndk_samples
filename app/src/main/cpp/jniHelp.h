//
// Created by Jesson on 3/3/21.
//

#ifndef JNI_HELPER_JNIHELP_H
#define JNI_HELPER_JNIHELP_H

#include <jni.h>
#include <stdio.h>
#include <android/log.h>

#define LOG_TAG "JNILog"
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)




#endif //JNI_HELPER_JNIHELP_H
