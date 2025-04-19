#include <change_c_pointer.h>
#include <stdio.h>
#include <stdlib.h>

MyData *data = NULL;

JNIEXPORT void JNICALL Java_com_gix_change_1c_1pointer_App_createMyData(JNIEnv *env, jobject thiz) {
    printf("create data\n");
    data = malloc(sizeof(MyData));
    data->name = malloc(sizeof(char) * 4);
    data->name = "Gix";
    data->age = 21;
    data->grade = 6;

    printf("set data address: %p to kotlin\n", data);

    // get class
    jclass clazz = (*env)->GetObjectClass(env, thiz);

    // get method
    jmethodID get_address = (*env)->GetMethodID(env, clazz, "setAddressPtr", "(J)V");

    // call method
    (*env)->CallVoidMethod(env, thiz, get_address, (long)data);
}

JNIEXPORT void JNICALL Java_com_gix_change_1c_1pointer_App_doubleGrade(JNIEnv *env, jobject thiz, jlong my_data_address) {
    printf("get data address: %p from kotlin\n", my_data_address);
    MyData *data_from_java = (void *)my_data_address;
    printf("data before:\n");
    printf("\t name: %s\n", data_from_java->name);
    printf("\t age: %u\n", data_from_java->age);
    printf("\t grade: %u\n", data_from_java->grade);

    printf("\ndouble the age of data\n\n");
    data->grade *= 2;

    printf("data after:\n");
    printf("\t name: %s\n", data_from_java->name);
    printf("\t age: %u\n", data_from_java->age);
    printf("\t grade: %u\n", data_from_java->grade);
}