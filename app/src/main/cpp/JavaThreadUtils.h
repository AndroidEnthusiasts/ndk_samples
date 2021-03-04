//
// Created by Jesson on 3/3/21.
//

#ifndef JNI_HELPER_JAVATHREADUTILS_H
#define JNI_HELPER_JAVATHREADUTILS_H


#include <string>
#include <jni.h>

namespace jni{
    class JavaThreadUtils {
    private:
        JavaThreadUtils(){}
        JavaThreadUtils(const JavaThreadUtils&){}
        virtual ~JavaThreadUtils(){}

    public:
        static JNIEXPORT JavaVM* getJavaVM();
        static JNIEXPORT JNIEnv* initialize(JavaVM* jvm);
        static JNIEXPORT JNIEnv* getEnvForCurrentThread();
        static JNIEXPORT JNIEnv* getEnvForCurrentThread(JavaVM *jvm);
        static JNIEXPORT JNIEnv* attachCurrentThreadToJVM(const char* thread_name);
        static JNIEXPORT JNIEnv* attachCurrentThreadAsDaemonToJVM(const char* thread_name);
        static JNIEXPORT void detatchCurrentThreadFromJVM();
    };



}





#endif //JNI_HELPER_JAVATHREADUTILS_H
