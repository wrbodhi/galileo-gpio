/* galileo2GPIO.h - GPIO example definitions */

/*
 * Copyright (c) 2015, Wind River Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* device bindings */

extern struct device *gpio07;
extern struct device *gpioLegacy;
extern struct device *gpio_sus;
extern struct device *gpioEXP0;
extern struct device *gpioEXP1;
extern struct device *gpioEXP2;
extern struct device *i2c;
extern struct device *pinmux;

/* function declarations */

int setup (void);

int gpio_output_set (int output_pin, int value);
int gpio_input_get (int input_pin, int *val_ptr);

