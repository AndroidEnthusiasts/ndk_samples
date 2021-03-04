//
// Created by Jesson on 3/3/21.
//

#ifndef JNI_HELPER_JNILOCALREF_H
#define JNI_HELPER_JNILOCALREF_H

#include <cstdio>
#include <jni.h>
#include "JavaThreadUtils.h"

namespace jni {
    template<typename JniType>
    class JniLocalRef {
    public:
        JniLocalRef() : _obj(NULL) {}
        JniLocalRef(JniType obj) : _obj(NULL) { set(obj); }
        JniLocalRef(const JniLocalRef<JniType> &ref) : _obj(NULL) {
            if (ref.get()) {
                JNIEnv *env = JavaThreadUtils::getEnvForCurrentThread();
                set(env ? (JniType)env->NewLocalRef(ref.get()): NULL);
            }
        }

        ~JniLocalRef() { set(NULL); }

        JniType get() const { return _obj; }
        void set(JniType obj) {
            if (_obj) {
                JNIEnv *env = JavaThreadUtils::getEnvForCurrentThread();
                if (env) env->DeleteLocalRef(_obj);
            }
            _obj = obj;
        }

        JniType leak() {
            JniType obj = _obj;
            _obj = NULL;
            return obj;
        }

        operator JniType() const { return _obj; }

        void operator=(JniType obj) { set(obj); }
        void operator=(const JniLocalRef<JniType> &ref) {
            if (ref.get()) {
                JNIEnv *env = JavaThreadUtils::getEnvForCurrentThread();
                set(env ? (JniType)env->NewLocalRef(ref.get()) : NULL);
            }
            else {
                set(NULL);
            }
        }

    private:
        JniType _obj;
    };
}


#endif //JNI_HELPER_JNILOCALREF_H
