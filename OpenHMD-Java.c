#include <jni.h>
#include "OpenHMD-Java.h"

JNIEXPORT jlong JNICALL Java_OpenHMD_ohmd_ctx_create();
{
	//Create the context and pass pointer as long to Java
	ohmd_context* ctx = ohmd_ctx_create();
	return (long)ctx;
}

JNIEXPORT void JNICALL Java_ohmd_ctx_destroy(jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_ctx_destroy(ctx);
}

JNIEXPORT jstring JNICALL Java_OpenHMD_OpenHMD_ohmd_ctx_get_error(jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	const char* cerror = ohmd_ctx_get_error(ctx);
	jstring error;

	error = (*env)->NewStringUTF(env,cerror);

	return error;
}

JNIEXPORT void JNICALL Java_OpenHMD_ohmd_ctx_update(jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_ctx_update(ctx);
}

JNIEXPORT jint JNICALL Java_OpenHMD_ohmd_ctx_probe(jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	return ohmd_ctx_probe(ctx);
}

JNIEXPORT jstring JNICALL Java_OpenHMD_ohmd_list_gets(jlong context, jint index, ohmd_string_value type);
{
	ohmd_context* ctx = (ohmd_context*)context;
	const char* creturn = ohmd_list_gets(ctx, index, type);
	jstring jreturn;

	jreturn = (*env)->NewStringUTF(env,jreturn);

	return jreturn;
}

JNIEXPORT ohmd_device* JNICALL Java_OpenHMD_ohmd_list_open_device(jlong context, jint index);
{
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_device* dev = ohmd_list_open_device(ctx, index)
	
	return (long)dev;
	
}

JNIEXPORT jint JNICALL Java_OpenHMD_ohmd_close_device(jlong context);
{
	ohmd_context* ctx = (ohmd_context*)context;
	
	return ohmd_close_device(device);
}

JNIEXPORT jfloat* JNICALL Java_OpenHMD_ohmd_device_getf(jlong context, ohmd_float_value type, jfloat* out);
{
	ohmd_context* ctx = (ohmd_context*)context;
	float* cout;
	jfloat* jout;

	ohmd_device_getf(device, type, out);
	jout = (*env)->GetFloatArrayElements(env, cout, 0);

	return jout;
}

JNIEXPORT jint* JNICALL Java_OpenHMD_ohmd_device_setf(jlong context, ohmd_float_value type, jfloat* in);
{
	ohmd_context* ctx = (ohmd_context*)context;
	
	return ohmd_device_setf(device, type, in);
}

JNIEXPORT jint* JNICALL Java_OpenHMD_ohmd_device_geti(jlong context, ohmd_int_value type, jint* out);
{
	ohmd_context* ctx = (ohmd_context*)context;
	int* cout;
	jint* jout;

	ohmd_device_geti(device, type, cout);
	jout = (*env)->GetIntArrayElements(env, cout, 0);

	return jout;
}
