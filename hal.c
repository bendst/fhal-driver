#include <hal.h>
#include <stdio.h>
int32_t hal_init(void *data);
int32_t hal_deinit(void *data);
bool hal_isInit(void *data);
int32_t hal_lock(void *data, TickType_t waittime);
int32_t hal_unlock(void *data);
uintptr_t *hal_getDev(uintptr_t **devs, uintptr_t **end, uint32_t index);
#ifdef CONFIG_INSTANCE_NAME
#define printNameOfDriver(gns) { \
	HAL_DEFINE_GLOBAL_ARRAY(gns); \
	uint32_t i = 0; \
	uintptr_t **instances; \
	struct hal *hal; \
	if (&_dev_##gns != &_dev_##gns##_end) { \
		printf("%s:\n", #gns); \
		for(instances = &_dev_##gns; instances < &_dev_##gns##_end;instances++, i++) { \
			hal = (struct hal *) *instances; \
			printf("%ld: %s\n", i, hal->name); \
		} \
	} \
}
int32_t hal_printNames() {
	printNameOfDriver(hal);
	printNameOfDriver(gpio);
	printNameOfDriver(uart);
	printNameOfDriver(timer);
	printNameOfDriver(pwm);
	printNameOfDriver(capture);
	printNameOfDriver(spi);
	printNameOfDriver(accel);
	printNameOfDriver(gyro);
	printNameOfDriver(adc);
	printNameOfDriver(example);
	return 0;
}
#endif
