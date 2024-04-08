#include <stdio.h>
#include "parsing.h"



int parseVelocityFromUART(uint8_t * rx_buffer)
{
	int mult = 1;
	int velocity = 0;
	if(rx_buffer[0] == 'p'){//this is a positive value
		int digits = rx_buffer[1] - '0';
		for(int i = digits + 1; i > 1; i--){
			velocity += (rx_buffer[i] - '0')*mult;
			mult *= 10;
		}
		}else if(rx_buffer[0] == 'n'){//this is a positive value
			int digits = rx_buffer[1] - '0';
		for(int i = digits + 1; i > 1; i--){
			velocity -= (rx_buffer[i] - '0')*mult;
			mult *= 10;
		}
	}
	return velocity;
}
