public class OpenHMD 
{
	static 
	{
		System.load("/home/koen/Code/OpenHMD-Java/libOpenHMD.so");
	}
	
	public static native long 		ohmd_ctx_create();
	public static native void 		ohmd_ctx_destroy(long ctx);
	public static native String 	ohmd_ctx_get_error(long ctx);
	public static native void 		ohmd_ctx_update(long ctx);
	public static native int 		ohmd_ctx_probe(long ctx);
	public static native String 	ohmd_list_gets(long dev, int index, int ohmd_string_value); 
	public static native long 		ohmd_list_open_device(long ctx, int index);
	public static native int 		ohmd_close_device(long ctx);
	public static native float[] 	ohmd_device_getf(long dev, int ohmd_float_value);
	public static native int 		ohmd_device_setf(long dev, int ohmd_float_value, float[] values);
	public static native int[]		ohmd_device_geti(long dev, int ohmd_int_value);

	
	public static void main(String[] args)
	{
		long ctx = ohmd_ctx_create();
		System.out.println("ctx: " + ctx);
		
		int numDevices = ohmd_ctx_probe(ctx);
		System.out.println("numDevices (probe): " + numDevices);
		
		long dev = ohmd_list_open_device(ctx, 0);
		System.out.println("dev: " + dev);
	
		ohmd_ctx_update(ctx);
		
		
		float[] rot = ohmd_device_getf(dev, 1);
		for (float f : rot)
			System.out.println(f + ", ");
	}
}
