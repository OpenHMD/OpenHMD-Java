#include <jni.h>
#include "OpenHMD-Java.h"
  
JNIEXPORT ohmd_context* JNICALL Java_ohmd_ctx_create();
{
	///TODO: Find out how to handle the return/context
	ohmd_ctx_create();
}

JNIEXPORT void JNICALL Java_ohmd_ctx_destroy(ohmd_context* ctx);
{
	ohmd_ctx_destroy();
}

JNIEXPORT jstring JNICALL Java_ohmd_ctx_get_error(ohmd_context* ctx);
{
	const char* cerror = ohmd_ctx_get_error(ctx);
	jstring error;
	
	error = (*env)->NewStringUTF(env,cerror);
	
	return error; 
}

JNIEXPORT void JNICALL Java_ohmd_ctx_update(ohmd_context* ctx);
{
	ohmd_ctx_update(ctx);
}

JNIEXPORT jint JNICALL Java_ohmd_ctx_probe(ohmd_context* ctx);
{	
	return ohmd_ctx_probe(ctx);
	
}

JNIEXPORT jstring JNICALL Java_ohmd_list_gets(ohmd_context* ctx, int index, ohmd_string_value type);
{
	const char* creturn = ohmd_list_gets(ctx, index, type);
	jstring jreturn;
	
	jreturn = (*env)->NewStringUTF(env,jreturn);
	
	return jreturn; 
}

JNIEXPORT ohmd_device* JNICALL Java_ohmd_list_open_device(ohmd_context* ctx, int index);
{
	///TODO: Find out how to handle the return/device
}

JNIEXPORT jint JNICALL Java_ohmd_close_device(ohmd_device* device);
{
	return ohmd_close_device(device);
}

JNIEXPORT jfloat* JNICALL Java_ohmd_device_getf(ohmd_device* device, ohmd_float_value type, float* out);
{
	float* cout;
	jfloat* jout;
	
	ohmd_device_getf(device, type, out);
	jout = (*env)->GetFloatArrayElements(env, cout, 0);
	
	return jout;
}

JNIEXPORT jint JNICALL Java_ohmd_device_setf(ohmd_device* device, ohmd_float_value type, float* in);
{
	return ohmd_device_setf(device, type, in);
}

JNIEXPORT jint JNICALL Java_ohmd_device_geti(* device, ohmd_int_value type, int* out);
{
	int* cout;
	jint* jout;
	
	ohmd_device_geti(device, type, cout);
	jout = (*env)->GetIntArrayElements(env, cout, 0);
	
	return jout;
}
