#include <change_c_pointer.h>
#include <stdio.h>
#include <stdlib.h>

JNIEXPORT void JNICALL Java_com_gix_change_1c_1pointer_App_cMain(JNIEnv *env, jobject thiz) {
    printf("create data\n");
    Student *student = malloc(sizeof(Student));
    student->name = malloc(sizeof(char) * 4);
    student->name = "Gix";
    student->age = 21;
    student->grade = 6;
    student->life = 1;

    printf("set data address: %p to kotlin\n", student);

    // get class
    jclass clazz = (*env)->GetObjectClass(env, thiz);

    // get method
    jmethodID get_address = (*env)->GetMethodID(env, clazz, "setAddressPtr", "(J)V");

    // call method
    (*env)->CallVoidMethod(env, thiz, get_address, (long)student);

    printf("start native loop\n");
    while (student->life) {
        printf("%s is life and learnig...\n", student->name);
    }
    printf("end native loop\n");
}

JNIEXPORT void JNICALL Java_com_gix_change_1c_1pointer_App_doubleGrade(JNIEnv *env, jobject thiz, jlong my_data_address) {
    printf("get data address: %p from kotlin\n", my_data_address);
    Student *data_from_java = (void *)my_data_address;
    printf("data before:\n");
    printf("\t name: %s\n", data_from_java->name);
    printf("\t age: %u\n", data_from_java->age);
    printf("\t grade: %u\n", data_from_java->grade);

    printf("\ndouble the age of data\n\n");
    data_from_java->grade *= 2;

    printf("data after:\n");
    printf("\t name: %s\n", data_from_java->name);
    printf("\t age: %u\n", data_from_java->age);
    printf("\t grade: %u\n", data_from_java->grade);
}

JNIEXPORT void JNICALL Java_com_gix_change_1c_1pointer_App_turnOff(JNIEnv *env, jobject thiz, jlong my_data_address) {
    printf("get data address: %p from kotlin\n", my_data_address);
    Student *data_from_java = (void *)my_data_address;
    printf("data before:\n");
    printf("\t name: %s\n", data_from_java->name);
    printf("\t age: %u\n", data_from_java->age);
    printf("\t grade: %u\n", data_from_java->grade);

    printf("\nTurn off student\n\n");
    data_from_java->life = 0;

    printf("data after:\n");
    printf("\t name: %s\n", data_from_java->name);
    printf("\t age: %u\n", data_from_java->age);
    printf("\t grade: %u\n", data_from_java->grade);
}
