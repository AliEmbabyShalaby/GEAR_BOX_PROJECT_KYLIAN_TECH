
/***
 *        ___    ____  ____   ____       _             __         __
 *       /   |  / __ \/ __ \ / __ \_____(_)   ______ _/ /____    / /_
 *      / /| | / /_/ / /_/ // /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     / ___ |/ ____/ ____// ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /_/  |_/_/   /_/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                  /_____/
 */

#ifndef APP_PRIVATE_H_
#define APP_PRIVATE_H_

#include "CPU_Configuration.h"
#include "SPI_Interface.h"
#include "EEPROM_Interface.h"
/*All Includes Here*/

ERROR_STATE ApplicationS_Initialize(void);
ERROR_STATE MAINS_Application(void);
void EEPROM_READ_WRITE(void);

#endif /* APP_PRIVATE_H_ */
