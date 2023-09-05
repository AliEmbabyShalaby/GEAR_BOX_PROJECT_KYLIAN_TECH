/***
 *                        _
 *       ____ ___  ____ _(_)___   _____
 *      / __ `__ \/ __ `/ / __ \ / ___/
 *     / / / / / / /_/ / / / / // /__
 *    /_/ /_/ /_/\__,_/_/_/ /_(_)___/
 *
 */
#include "main.h"

int main() {
	ApplicationS_Initialize();
	while (1) {
		MAINS_Application();
	}
	return 0;
}
