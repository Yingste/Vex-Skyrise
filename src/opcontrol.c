/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Purdue University ACM SIG BOTS nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */
typedef int bool;
#define TRUE 1
#define FALSE 0

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
void operatorControl() {

	while (1) {

		//--------------------------------------------------------------------
		//------ Joystick Declaration
		//--------------------------------------------------------------------

		//Declare Joystick1
		int joystick1 = joystickGetAnalog(1,1);
		int joystick2 = joystickGetAnalog(1,2);
		int joystick3 = joystickGetAnalog(1,3);
		int joystick4 = joystickGetAnalog(1,4);
		bool button5u = joystickGetDigital(1,5,JOY_UP);
		bool button5d = joystickGetDigital(1,5,JOY_DOWN);
		bool button6u = joystickGetDigital(1,6,JOY_UP);
		bool button6d = joystickGetDigital(1,6,JOY_DOWN);
		bool button7u = joystickGetDigital(1,7,JOY_UP);
		bool button7d = joystickGetDigital(1,7,JOY_DOWN);
		bool button7l = joystickGetDigital(1,7,JOY_LEFT);
		bool button7r = joystickGetDigital(1,7,JOY_RIGHT);
		bool button8u = joystickGetDigital(1,8,JOY_UP);
		bool button8d = joystickGetDigital(1,8,JOY_DOWN);
		bool button8l = joystickGetDigital(1,8,JOY_LEFT);
		bool button8r = joystickGetDigital(1,8,JOY_RIGHT);

		//Declare Joystick2
		int joystick1 = joystickGetAnalog(2,1);
		int joystick2 = joystickGetAnalog(2,2);
		int joystick3 = joystickGetAnalog(2,3);
		int joystick4 = joystickGetAnalog(2,4);
		bool button5u = joystickGetDigital(2,5,JOY_UP);
		bool button5d = joystickGetDigital(2,5,JOY_DOWN);
		bool button6u = joystickGetDigital(2,6,JOY_UP);
		bool button6d = joystickGetDigital(2,6,JOY_DOWN);
		bool button7u = joystickGetDigital(2,7,JOY_UP);
		bool button7d = joystickGetDigital(2,7,JOY_DOWN);
		bool button7l = joystickGetDigital(2,7,JOY_LEFT);
		bool button7r = joystickGetDigital(2,7,JOY_RIGHT);
		bool button8u = joystickGetDigital(2,8,JOY_UP);
		bool button8d = joystickGetDigital(2,8,JOY_DOWN);
		bool button8l = joystickGetDigital(2,8,JOY_LEFT);
		bool button8r = joystickGetDigital(2,8,JOY_RIGHT);


		//--------------------------------------------------------------------
		//------ Variables
		//--------------------------------------------------------------------
		int XDriveX;
		int XDriveY;
		int XDriveR;


		//--------------------------------------------------------------------
		//------ Drive Train
		//--------------------------------------------------------------------

		// Controller 1/2, Stick L/R, Axis X/Y

		//for arcade drive
		if (1 == 0)
		{
		XDriveX = joystick4;
		XDriveY = joystick3;
		XDriveR = joystick1;
		}

		//for hypothetical tank drive controls
		if (1 == 1)
		{
			XDriveX = joystick4;
			XDriveY = ((joystick3+joystick2)/2);
			XDriveR = (1-((joystick3-joystick2)/2));// I think I need to increase the rotation when doing slight turn. as of now if only one stick is applied it will 45 strafe.
		}


		// Y component, X component, Rotation
		motorSet(1, -XDriveY - XDriveX - XDriveR); // Front Left
		motorSet(2,  XDriveY - XDriveX - XDriveR); // Front Right
		motorSet(3,  XDriveY + XDriveX - XDriveR); // Back Left
		motorSet(4, -XDriveY + XDriveX - XDriveR); // Back Right



		//--------------------------------------------------------------------
		//------ Arm
		//--------------------------------------------------------------------





		delay(20);
	}
}
