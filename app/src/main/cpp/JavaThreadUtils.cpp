//
// Created by Jesson on 3/3/21.
//

#include "JavaThreadUtils.h"
#include "JavaExceptionUtils.h"

#include <sstream>
#include <cstdarg>


namespace jni {
    static JavaVM* sJavaVm = NULL;

    JNIEnv* JavaThreadUtils::initialize(JavaVM *jvm) {
        sJavaVm = jvm;
        return getEnvForCurrentThread(jvm);
    }

    JavaVM* JavaThreadUtils::getJavaVM() {
        return sJavaVm;
    }

    JNIEnv* JavaThreadUtils::getEnvForCurrentThread() {
        return getEnvForCurrentThread(sJavaVm);
    }

    JNIEnv* JavaThreadUtils::getEnvForCurrentThread(JavaVM *jvm) {
        JNIEnv *env;

        if (jvm == nullptr) {
            return nullptr;
        } else if (jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
            return nullptr;
        }

        return env;
    }

    JNIEnv* JavaThreadUtils::attachCurrentThreadToJVM(const char* thread_name) {
        JNIEnv *env;
        JavaVMAttachArgs args;
        int result = -1;

        args.version = JNI_VERSION_1_6;
        args.name = const_cast<char *>(thread_name);
        args.group = nullptr;

        result = sJavaVm->AttachCurrentThread(&env, &args);

        if (result != JNI_OK) {
           // JavaExceptionUtils::throwRuntimeException(env, "Could not attach thread %s to JVM", thread_name);
            return nullptr;
        }
    }

    JNIEnv* JavaThreadUtils::attachCurrentThreadAsDaemonToJVM(const char* thread_name) {
        JNIEnv *env;
        JavaVMAttachArgs args;
        int result = -1;

        args.version = JNI_VERSION_1_6;
        args.name = const_cast<char*>(thread_name);
        args.group = nullptr;

#ifdef ANDROID
        result = sJavaVm->AttachCurrentThreadAsDaemon(&env, &args);
#else
        result = sJavaVm->AttachCurrentThreadAsDaemon((JNIEnv**)(&env), &args);
#endif
        if (result != JNI_OK) {
            //JavaExceptionUtils::throwRuntimeException(env, "Could not attach daemon thread %s to JVM", thread_name);
            return nullptr;
        }

        return env;
    }
}