// Force linker to keep command symbols for dlsym access
// These functions are called dynamically by ios_system via dlsym(RTLD_MAIN_ONLY, ...)
// The array must be GLOBAL (not static) so linker can't prove it's unused and discard it

extern int config_main(int, char**);
extern int help_main(int, char**);
extern int clear_main(int, char**);
extern int history_main(int, char**);
extern int open_main(int, char**);
extern int showkey_main(int, char**);
extern int bench_main(int, char**);
extern int geo_main(int, char**);
extern int device_info_main(int, char**);
extern int say_main(int, char**);
extern int whatsnew_main(int, char**);
extern int build_main(int, char**);
extern int blink_openurl_main(int, char**);
extern int blink_xcall_main(int, char**);
extern int blink_ssh_main(int, char**);
extern int blink_ssh_add(int, char**);
extern int copyfiles_main(int, char**);
extern int skstore_main(int, char**);
extern int code_main(int, char**);
extern int browse_main(int, char**);
extern int facecam_main(int, char**);
extern int udptunnel_main(int, char**);

typedef int (*cmd_func)(int, char**);

// GLOBAL exported array - linker must keep because it might be referenced externally
__attribute__((visibility("default"), used))
cmd_func blink_force_link_commands[] = {
    config_main, help_main, clear_main, history_main,
    open_main, showkey_main, bench_main, geo_main,
    device_info_main, say_main, whatsnew_main, build_main,
    blink_openurl_main, blink_xcall_main, blink_ssh_main,
    blink_ssh_add, copyfiles_main, skstore_main,
    code_main, browse_main, facecam_main, udptunnel_main
};
