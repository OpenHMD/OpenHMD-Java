#include "OpenHMD-Java.h"

#include "openhmd.h"

#include <jni.h>

jlong Java_OpenHMD_ohmd_1ctx_1create
  (JNIEnv *env, jobject obj)
{
	//Create the context and pass pointer as long to Java
	ohmd_context* ctx = ohmd_ctx_create();

	return (long)ctx;
}

void Java_OpenHMD_ohmd_1ctx_1destroy
  (JNIEnv *env, jobject obj, jlong context)
{
	//Destroy the context
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_ctx_destroy(ctx);
}

jstring Java_OpenHMD_ohmd_1ctx_1get_1error
  (JNIEnv *env, jobject obj, jlong context)
{
	//Call get_error and return the error code
	ohmd_context* ctx = (ohmd_context*)context;
	const char* cerror = ohmd_ctx_get_error(ctx);
	jstring error;

	error = (*env)->NewStringUTF(env,cerror);

	return error;
}

void Java_OpenHMD_ohmd_1ctx_1update
  (JNIEnv *env, jobject obj, jlong context)
{
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_ctx_update(ctx);
}

jint Java_OpenHMD_ohmd_1ctx_1probe
  (JNIEnv *env, jobject obj, jlong context)
{
	ohmd_context* ctx = (ohmd_context*)context;

	return ohmd_ctx_probe(ctx);
}

jstring Java_OpenHMD_ohmd_1list_1gets
  (JNIEnv *env, jobject obj, jlong context, jint index, jint type)
{
	ohmd_context* ctx = (ohmd_context*)context;
	const char* creturn = ohmd_list_gets(ctx, index, type);
	jstring jreturn;

	jreturn = (*env)->NewStringUTF(env,creturn);

	return jreturn;
}

jlong Java_OpenHMD_ohmd_1list_1open_1device
  (JNIEnv *env, jobject obj, jlong context, jint index)
{
	ohmd_context* ctx = (ohmd_context*)context;
	ohmd_device* dev = ohmd_list_open_device(ctx, index);

	//returns pointer to device as long
	return (long)dev;

}

jint Java_OpenHMD_ohmd_1close_1device
  (JNIEnv *env, jobject obj, jlong context)
{
	ohmd_device* dev = (ohmd_device*)context;

	//return int is error code
	return ohmd_close_device(dev);
}

jfloatArray Java_OpenHMD_ohmd_1device_1getf
  (JNIEnv *env, jobject obj, jlong device, jint type)
{
	ohmd_device* dev = (ohmd_device*)device;

	switch(type){
	case OHMD_LEFT_EYE_GL_MODELVIEW_MATRIX:
	{
		float cout[16];
		jfloatArray jout = (*env)->NewFloatArray(env, 16);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_RIGHT_EYE_GL_MODELVIEW_MATRIX:
	{
		float cout[16];
		jfloatArray jout = (*env)->NewFloatArray(env, 16);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_LEFT_EYE_GL_PROJECTION_MATRIX:
	{
		float cout[16];
		jfloatArray jout = (*env)->NewFloatArray(env, 16);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_RIGHT_EYE_GL_PROJECTION_MATRIX:
	{
		float cout[16];
		jfloatArray jout = (*env)->NewFloatArray(env, 16);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 16, cout);

		return jout;
	}
	case OHMD_SCREEN_HORIZONTAL_SIZE:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_SCREEN_VERTICAL_SIZE:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_LENS_HORIZONTAL_SEPARATION:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_LENS_VERTICAL_POSITION:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_RIGHT_EYE_FOV:
	case OHMD_LEFT_EYE_FOV:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_RIGHT_EYE_ASPECT_RATIO:
	case OHMD_LEFT_EYE_ASPECT_RATIO:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_EYE_IPD:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_PROJECTION_ZFAR:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}
	case OHMD_PROJECTION_ZNEAR:
	{
		float cout[1];
		jfloatArray jout = (*env)->NewFloatArray(env, 1);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 1, cout);

		return jout;
	}

	case OHMD_ROTATION_QUAT:
	{
		float cout[4];
		jfloatArray jout = (*env)->NewFloatArray(env, 4);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 4, cout);

		return jout;
	}
	case OHMD_POSITION_VECTOR:
	{
		float cout[3];
		jfloatArray jout = (*env)->NewFloatArray(env, 3);

		ohmd_device_getf(dev, type, cout);
		(*env)->SetFloatArrayRegion(env, jout, 0, 4, cout);

		return jout;
	}

	default:
	    return 0;
		//return dev->getf(dev, type, out);
	}

	return 0; //something horrible has gone wrong
}

jint Java_OpenHMD_ohmd_1device_1setf
  (JNIEnv *env, jobject obj, jlong context, jint type, jfloatArray in)
{
	ohmd_context* ctx = (ohmd_context*)context;

	//return int is error code
	//return ohmd_device_setf(device, type, in);
}

jintArray Java_OpenHMD_ohmd_1device_1geti
  (JNIEnv *env, jobject obj, jlong device, jint type)
{
	/*
	ohmd_context* ctx = (ohmd_context*)context;
	int* cout;
	jintArray jout;

	ohmd_device_geti(device, type, cout);
	jout = (*env)->GetIntArrayElements(env, cout, 0);

	return jout;*/
}
