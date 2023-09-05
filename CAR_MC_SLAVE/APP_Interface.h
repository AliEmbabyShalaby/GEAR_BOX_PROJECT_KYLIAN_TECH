/***
 *        ___    ____  ____   ____      __            ____                  __
 *       /   |  / __ \/ __ \ /  _/___  / /____  _____/ __/___ _________    / /_
 *      / /| | / /_/ / /_/ / / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / ___ |/ ____/ ____/_/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_/  |_/_/   /_/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                  /_____/
 */

#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

#include "CPU_Configuration.h"
#include "SPI_Interface.h"
#include "EEPROM_Interface.h"
/*All Includes Here*/

ERROR_STATE ApplicationS_Initialize(void);
ERROR_STATE MAINS_Application(void);
void EEPROM_READ_WRITE(void);

#endif /* APP_INTERFACE_H_ */
