/***
 *        _______   ______    ______            _____         __
 *       /  _/__ \ / ____/   / ____/___  ____  / __(_)___ _  / /_
 *       / / __/ // /       / /   / __ \/ __ \/ /_/ / __ `/ / __ \
 *     _/ / / __// /___    / /___/ /_/ / / / / __/ / /_/ / / / / /
 *    /___//____/\____/____\____/\____/_/ /_/_/ /_/\__, (_)_/ /_/
 *                   /_____/                      /____/
 */

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

/*
	IC2_EN -> Enable I2C protocol
	IC2_DS -> Disable I2C protocol
*/
#define I2C_MODE		I2C_EN

/*
	IC2_INT_EN -> Enable I2C interrupt service routine
	IC2_INT_DS -> Disable I2C interrupt service routine
*/
#define I2C_INT_MODE	I2C_INT_DS

/*
	I2C_PRESCALE_1 -> set prescaler to F_CLK/1
	I2C_PRESCALE_4 -> set prescaler to F_CLK/4
	I2C_PRESCALE_16 -> set prescaler to F_CLK/16
	I2C_PRESCALE_64 -> set prescaler to F_CLK/64
*/
#define I2C_PRESCALE	I2C_PRESCALE_1

#endif /* I2C_CONFIG_H_ */
