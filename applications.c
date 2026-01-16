/*
 * applications.c
 *
 *  Created on: May 14, 2018
 *  Last modified on: May 21, 2018
 *      Author: Paolo Torroni. All rights reserved.
 */

#include "applications.h"

void Application0(int task) {
	switch (task) {
	case 0: /* task 0: [:3 ] */
		get_busy(60*OPSMSEC);
		break;
	}
}

void Application1(int task) {
	switch (task) {
	case 0: /* task 1: [:2.5 [Ra: 0.5]] */
		get_busy(20*OPSMSEC);
			EntrySection(0,0);
			get_busy(10*OPSMSEC);
			ExitSection(0,0);
		get_busy(20*OPSMSEC);
		break;
	case 1: /* task 2: [:6 [Ra: 5]] */
		get_busy(10*OPSMSEC);
			EntrySection(0,1);
			get_busy(100*OPSMSEC);
			ExitSection(0,1);
		get_busy(10*OPSMSEC);
		break;
	}
}

void Application2(int task) {
	switch (task) {
	case 0: /* task 1: [:3 [Rb:2]] */
		get_busy(10*OPSMSEC);
			EntrySection(1,0);
			get_busy(40*OPSMSEC);
			ExitSection(1,0);
		get_busy(10*OPSMSEC);
		break;
	case 1: /* task 2: [:5 [Ra:4]] */
		get_busy(10*OPSMSEC);
			EntrySection(0,1);
			get_busy(80*OPSMSEC);
			ExitSection(0,1);
		get_busy(10*OPSMSEC);
		break;
	case 2: /* task 3: [:4 [Rb:3 [Ra:1]]] */
		get_busy(10*OPSMSEC);
			EntrySection(1,2);
			get_busy(20*OPSMSEC);
				EntrySection(0,2);
				get_busy(20*OPSMSEC);
				ExitSection(0,2);
			get_busy(20*OPSMSEC);
			ExitSection(1,2);
		get_busy(10*OPSMSEC);
		break;
	}
}

void Application3(int task) {
	switch (task) {
	case 0: /* task 1: [:3 [Rb:2]] */
		get_busy(10*OPSMSEC);
			EntrySection(1,0);
			get_busy(40*OPSMSEC);
			ExitSection(1,0);
		get_busy(10*OPSMSEC);
		break;
	case 1: /* task 2: [:5 [Ra:4]] */
		get_busy(10*OPSMSEC);
			EntrySection(0,1);
			get_busy(80*OPSMSEC);
			ExitSection(0,1);
		get_busy(10*OPSMSEC);
		break;
	case 2: /* task 3: [:4 [Ra:3 [Rb:1]]] */
		get_busy(10*OPSMSEC);
			EntrySection(0,2);
			get_busy(20*OPSMSEC);
				EntrySection(1,2);
				get_busy(20*OPSMSEC);
				ExitSection(1,2);
			get_busy(20*OPSMSEC);
			ExitSection(0,2);
		get_busy(10*OPSMSEC);
		break;
	}
}

void Application4(int task) {
	switch (task) {
	case 0: /* task 1: [:2 [Ra:1]] */
		get_busy(10*OPSMSEC);
			EntrySection(0,0);
			get_busy(20*OPSMSEC);
			ExitSection(0,0);
		get_busy(10*OPSMSEC);
		break;
	case 1: /* task 2: [:2 [Rb:1]] */
		get_busy(10*OPSMSEC);
			EntrySection(1,1);
			get_busy(20*OPSMSEC);
			ExitSection(1,1);
		get_busy(10*OPSMSEC);
		break;
	case 2: /* task 3: [:6 [Rb:6 [Ra:3]]] */
		get_busy(10*OPSMSEC);
			EntrySection(1,2);
			get_busy(20*OPSMSEC);
				EntrySection(0,2);
				get_busy(60*OPSMSEC);
				ExitSection(0,2);
			get_busy(40*OPSMSEC);
			ExitSection(1,2);
		get_busy(10*OPSMSEC);
		break;
	}
	
}


 /* Application for RT Assignment */
void Application5(int task) {   
	switch (task) {
	
	case 0: /* T1 */
		/* Period: 10, Phase: 2 */
		get_busy(20 * OPSMSEC);         
			EntrySection(0, 0);         /*  enters R1 */
			get_busy(20 * OPSMSEC);     /*  uses R1 */
			ExitSection(0, 0);          /*  exits R1 */
		get_busy(20 * OPSMSEC);
		break;

	case 1: /* T2 */
		/* Period: 15, Phase: 1 */
		         
		EntrySection(0, 1);               /*  enter R1 */
			get_busy(20 * OPSMSEC);       /*  use  R1 */
			EntrySection(1, 1);           /*  enter R2 */
				get_busy(40 * OPSMSEC);   /*  use R2 and R1 */
			ExitSection(1, 1);       	  /*  exit R2 */
		ExitSection(0, 1);                /*  exit R1 */
		get_busy(20 * OPSMSEC);        
		break;

	case 2: /* T3 */
		/* Period: 30, Phase: 0 */
		get_busy(20 * OPSMSEC);         
			EntrySection(2, 2);             /*  enter R3 */
				get_busy(40 * OPSMSEC);     /*  use R3 */
				EntrySection(0, 2);         /*  enter R1 */
					get_busy(40 * OPSMSEC); /*  use R3 and R1 */
					EntrySection(1, 2);     /*  enter R2 */
					get_busy(20 * OPSMSEC); /*  use R3, R2 and R1 */
					ExitSection(0, 2);		/*  exit R1 */
				get_busy(40 * OPSMSEC);		/*  use R3 and R2 */
				ExitSection(1, 2);			/*  exit R2 */
			ExitSection(2, 2);         		/*  exit R3 */
		break;
	}
}
