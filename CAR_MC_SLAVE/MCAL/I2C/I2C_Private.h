/***
 *        _______   ______     ____       _             __         __
 *       /  _/__ \ / ____/    / __ \_____(_)   ______ _/ /____    / /_
 *       / / __/ // /        / /_/ / ___/ / | / / __ `/ __/ _ \  / __ \
 *     _/ / / __// /___     / ____/ /  / /| |/ / /_/ / /_/  __/ / / / /
 *    /___//____/\____/____/_/   /_/  /_/ |___/\__,_/\__/\___(_)_/ /_/
 *                   /_____/
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define TWBR	(*(volatile UINT8_t *) 0x20)
#define TWCR	(*(volatile UINT8_t *) 0x56)
#define TWSR	(*(volatile UINT8_t *) 0x21)
#define TWDR	(*(volatile UINT8_t *) 0x23)
#define TWAR	(*(volatile UINT8_t *) 0x22)

/*TWCR pins*/
#define TWCR_TWINT	7
#define TWCR_TWEA	6
#define TWCR_TWSTA	5
#define	TWCR_TWSTO	4
#define TWCR_TWWC	3
#define	TWCR_TWEN	2
#define TWCR_TWIE	0

/*TWSR pins*/
#define TWSR_TWPS0	0
#define TWSR_TWPS1	1

/*TWAR pins*/
#define TWAR_GCE	0

/*I2C control*/
#define I2C_DS		0
#define I2C_EN		1

/*I2C int control*/
#define I2C_INT_DS	0
#define I2C_INT_EN	1

/*prescaler*/
#define I2C_PRESCALE_1	1
#define I2C_PRESCALE_4	4
#define I2C_PRESCALE_16	16
#define I2C_PRESCALE_64	64

/*master status codes*/
#define START_ACK					0x08
#define REP_START_ACK				0x10
#define MSTR_ADDR_AND_W_ACK			0x18
#define MSTR_ADDR_AND_W_NOT_ACK		0x20
#define MSTR_DATA_TX_ACK			0x28
#define MSTR_DATA_TX_NOT_ACK		0x30
#define ARBITRATION_LOST			0x38
#define MSTR_ADDR_AND_R_ACK			0x40
#define MSTR_ADDR_AND_R_NOT_ACK		0x48
#define MSTR_DATA_RX_ACK			0x50
#define MSTR_DATA_RX_NOT_ACK		0x58

/*slave status codes*/
#define	SLAVE_ADDR_AND_W_ACK		0x60
#define SLAVE_GEN_CALL_ACK			0x70
#define SLAVE_DATA_RX_ACK			0x80
#define SLAVE_DATA_RX_NOT_ACK		0x88
#define SLAVE_GEN_DATA_RX_ACK		0x90
#define SLAVE_GEN_DATA_RX_NOT_ACK	0x98
#define SLAVE_STOP_OR_REP_START		0xA0
#define SLAVE_ADDR_AND_R_ACK		0xA8
#define SLAVE_DATA_TX_ACK			0xB8
#define SLAVE_DATA_TX_NOT_ACK		0xC0

#define BUS_ERROR					0x00

#endif /* I2C_PRIVATE_H_ */
