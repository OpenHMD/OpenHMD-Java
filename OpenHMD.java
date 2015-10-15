public class OpenHMD 
{
	static 
	{
		System.load("/home/koen/Code/OpenHMD-Java/libOpenHMD.so");
	}
	
	
	
//	private native void ohmd_ctx_create();
	private native void 	ohmd_ctx_destroy();
	private native String 	ohmd_ctx_get_error();
	private native void 	ohmd_ctx_update();
	private native int 		ohmd_ctx_probe();
	private native String 	ohmd_list_gets();
//	private native void ohmd_list_open_device();
	private native int 		ohmd_close_device();
	private native float 	ohmd_device_getf();
	private native int 		ohmd_device_setf();
	private native int 		ohmd_device_geti();

	
	public static void main(String[] args)
	{
	}
}
