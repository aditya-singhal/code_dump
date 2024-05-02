#define FUNC_INFO_ENABLE 	1

#if FUNC_INFO_ENABLE == 1
	#define FUNC_INFO() std::cout << __FILE__ << ":" << __LINE__ << ": " << __PRETTY_FUNCTION__ << std::endl
#else
	#define FUNC_INFO()
#endif

#define PRINT(x) std::cout << "@" << sc_time_stamp() << ": " << x;