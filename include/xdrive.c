/*
 * xdrive.c
 *
 *  Created on: Nov 21, 2014
 *      Author: yingste
 */
#include "xdrive.h"
#include <main.h>


void xdrive();

xdrive() {
	if (isAutonomous())
	{

	} else
	{


		// Controller 1/2, Stick L/R, Axis X/Y


				XDriveX = joystick1_4;
				XDriveY = joystick1_3;
				XDriveR = joystick1_1;




				motorSet(2, -XDriveY - XDriveX - XDriveR); // Front Left
				motorSet(9,  XDriveY - XDriveX - XDriveR); // Front Right
				motorSet(10,  XDriveY + XDriveX - XDriveR); // Back Left
				motorSet(1, -XDriveY + XDriveX - XDriveR); // Back Right




	}

};





