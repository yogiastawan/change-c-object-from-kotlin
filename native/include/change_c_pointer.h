
#ifndef __CHANGE_C_POINTER_H__
#define __CHANGE_C_POINTER_H__

#include <jni.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _MyData {
    char *name;
    uint8_t age;
    uint8_t grade;
} MyData;

JNIEXPORT void JNICALL Java_com_gix_change_1c_1pointer_App_createMyData(JNIEnv *env, jobject thiz);
JNIEXPORT void JNICALL Java_com_gix_change_1c_1pointer_App_doubleGrade(JNIEnv *env, jobject thiz, jlong my_data_address);

#ifdef __cplusplus
}
#endif

#endif /* __CHANGE_C_POINTER_H__ */
