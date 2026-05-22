int g_x77{98}; // extern by default
// extern int g_z77{ 98 }; will give compiler warning 'initialized and declared "extern"'
extern const int g_y77{ 3 };
// const vars have internal linkage by default, so need extern to give g_y77 external linkage
// extern can mean 'external linkage' or 'forward declaration'
// 