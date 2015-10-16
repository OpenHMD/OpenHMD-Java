#include <jni.h>
#include "OpenHMD-Java.h"
#include "openhmd.h"

JNIEXPORT jlong JNICALL Java_OpenHMD_ohmd_ctx_create(JNIEnv* env, jobject obj);
{
	//Create the context and pass pointer as long to Java
	ohmd_context* ctx = ohmd_ctx_create();
	
	return (long)ctx;
}

JNIEXPORT void JNICALL Java_ohmd_ctx_destroy(JNIEnv* env, jobject obj, jlong context);
{
	//Destroy the context
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_ctx_destroy(ctx);
}

JNIEXPORT jstring JNICALL Java_OpenHMD_OpenHMD_ohmd_ctx_get_error(JNIEnv* env, jobject obj, jlong context);
{
	//Call get_error and return the error code
	ohmd_context* ctx = (ohmd_context*)context;
	const char* cerror = ohmd_ctx_get_error(ctx);
	jstring error;

	error = (*env)->NewStringUTF(env,cerror);

	return error;
}

JNIEXPORT void JNICALL Java_OpenHMD_ohmd_ctx_update(JNIEnv* env, jobject obj, jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_ctx_update(ctx);
}

JNIEXPORT jint JNICALL Java_OpenHMD_ohmd_ctx_probe(JNIEnv* env, jobject obj, jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	
	return ohmd_ctx_probe(ctx);
}

JNIEXPORT jstring JNICALL Java_OpenHMD_ohmd_list_gets(JNIEnv* env, jobject obj, jlong context, jint index, jint type);
{
	ohmd_context* ctx = (ohmd_context*)context;
	const char* creturn = ohmd_list_gets(ctx, index, type);
	jstring jreturn;

	jreturn = (*env)->NewStringUTF(env,jreturn);

	return jreturn;
}

JNIEXPORT jlong JNICALL Java_OpenHMD_ohmd_list_open_device(JNIEnv* env, jobject obj, jlong context, jint index);
{
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_device* dev = ohmd_list_open_device(ctx, index)
	
	//returns pointer to device as long
	return (long)dev;
	
}

JNIEXPORT jint JNICALL Java_OpenHMD_ohmd_close_device(JNIEnv* env, jobject obj, jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	
	//return int is error code
	return ohmd_close_device(device);
}

JNIEXPORT jfloat* JNICALL Java_OpenHMD_ohmd_device_getf(JNIEnv* env, jobject obj, jlong context, jint type);
{
	ohmd_context* ctx = (ohmd_context*)context;
	float* cout;
	jfloat* jout;

	ohmd_device_getf(device, type, cout);
	jout = (*env)->GetFloatArrayElements(env, cout, 0);

	return jout;
}

JNIEXPORT jint JNICALL Java_OpenHMD_ohmd_device_setf(JNIEnv* env, jobject obj, jlong context, jint type, jfloat* in);
{
	ohmd_context* ctx = (ohmd_context*)context;

	//return int is error code
	return ohmd_device_setf(device, type, in);
}

JNIEXPORT jint* JNICALL Java_OpenHMD_ohmd_device_geti(JNIEnv* env, jobject obj, jlong context, jint type);
{
	ohmd_context* ctx = (ohmd_context*)context;
	int* cout;
	jint* jout;

	ohmd_device_geti(device, type, cout);
	jout = (*env)->GetIntArrayElements(env, cout, 0);

	return jout;
}
