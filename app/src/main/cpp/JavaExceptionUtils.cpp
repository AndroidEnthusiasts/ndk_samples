//
// Created by Jesson on 3/3/21.
//

#include "JavaExceptionUtils.h"
namespace jni {
    static const size_t kExceptionMaxLength = 512;

    void JavaExceptionUtils::checkException(JNIEnv *env) {
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
        }
    }

    void JavaExceptionUtils::checkExceptionAndClear(JNIEnv *env) {
        checkException(env);
        env->ExceptionClear();
    }

//    JniLocalRef<jobject> JavaExceptionUtils::newThrowable(JNIEnv *env, const char *message, ...) {
//        jclass throwableClazz = JavaClassUtils::findClass(env, kTypeJavaClass(Throwable), false);
//        if (throwableClazz == NULL) {
//            JavaExceptionUtils::throwRuntimeException(env, "Could not find class Throwable");
//            return NULL;
//        }
//        // Construct error message
//        va_list arguments;
//        va_start(arguments, message);
//        char formattedMessage[kExceptionMaxLength];
//        vsnprintf(formattedMessage, kExceptionMaxLength, message, arguments);
//        va_end(arguments);
//        std::string javaMessage(formattedMessage);
//        JniLocalRef<jobject> result = env->NewObject(throwableClazz, throwableCtor,javaMessage);
//        JavaExceptionUtils::checkException(env);
//        if (result == NULL) {
//            JavaExceptionUtils::throwRuntimeException(env,
//                                                      "Could not create new Throwable instance");
//            return NULL;
//        }
//
//        return result;
//    }

}