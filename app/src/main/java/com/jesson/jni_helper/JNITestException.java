package com.jesson.jni_helper;

import android.util.Log;

public class JNITestException {
    static {
        System.loadLibrary("native-lib");
    }

    //演示普通的写法 在jni内部给异常捕获
    public static native int jniDivide(int input1, int input2);

    public static native int jniDivide_AdvancedWriting(int input1, int input2);

    public static int callJniDivide(int input1, int input2) {
        try {
            return jniDivide_AdvancedWriting(input1, input2);
        } catch (Exception e) {
            Log.e("JniExceptionHandler", e.toString());
            return -1;
        }
    }




}
