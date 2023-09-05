/***
 *        ________________  ____  ____  __  ___     ____      __            ____                  __
 *       / ____/ ____/ __ \/ __ \/ __ \/  |/  /    /  _/___  / /____  _____/ __/___ _________    / /_
 *      / __/ / __/ / /_/ / /_/ / / / / /|_/ /     / // __ \/ __/ _ \/ ___/ /_/ __ `/ ___/ _ \  / __ \
 *     / /___/ /___/ ____/ _, _/ /_/ / /  / /    _/ // / / / /_/  __/ /  / __/ /_/ / /__/  __/ / / / /
 *    /_____/_____/_/   /_/ |_|\____/_/  /_/____/___/_/ /_/\__/\___/_/  /_/  \__,_/\___/\___(_)_/ /_/
 *                                        /_____/
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "CPU_Configuration.h"

void EEPROM_Init(void);

void EEPROM_ByteWrite(UINT8_t addr, UINT8_t data);

UINT8_t EEPROM_RandomRead(UINT8_t addr);

#endif /* EEPROM_INTERFACE_H_ */
