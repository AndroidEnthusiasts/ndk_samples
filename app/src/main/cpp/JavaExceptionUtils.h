//
// Created by Jesson on 3/3/21.
//

#ifndef JNI_HELPER_JAVAEXCEPTIONUTILS_H
#define JNI_HELPER_JAVAEXCEPTIONUTILS_H


#include "jni.h"
#include "JniLocalRef.h"

namespace jni {

    class JavaExceptionUtils {
    private:
        JavaExceptionUtils() {}
        JavaExceptionUtils(const JavaExceptionUtils&) {}
        virtual ~JavaExceptionUtils() {}

    public:
        static JNIEXPORT JniLocalRef<jobject> newThrowable(JNIEnv *env, const char *message, ...);

        static JNIEXPORT void checkException(JNIEnv *env);
        static JNIEXPORT void checkExceptionAndClear(JNIEnv *env);
        static JNIEXPORT void throwException(JNIEnv *env, const char *message, ...);
        static JNIEXPORT void throwRuntimeException(JNIEnv *env, const char *message, ...);
        static JNIEXPORT void throwExceptionOfType(JNIEnv *env, const char *exception_class_name, const char *message, ...);

    protected:
        static JNIEXPORT void throwExceptionOfType(JNIEnv *env, const char *exception_class_name, const char *message, va_list arguments);
    };
}


#endif //JNI_HELPER_JAVAEXCEPTIONUTILS_H
