#define MIN(a, b) ({ \
  __typeof__ (a) _a = (a); \
  __typeof__ (b) _b = (b); \
  (_a < _b) ? _a : _b; \
})

#define MAX(a, b) ({ \
  __typeof__ (a) _a = (a); \
  __typeof__ (b) _b = (b); \
  (_a > _b) ? _a : _b; \
})

#define CLAMP(x, low, high) ({ \
  __typeof__(x) __x = (x); \
  __typeof__(low) __low = (low);\
  __typeof__(high) __high = (high);\
  (__x > __high) ? __high : ((__x < __low) ? __low : __x); \
})

#define COMPILE_TIME_ASSERT(pred) ((void)sizeof(char[1 - (2 * ((int)(!(pred))))]))

// compute the time elapsed (in microseconds) from 2 counter samples
// case where ts < ts_last is ok: overflow is properly re-casted into uint32_t
uint32_t get_ts_elapsed(uint32_t ts, uint32_t ts_last) {
  return ts - ts_last;
}
