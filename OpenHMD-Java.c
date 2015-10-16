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

JNIEXPORT jfloatArray JNICALL Java_OpenHMD_ohmd_device_getf(JNIEnv* env, jobject obj, jlong context, jint type);
{
	ohmd_context* ctx = (ohmd_context*)context;
	
	switch(type){
	case OHMD_LEFT_EYE_GL_MODELVIEW_MATRIX: 
	{
		float[16] cout;
		jfloatArray jout = (*env)->NewFloatArray(16);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_RIGHT_EYE_GL_MODELVIEW_MATRIX: 
	{
		float[16] out;
		jfloatArray jout = (*env)->NewFloatArray(16);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_LEFT_EYE_GL_PROJECTION_MATRIX:
	{
		float[16] out;
		jfloatArray jout = (*env)->NewFloatArray(16);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_RIGHT_EYE_GL_PROJECTION_MATRIX:
	{
		float[16] out;
		jfloatArray jout = (*env)->NewFloatArray(16);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_SCREEN_HORIZONTAL_SIZE:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_SCREEN_VERTICAL_SIZE:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_LENS_HORIZONTAL_SEPARATION:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_LENS_VERTICAL_POSITION:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_RIGHT_EYE_FOV:
	case OHMD_LEFT_EYE_FOV:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_RIGHT_EYE_ASPECT_RATIO:
	case OHMD_LEFT_EYE_ASPECT_RATIO:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_EYE_IPD:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_PROJECTION_ZFAR:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_PROJECTION_ZNEAR:
	{
		float[1] out;
		jfloatArray jout = (*env)->NewFloatArray(1);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_ROTATION_QUAT:
	{
		float[4] out;
		jfloatArray jout = (*env)->NewFloatArray(4);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 4, cout);

		return jout;
	}
	case OHMD_POSITION_VECTOR:
	{
		float[4] out;
		jfloatArray jout = (*env)->NewFloatArray(4);
		
		ohmd_device_getf(device, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 4, cout);

		return jout;
	}
		
	default:
		return device->getf(device, type, out);
	}
	
	return 0; //something horrible has gone wrong
}

JNIEXPORT jint JNICALL Java_OpenHMD_ohmd_device_setf(JNIEnv* env, jobject obj, jlong context, jint type, jfloatArray in);
{
	ohmd_context* ctx = (ohmd_context*)context;

	//return int is error code
	return ohmd_device_setf(device, type, in);
}

JNIEXPORT jintArray JNICALL Java_OpenHMD_ohmd_device_geti(JNIEnv* env, jobject obj, jlong context, jint type);
{
	/*
	ohmd_context* ctx = (ohmd_context*)context;
	int* cout;
	jintArray jout;

	ohmd_device_geti(device, type, cout);
	jout = (*env)->GetIntArrayElements(env, cout, 0);

	return jout;*/
}
