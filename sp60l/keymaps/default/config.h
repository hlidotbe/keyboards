/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"


#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL // comment this out for tap-to-select acceleration
// medium values will be used as default
#define MK_C_OFFSET_SLOW     1 // pixels
#define MK_C_INTERVAL_SLOW  30 // milliseconds
#define MK_C_OFFSET_MED      8
#define MK_C_INTERVAL_MED   16
#define MK_C_OFFSET_FAST    20
#define MK_C_INTERVAL_FAST  16

#define MK_W_OFFSET_SLOW     1 // wheel clicks
#define MK_W_INTERVAL_SLOW 150 // milliseconds
#define MK_W_OFFSET_MED      1
#define MK_W_INTERVAL_MED  125
#define MK_W_OFFSET_FAST     1
#define MK_W_INTERVAL_FAST  40

#endif
