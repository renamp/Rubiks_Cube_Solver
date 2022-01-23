#include DriverMotor.inc

void Cruz(){
	if( m[5][4] == m[5][1] || m[5][4] == m[5][3] || m[5][4] == m[5][5] || m[5][4] == m[5][7] ){
Loop1:
		if( m[5][4] != m[5][5] || m[0][1] != m[0][4] ){
			if( m[5][4] != m[5][7] || m[1][1] != m[1][4] ){
				if( m[5][4] != m[5][3] || m[2][1] != m[2][4] ){
					if( m[5][4] != m[5][1] || m[3][1] != m[3][4] ){
						move(8+5); goto Loop1;
	}	}	}	}	}

Loop2:
	if( m[0][3] == m[5][4] && m[1][5] == m[1][4] ){ move(1); goto Loop2; }
	else if( m[1][3] == m[5][4] && m[2][5] == m[2][4] ){ move(2); goto Loop2;}
	else if( m[2][3] == m[5][4] && m[3][5] == m[3][4] ){ move(3); goto Loop2;}
	else if( m[3][3] == m[5][4] && m[0][5] == m[0][4] ){ move(0); goto Loop2;}
	
	else if( m[1][5] == m[5][4] && m[0][3] == m[0][4] ){ move(8+0); goto Loop2;}
	else if( m[2][5] == m[5][4] && m[1][3] == m[1][4] ){ move(8+1); goto Loop2;}
	else if( m[3][5] == m[5][4] && m[2][3] == m[2][4] ){ move(8+2); goto Loop2;}
	else if( m[0][5] == m[5][4] && m[3][3] == m[3][4] ){ move(8+3); goto Loop2;}

Loop3:
	if( m[5][4] == m[4][1] || m[5][4] == m[4][3] || m[5][4] == m[4][5] || m[5][4] == m[4][7] ){
		if( m[4][5] == m[5][4] && m[0][4] == m[0][7] ){ move(0); move(0); goto Loop2; }
		else if( m[4][1] == m[5][4] && m[1][4] == m[1][7] ){ move(1); move(1); goto Loop2; }
		else if( m[4][3] == m[5][4] && m[2][4] == m[2][7] ){ move(2); move(2); goto Loop2; }
		else if( m[4][7] == m[5][4] && m[3][4] == m[3][7] ){ move(3); move(3); goto Loop2; }
		move(4); goto Loop3;
	}
	
	if( m[0][3] == m[5][4] ){ move(8+1); 
		if( m[0][3] == m[5][4] && m[1][5] == m[1][4] ){ 
			if( m[1][7] == m[0][4] ){ move(8+4); }
			else if( m[1][7] == m[2][4] ){ move(4); }
			else { move(8+4); }
			move(1);
		} goto Loop3;
	}
	else if( m[1][3] == m[5][4] ){ move(8+2); 
		if( m[1][3] == m[5][4] && m[2][5] == m[2][4] ){ 
			if( m[2][7] == m[1][4] ){ move(8+4); }
			else if( m[2][7] == m[3][4] ){ move(4); }
			else { move(8+4); }
			move(2);
		} goto Loop3;
	}
	else if( m[2][3] == m[5][4] ){ move(8+3); 
		if( m[2][3] == m[5][4] && m[3][5] == m[3][4] ){ 
			if( m[3][7] == m[2][4] ){ move(8+4); }
			else if( m[3][7] == m[0][4] ){ move(4); }
			else { move(8+4); }
			move(3);
		} goto Loop3;
	}
	else if( m[3][3] == m[5][4] ){ move(8+0); 
		if( m[3][3] == m[5][4] && m[0][5] == m[0][4] ){ 
			if( m[0][7] == m[3][4] ){ move(8+4); }
			else if( m[0][7] == m[1][4] ){ move(4); }
			else { move(8+4); }
			move(0);
		} goto Loop3;
	}

	else if( m[1][5] == m[5][4] ){ move(0);
		if( m[1][5] == m[5][4] && m[0][3] == m[0][4] ){
			if( m[0][7] == m[3][4] ){ move(8+4); }
			else if( m[0][7] == m[1][4] ){ move(4); }
			else { move(8+4); }
			move(8+0);
		} goto Loop3;
	}
	else if( m[2][5] == m[5][4] ){ move(1);
		if( m[2][5] == m[5][4] && m[1][3] == m[1][4] ){
			if( m[1][7] == m[0][4] ){ move(8+4); }
			else if( m[1][7] == m[2][4] ){ move(4); }
			else { move(8+4); }
			move(8+1);
		} goto Loop3;
	}
	else if( m[3][5] == m[5][4] ){ move(2);
		if( m[3][5] == m[5][4] && m[2][3] == m[2][4] ){
			if( m[2][7] == m[1][4] ){ move(8+4); }
			else if( m[2][7] == m[3][4] ){ move(4); }
			else { move(8+4); }
			move(8+2);
		} goto Loop3;
	}
	else if( m[0][5] == m[5][4] ){ move(3);
		if( m[0][5] == m[5][4] && m[3][3] == m[3][4] ){
			if( m[3][7] == m[2][4] ){ move(8+4); }
			else if( m[3][7] == m[0][4] ){ move(4); }
			else { move(8+4); }
			move(8+3);
		} goto Loop3;
	}

Loop4:
	if( m[1][7] == m[5][4] ){
		if( m[4][1] == m[0][4] ){ move(1); move(8+0); }
		else if( m[4][1] == m[2][4] ){ move(8+1); move(2); }
		else { move(8+4); }
		goto Loop2;
	}
	else if( m[2][7] == m[5][4] ){
		if( m[4][3] == m[1][4] ){ move(2); move(8+1); }
		else if( m[4][3] == m[3][4] ){ move(8+2); move(3); }
		else { move(8+4); }
		goto Loop2;
	}
	else if( m[3][7] == m[5][4] ){
		if( m[4][7] == m[2][4] ){ move(3); move(8+2); }
		else if( m[4][7] == m[0][4] ){ move(8+3); move(0); }
		else { move(8+4); }
		goto Loop2;
	}
	else if( m[0][7] == m[5][4] ){
		if( m[4][5] == m[3][4] ){ move(0); move(8+3); }
		else if( m[4][5] == m[1][4] ){ move(8+0); move(1); }
		else { move(8+4); }
		goto Loop2;
	}
	
	if( m[0][1] == m[5][4] ){ move(0); move(0); goto Loop4;}
	else if( m[1][1] == m[5][4] ){ move(1); move(1); goto Loop4;}
	else if( m[2][1] == m[5][4] ){ move(2); move(2); goto Loop4;}
	else if( m[3][1] == m[5][4] ){ move(3); move(3); goto Loop4;}
	
	if( m[0][1] != m[0][4] ){ move(0); move(0); goto Loop3;}
	else if( m[1][1] != m[1][4] ){ move(1); move(1); goto Loop3;}
	else if( m[2][1] != m[2][4] ){ move(2); move(2); goto Loop3;}
	else if( m[3][1] != m[3][4] ){ move(3); move(3); goto Loop3;}
}

void F2L(){
int F2lCount;		// o algoritmo deve ser executado 4 vezes.. uma para cada canto
int aux1;			// variavel para fazer 4 repeticoes
int aux2;			// variavel para 

F2L_ini:
aux2 = 0;
F2L_1:		// o algoritmo deve tentar 4 para cada canto

aux1 = 0;
F2L_3M:
// caso R7
if( m[4][7] == m[1][4] && m[4][2] == m[0][4] && m[3][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] ){
	move(0);move(4);move(8+0);
}
else if( m[4][5] == m[2][4] && m[4][0] == m[1][4] && m[0][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] ){
	move(1);move(4);move(8+1);
}
else if( m[4][1] == m[3][4] && m[4][6] == m[2][4] && m[1][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] ){
	move(2);move(4);move(8+2);
}
else if( m[4][3] == m[0][4] && m[4][8] == m[3][4] && m[2][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] ){
	move(3);move(4);move(8+3);
}

// caso F7
else if( m[4][3] == m[0][4] && m[4][2] == m[1][4] && m[2][7] == m[1][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] ){
	move(8+1);move(8+4);move(1);
}
else if( m[4][7] == m[1][4] && m[4][0] == m[2][4] && m[3][7] == m[2][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] ){
	move(8+2);move(8+4);move(2);
}
else if( m[4][5] == m[2][4] && m[4][6] == m[3][4] && m[0][7] == m[3][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] ){
	move(8+3);move(8+4);move(3);
}
else if( m[4][1] == m[3][4] && m[4][8] == m[0][4] && m[1][7] == m[0][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] ){
	move(8+0);move(8+4);move(0);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_3M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_4M:
// caso R3
if( m[4][1] == m[0][4] && m[4][2] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] ){
	move(8+4);move(8+1);move(4);move(1);
}
else if( m[4][3] == m[1][4] && m[4][0] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] ){
	move(8+4);move(8+2);move(4);move(2);
}
else if( m[4][7] == m[2][4] && m[4][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] ){
	move(8+4);move(8+3);move(4);move(3);
}
else if( m[4][5] == m[3][4] && m[4][8] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] ){
	move(8+4);move(8+0);move(4);move(0);
}

// caso F3
else if( m[4][5] == m[1][4] && m[4][2] == m[1][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] ){
	move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][1] == m[2][4] && m[4][0] == m[2][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] ){
	move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][3] == m[3][4] && m[4][6] == m[3][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] ){
	move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][7] == m[0][4] && m[4][8] == m[0][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] ){
	move(4);move(3);move(8+4);move(8+3);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_4M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_7M:
// caso Fd3
if( m[4][1] == m[0][4] && m[1][7] == m[1][4] && m[1][2] == m[5][4] && m[0][0] == m[1][4] && m[5][8] == m[0][4] ){
	move(8+1);move(8+4);move(1);move(4);move(8+1);move(8+4);move(1);
}
else if( m[4][3] == m[1][4] && m[2][7] == m[2][4] && m[2][2] == m[5][4] && m[1][0] == m[2][4] && m[5][6] == m[1][4] ){
	move(8+2);move(8+4);move(2);move(4);move(8+2);move(8+4);move(2);
}
else if( m[4][7] == m[2][4] && m[3][7] == m[3][4] && m[3][2] == m[5][4] && m[2][0] == m[3][4] && m[5][0] == m[2][4] ){
	move(8+3);move(8+4);move(3);move(4);move(8+3);move(8+4);move(3);
}
else if( m[4][5] == m[3][4] && m[0][7] == m[0][4] && m[0][2] == m[5][4] && m[3][0] == m[0][4] && m[5][2] == m[3][4] ){
	move(8+0);move(8+4);move(0);move(4);move(8+0);move(8+4);move(0);
}

// caso Fd4
else if( m[4][5] == m[1][4] && m[0][7] == m[0][4] && m[1][2] == m[5][4] && m[0][0] == m[1][4] && m[5][8] == m[0][4] ){
	move(0);move(8+4);move(8+0);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][1] == m[2][4] && m[1][7] == m[1][4] && m[2][2] == m[5][4] && m[1][0] == m[2][4] && m[5][6] == m[1][4] ){
	move(1);move(8+4);move(8+1);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][3] == m[3][4] && m[2][7] == m[2][4] && m[3][2] == m[5][4] && m[2][0] == m[3][4] && m[5][0] == m[2][4] ){
	move(2);move(8+4);move(8+2);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][7] == m[0][4] && m[3][7] == m[3][4] && m[0][2] == m[5][4] && m[3][0] == m[0][4] && m[5][2] == m[3][4] ){
	move(3);move(8+4);move(8+3);move(4);move(3);move(8+4);move(8+3);
}

// caso Rd3
else if( m[4][1] == m[0][4] && m[1][7] == m[1][4] && m[1][2] == m[0][4] && m[0][0] == m[5][4] && m[5][8] == m[1][4] ){
	move(8+1);move(4);move(1);move(8+4);move(8+1);move(4);move(1);
}
else if( m[4][3] == m[1][4] && m[2][7] == m[2][4] && m[2][2] == m[1][4] && m[1][0] == m[5][4] && m[5][6] == m[2][4] ){
	move(8+2);move(4);move(2);move(8+4);move(8+2);move(4);move(2);
}
else if( m[4][7] == m[2][4] && m[3][7] == m[3][4] && m[3][2] == m[2][4] && m[2][0] == m[5][4] && m[5][0] == m[3][4] ){
	move(8+3);move(4);move(3);move(8+4);move(8+3);move(4);move(3);
}
else if( m[4][5] == m[3][4] && m[0][7] == m[0][4] && m[0][2] == m[3][4] && m[3][0] == m[5][4] && m[5][2] == m[0][4] ){
	move(8+0);move(4);move(0);move(8+4);move(8+0);move(4);move(0);
}

// caso Rd4
else if( m[4][5] == m[1][4] && m[0][7] == m[0][4] && m[1][2] == m[0][4] && m[0][0] == m[5][4] && m[5][8] == m[1][4] ){
	move(0);move(4);move(8+0);move(8+4);move(0);move(4);move(8+0);
}
else if( m[4][1] == m[2][4] && m[1][7] == m[1][4] && m[2][2] == m[1][4] && m[1][0] == m[5][4] && m[5][6] == m[2][4] ){
	move(1);move(4);move(8+1);move(8+4);move(1);move(4);move(8+1);
}
else if( m[4][3] == m[3][4] && m[2][7] == m[2][4] && m[3][2] == m[2][4] && m[2][0] == m[5][4] && m[5][0] == m[3][4] ){
	move(2);move(4);move(8+2);move(8+4);move(2);move(4);move(8+2);
}
else if( m[4][7] == m[0][4] && m[3][7] == m[3][4] && m[0][2] == m[3][4] && m[3][0] == m[5][4] && m[5][2] == m[0][4] ){
	move(3);move(4);move(8+3);move(8+4);move(3);move(4);move(8+3);
}

// caso U2
else if( m[4][2] == m[5][4] && m[1][8] == m[0][4] && m[0][6] == m[1][4] && m[1][5] == m[0][4] && m[0][3] == m[1][4] ){
	move(0);move(8+4);move(8+0);move(8+1);move(4);move(4);move(1);
}
else if( m[4][0] == m[5][4] && m[2][8] == m[1][4] && m[1][6] == m[2][4] && m[2][5] == m[1][4] && m[1][3] == m[2][4] ){
	move(1);move(8+4);move(8+1);move(8+2);move(4);move(4);move(2);
}
else if( m[4][6] == m[5][4] && m[3][8] == m[2][4] && m[2][6] == m[3][4] && m[3][5] == m[2][4] && m[2][3] == m[3][4] ){
	move(2);move(8+4);move(8+2);move(8+3);move(4);move(4);move(3);
}
else if( m[4][8] == m[5][4] && m[0][8] == m[3][4] && m[3][6] == m[0][4] && m[0][5] == m[3][4] && m[3][3] == m[0][4] ){
	move(3);move(8+4);move(8+3);move(8+0);move(4);move(4);move(0);
}

// caso U6
else if( m[4][6] == m[5][4] && m[4][5] == m[1][4] && m[3][8] == m[0][4] && m[2][6] == m[1][4] && m[0][7] == m[0][4] ){
	move(0);move(4);move(8+0);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][8] == m[5][4] && m[4][1] == m[2][4] && m[0][8] == m[1][4] && m[3][6] == m[2][4] && m[1][7] == m[1][4] ){
	move(1);move(4);move(8+1);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][2] == m[5][4] && m[4][3] == m[3][4] && m[1][8] == m[2][4] && m[0][6] == m[3][4] && m[2][7] == m[2][4] ){
	move(2);move(4);move(8+2);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][0] == m[5][4] && m[4][7] == m[0][4] && m[2][8] == m[3][4] && m[1][6] == m[0][4] && m[3][7] == m[3][4] ){
	move(3);move(4);move(8+3);move(4);move(3);move(8+4);move(8+3);
}

// caso U7
else if( m[4][6] == m[5][4] && m[4][1] == m[0][4] && m[3][8] == m[0][4] && m[2][6] == m[1][4] && m[1][7] == m[1][4] ){
	move(8+1);move(8+4);move(1);move(8+4);move(8+1);move(4);move(1);
}
else if( m[4][8] == m[5][4] && m[4][3] == m[1][4] && m[0][8] == m[1][4] && m[3][6] == m[2][4] && m[2][7] == m[2][4] ){
	move(8+2);move(8+4);move(2);move(8+4);move(8+2);move(4);move(2);
}
else if( m[4][2] == m[5][4] && m[4][7] == m[2][4] && m[1][8] == m[2][4] && m[0][6] == m[3][4] && m[3][7] == m[3][4] ){
	move(8+3);move(8+4);move(3);move(8+4);move(8+3);move(4);move(3);
}
else if( m[4][0] == m[5][4] && m[4][5] == m[3][4] && m[2][8] == m[3][4] && m[1][6] == m[0][4] && m[0][7] == m[0][4] ){
	move(8+0);move(8+4);move(0);move(8+4);move(8+0);move(4);move(0);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_7M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_8M:
// caso Dd2
if( m[4][1] == m[0][4] && m[1][7] == m[1][4] && m[1][2] == m[1][4] && m[0][0] == m[0][4] && m[5][8] == m[5][4] ){
	move(4);move(0);move(8+4);move(8+0);move(8+4);move(8+1);move(4);move(1);
}
else if( m[4][3] == m[1][4] && m[2][7] == m[2][4] && m[2][2] == m[2][4] && m[1][0] == m[1][4] && m[5][6] == m[5][4] ){
	move(4);move(1);move(8+4);move(8+1);move(8+4);move(8+2);move(4);move(2);
}
else if( m[4][7] == m[2][4] && m[3][7] == m[3][4] && m[3][2] == m[3][4] && m[2][0] == m[2][4] && m[5][0] == m[5][4] ){
	move(4);move(2);move(8+4);move(8+2);move(8+4);move(8+3);move(4);move(3);
}
else if( m[4][5] == m[3][4] && m[0][7] == m[0][4] && m[0][2] == m[0][4] && m[3][0] == m[3][4] && m[5][2] == m[5][4] ){
	move(4);move(3);move(8+4);move(8+3);move(8+4);move(8+0);move(4);move(0);
}

// caso Dd3
else if( m[4][5] == m[1][4] && m[0][7] == m[0][4] && m[1][2] == m[1][4] && m[0][0] == m[0][4] && m[5][8] == m[5][4] ){
	move(8+4);move(8+1);move(4);move(1);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][1] == m[2][4] && m[1][7] == m[1][4] && m[2][2] == m[2][4] && m[1][0] == m[1][4] && m[5][6] == m[5][4] ){
	move(8+4);move(8+2);move(4);move(2);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][3] == m[3][4] && m[2][7] == m[2][4] && m[3][2] == m[3][4] && m[2][0] == m[2][4] && m[5][0] == m[5][4] ){
	move(8+4);move(8+3);move(4);move(3);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][7] == m[0][4] && m[3][7] == m[3][4] && m[0][2] == m[0][4] && m[3][0] == m[3][4] && m[5][2] == m[5][4] ){
	move(8+4);move(8+0);move(4);move(0);move(4);move(3);move(8+4);move(8+3);
}

// caso U3
else if( m[4][1] == m[0][4] && m[4][2] == m[5][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[1][4] ){
	move(8+1);move(4);move(4);move(1);move(4);move(8+1);move(8+4);move(1);
}
else if( m[4][3] == m[1][4] && m[4][0] == m[5][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[2][4] ){
	move(8+2);move(4);move(4);move(2);move(4);move(8+2);move(8+4);move(2);
}
else if( m[4][7] == m[2][4] && m[4][6] == m[5][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[3][4] ){
	move(8+3);move(4);move(4);move(3);move(4);move(8+3);move(8+4);move(3);
}
else if( m[4][5] == m[3][4] && m[4][8] == m[5][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[0][4] ){
	move(8+0);move(4);move(4);move(0);move(4);move(8+0);move(8+4);move(0);
}

// caso U5
else if( m[4][8] == m[5][4] && m[4][1] == m[0][4] && m[3][6] == m[1][4] && m[1][7] == m[1][4] && m[0][8] == m[0][4] ){
	move(8+1);move(4);move(4);move(1);move(8+4);move(8+1);move(4);move(1);
}
else if( m[4][2] == m[5][4] && m[4][3] == m[1][4] && m[0][6] == m[2][4] && m[2][7] == m[2][4] && m[1][8] == m[1][4] ){
	move(8+2);move(4);move(4);move(2);move(8+4);move(8+2);move(4);move(2);
}
else if( m[4][0] == m[5][4] && m[4][7] == m[2][4] && m[1][6] == m[3][4] && m[3][7] == m[3][4] && m[2][8] == m[2][4] ){
	move(8+3);move(4);move(4);move(3);move(8+4);move(8+3);move(4);move(3);
}
else if( m[4][6] == m[5][4] && m[4][5] == m[3][4] && m[2][6] == m[0][4] && m[0][7] == m[0][4] && m[3][8] == m[3][4] ){
	move(8+0);move(4);move(4);move(0);move(8+4);move(8+0);move(4);move(0);
}

// caso U8
else if( m[4][5] == m[1][4] && m[4][0] == m[5][4] && m[2][8] == m[0][4] && m[1][6] == m[1][4] && m[0][7] == m[0][4] ){
	move(0);move(4);move(4);move(8+0);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][1] == m[2][4] && m[4][6] == m[5][4] && m[3][8] == m[1][4] && m[2][6] == m[2][4] && m[1][7] == m[1][4] ){
	move(1);move(4);move(4);move(8+1);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][3] == m[3][4] && m[4][8] == m[5][4] && m[0][8] == m[2][4] && m[3][6] == m[3][4] && m[2][7] == m[2][4] ){
	move(2);move(4);move(4);move(8+2);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][7] == m[0][4] && m[4][2] == m[5][4] && m[1][8] == m[3][4] && m[0][6] == m[0][4] && m[3][7] == m[3][4] ){
	move(3);move(4);move(4);move(8+3);move(4);move(3);move(8+4);move(8+3);
}

// caso U10
else if( m[4][5] == m[1][4] && m[4][2] == m[5][4] && m[1][8] == m[0][4] && m[0][6] == m[1][4] && m[0][7] == m[0][4] ){
	move(0);move(4);move(4);move(8+0);move(8+4);move(0);move(4);move(8+0);
}
else if( m[4][1] == m[2][4] && m[4][0] == m[5][4] && m[2][8] == m[1][4] && m[1][6] == m[2][4] && m[1][7] == m[1][4] ){
	move(1);move(4);move(4);move(8+1);move(8+4);move(1);move(4);move(8+1);
}
else if( m[4][3] == m[3][4] && m[4][6] == m[5][4] && m[3][8] == m[2][4] && m[2][6] == m[3][4] && m[2][7] == m[2][4] ){
	move(2);move(4);move(4);move(8+2);move(8+4);move(2);move(4);move(8+2);
}
else if( m[4][7] == m[0][4] && m[4][8] == m[5][4] && m[0][8] == m[3][4] && m[3][6] == m[0][4] && m[3][7] == m[3][4] ){
	move(3);move(4);move(4);move(8+3);move(8+4);move(3);move(4);move(8+3);
}

// caso F9
else if( m[4][7] == m[0][4] && m[4][2] == m[1][4] && m[3][7] == m[1][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] ){
	move(4);move(8+1);move(8+4);move(1);move(8+4);move(8+1);move(8+4);move(1);
}
else if( m[4][5] == m[1][4] && m[4][0] == m[2][4] && m[0][7] == m[2][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] ){
	move(4);move(8+2);move(8+4);move(2);move(8+4);move(8+2);move(8+4);move(2);
}
else if( m[4][1] == m[2][4] && m[4][6] == m[3][4] && m[1][7] == m[3][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] ){
	move(4);move(8+3);move(8+4);move(3);move(8+4);move(8+3);move(8+4);move(3);
}
else if( m[4][3] == m[3][4] && m[4][8] == m[0][4] && m[2][7] == m[0][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] ){
	move(4);move(8+0);move(8+4);move(0);move(8+4);move(8+0);move(8+4);move(0);
}

// caso F6
else if( m[4][1] == m[0][4] && m[4][2] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] ){
	move(4);move(8+1);move(4);move(1);move(8+4);move(8+1);move(8+4);move(1);
}
else if( m[4][3] == m[1][4] && m[4][0] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] ){
	move(4);move(8+2);move(4);move(2);move(8+4);move(8+2);move(8+4);move(2);
}
else if( m[4][7] == m[2][4] && m[4][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] ){
	move(4);move(8+3);move(4);move(3);move(8+4);move(8+3);move(8+4);move(3);
}
else if( m[4][5] == m[3][4] && m[4][8] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] ){
	move(4);move(8+0);move(4);move(0);move(8+4);move(8+0);move(8+4);move(0);
}

// caso R2
else if( m[4][2] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] && m[1][5] == m[0][4] && m[0][3] == m[1][4] ){
	move(4);move(8+1);move(8+4);move(1);move(8+4);move(0);move(4);move(8+0);
}
else if( m[4][0] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] && m[2][5] == m[1][4] && m[1][3] == m[2][4] ){
	move(4);move(8+2);move(8+4);move(2);move(8+4);move(1);move(4);move(8+1);
}
else if( m[4][6] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] && m[3][5] == m[2][4] && m[2][3] == m[3][4] ){
	move(4);move(8+3);move(8+4);move(3);move(8+4);move(2);move(4);move(8+2);
}
else if( m[4][8] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] && m[0][5] == m[3][4] && m[3][3] == m[0][4] ){
	move(4);move(8+0);move(8+4);move(0);move(8+4);move(3);move(4);move(8+3);
}

// caso F5
else if( m[4][1] == m[1][4] && m[4][2] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] ){
	move(8+1);move(4);move(1);move(8+4);move(8+4);move(0);move(4);move(8+0);
}
else if( m[4][3] == m[2][4] && m[4][0] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] ){
	move(8+2);move(4);move(2);move(8+4);move(8+4);move(1);move(4);move(8+1);
}
else if( m[4][7] == m[3][4] && m[4][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] ){
	move(8+3);move(4);move(3);move(8+4);move(8+4);move(2);move(4);move(8+2);
}
else if( m[4][5] == m[0][4] && m[4][8] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] ){
	move(8+0);move(4);move(0);move(8+4);move(8+4);move(3);move(4);move(8+3);
}

// caso R5
else if( m[4][5] == m[0][4] && m[4][2] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] && m[0][7] == m[1][4] ){
	move(0);move(8+4);move(8+0);move(4);move(4);move(8+1);move(8+4);move(1);
}
else if( m[4][1] == m[1][4] && m[4][0] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] && m[1][7] == m[2][4] ){
	move(1);move(8+4);move(8+1);move(4);move(4);move(8+2);move(8+4);move(2);
}
else if( m[4][3] == m[2][4] && m[4][6] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] && m[2][7] == m[3][4] ){
	move(2);move(8+4);move(8+2);move(4);move(4);move(8+3);move(8+4);move(3);
}
else if( m[4][7] == m[3][4] && m[4][8] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] && m[3][7] == m[0][4] ){
	move(3);move(8+4);move(8+3);move(4);move(4);move(8+0);move(8+4);move(0);
}

// caso R6
else if( m[4][5] == m[1][4] && m[4][2] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] && m[0][7] == m[0][4] ){
	move(8+4);move(0);move(8+4);move(8+0);move(4);move(0);move(4);move(8+0);
}
else if( m[4][1] == m[2][4] && m[4][0] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] && m[1][7] == m[1][4] ){
	move(8+4);move(1);move(8+4);move(8+1);move(4);move(1);move(4);move(8+1);
}
else if( m[4][3] == m[3][4] && m[4][6] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] && m[2][7] == m[2][4] ){
	move(8+4);move(2);move(8+4);move(8+2);move(4);move(2);move(4);move(8+2);
}
else if( m[4][7] == m[0][4] && m[4][8] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] && m[3][7] == m[3][4] ){
	move(8+4);move(3);move(8+4);move(8+3);move(4);move(3);move(4);move(8+3);
}

// caso R9
else if( m[4][3] == m[1][4] && m[4][2] == m[0][4] && m[2][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] ){
	move(8+4);move(0);move(4);move(8+0);move(4);move(0);move(4);move(8+0);
}
else if( m[4][7] == m[2][4] && m[4][0] == m[1][4] && m[3][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] ){
	move(8+4);move(1);move(4);move(8+1);move(4);move(1);move(4);move(8+1);
}
else if( m[4][5] == m[3][4] && m[4][6] == m[2][4] && m[0][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] ){
	move(8+4);move(2);move(4);move(8+2);move(4);move(2);move(4);move(8+2);
}
else if( m[4][1] == m[0][4] && m[4][8] == m[3][4] && m[1][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] ){
	move(8+4);move(3);move(4);move(8+3);move(4);move(3);move(4);move(8+3);
}

// caso F2
else if( m[4][2] == m[1][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] && m[1][5] == m[0][4] && m[0][3] == m[1][4] ){
	move(8+4);move(0);move(4);move(8+0);move(4);move(8+1);move(8+4);move(1);
}
else if( m[4][0] == m[2][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] && m[2][5] == m[1][4] && m[1][3] == m[2][4] ){
	move(8+4);move(1);move(4);move(8+1);move(4);move(8+2);move(8+4);move(2);
}
else if( m[4][6] == m[3][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] && m[3][5] == m[2][4] && m[2][3] == m[3][4] ){
	move(8+4);move(2);move(4);move(8+2);move(4);move(8+3);move(8+4);move(3);
}
else if( m[4][8] == m[0][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] && m[0][5] == m[3][4] && m[3][3] == m[0][4] ){
	move(8+4);move(3);move(4);move(8+3);move(4);move(8+0);move(8+4);move(0);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_8M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_9M:
// caso Fd2
if( m[1][5] == m[0][4] && m[0][3] == m[1][4] && m[1][2] == m[5][4] && m[0][0] == m[1][4] && m[5][8] == m[0][4] ){
	move(8+1);move(8+2);move(4);move(4);move(2);move(1);move(0);move(4);move(8+0);
}
else if( m[2][5] == m[1][4] && m[1][3] == m[2][4] && m[2][2] == m[5][4] && m[1][0] == m[2][4] && m[5][6] == m[1][4] ){
	move(8+2);move(8+3);move(4);move(4);move(3);move(2);move(1);move(4);move(8+1);
}
else if( m[3][5] == m[2][4] && m[2][3] == m[3][4] && m[3][2] == m[5][4] && m[2][0] == m[3][4] && m[5][0] == m[2][4] ){
	move(8+3);move(8+0);move(4);move(4);move(0);move(3);move(2);move(4);move(8+2);
}
else if( m[0][5] == m[3][4] && m[3][3] == m[0][4] && m[0][2] == m[5][4] && m[3][0] == m[0][4] && m[5][2] == m[3][4] ){
	move(8+0);move(8+1);move(4);move(4);move(1);move(0);move(3);move(4);move(8+3);
}

// caso Rd2
else if( m[1][5] == m[0][4] && m[0][3] == m[1][4] && m[1][2] == m[0][4] && m[0][0] == m[5][4] && m[5][8] == m[1][4] ){
	move(0);move(8+4);move(8+0);move(8+1);move(8+2);move(4);move(4);move(2);move(1);
}
else if( m[2][5] == m[1][4] && m[1][3] == m[2][4] && m[2][2] == m[1][4] && m[1][0] == m[5][4] && m[5][6] == m[2][4] ){
	move(1);move(8+4);move(8+1);move(8+2);move(8+3);move(4);move(4);move(3);move(2);
}
else if( m[3][5] == m[2][4] && m[2][3] == m[3][4] && m[3][2] == m[2][4] && m[2][0] == m[5][4] && m[5][0] == m[3][4] ){
	move(2);move(8+4);move(8+2);move(8+3);move(8+0);move(4);move(4);move(0);move(3);
}
else if( m[0][5] == m[3][4] && m[3][3] == m[0][4] && m[0][2] == m[3][4] && m[3][0] == m[5][4] && m[5][2] == m[0][4] ){
	move(3);move(8+4);move(8+3);move(8+0);move(8+1);move(4);move(4);move(1);move(0);
}

// caso F10
else if( m[4][7] == m[1][4] && m[4][2] == m[1][4] && m[3][7] == m[0][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] ){
	move(8+4);move(0);move(4);move(8+0);move(4);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][5] == m[2][4] && m[4][0] == m[2][4] && m[0][7] == m[1][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] ){
	move(8+4);move(1);move(4);move(8+1);move(4);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][1] == m[3][4] && m[4][6] == m[3][4] && m[1][7] == m[2][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] ){
	move(8+4);move(2);move(4);move(8+2);move(4);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][3] == m[0][4] && m[4][8] == m[0][4] && m[2][7] == m[3][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] ){
	move(8+4);move(3);move(4);move(8+3);move(4);move(4);move(3);move(8+4);move(8+3);
}

// caso R1
else if( m[4][2] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] && m[1][5] == m[1][4] && m[0][3] == m[0][4] ){
	move(4);move(8+1);move(4);move(1);move(4);move(4);move(8+1);move(4);move(1);
}
else if( m[4][0] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] && m[2][5] == m[2][4] && m[1][3] == m[1][4] ){
	move(4);move(8+2);move(4);move(2);move(4);move(4);move(8+2);move(4);move(2);
}
else if( m[4][6] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] && m[3][5] == m[3][4] && m[2][3] == m[2][4] ){
	move(4);move(8+3);move(4);move(3);move(4);move(4);move(8+3);move(4);move(3);
}
else if( m[4][8] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] && m[0][5] == m[0][4] && m[3][3] == m[3][4] ){
	move(4);move(8+0);move(4);move(0);move(4);move(4);move(8+0);move(4);move(0);
}

// caso R4
else if( m[4][1] == m[1][4] && m[4][2] == m[0][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] ){
	move(4);move(8+1);move(4);move(4);move(1);move(8+4);move(0);move(4);move(8+0);
}
else if( m[4][3] == m[2][4] && m[4][0] == m[1][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] ){
	move(4);move(8+2);move(4);move(4);move(2);move(8+4);move(1);move(4);move(8+1);
}
else if( m[4][7] == m[3][4] && m[4][6] == m[2][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] ){
	move(4);move(8+3);move(4);move(4);move(3);move(8+4);move(2);move(4);move(8+2);
}
else if( m[4][5] == m[0][4] && m[4][8] == m[3][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] ){
	move(4);move(8+0);move(4);move(4);move(0);move(8+4);move(3);move(4);move(8+3);
}

// caso R10
else if( m[4][3] == m[0][4] && m[4][2] == m[0][4] && m[2][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] ){
	move(4);move(8+1);move(8+4);move(1);move(4);move(4);move(8+1);move(4);move(1);
}
else if( m[4][7] == m[1][4] && m[4][0] == m[1][4] && m[3][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] ){
	move(4);move(8+2);move(8+4);move(2);move(4);move(4);move(8+2);move(4);move(2);
}
else if( m[4][5] == m[2][4] && m[4][6] == m[2][4] && m[0][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] ){
	move(4);move(8+3);move(8+4);move(3);move(4);move(4);move(8+3);move(4);move(3);
}
else if( m[4][1] == m[3][4] && m[4][8] == m[3][4] && m[1][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] ){
	move(4);move(8+0);move(8+4);move(0);move(4);move(4);move(8+0);move(4);move(0);
}

// caso F1
else if( m[4][2] == m[1][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] && m[1][5] == m[1][4] && m[0][3] == m[0][4] ){
	move(8+4);move(0);move(8+4);move(8+0);move(4);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][0] == m[2][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] && m[2][5] == m[2][4] && m[1][3] == m[1][4] ){
	move(8+4);move(1);move(8+4);move(8+1);move(4);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][6] == m[3][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] && m[3][5] == m[3][4] && m[2][3] == m[2][4] ){
	move(8+4);move(2);move(8+4);move(8+2);move(4);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][8] == m[0][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] && m[0][5] == m[0][4] && m[3][3] == m[3][4] ){
	move(8+4);move(3);move(8+4);move(8+3);move(4);move(4);move(3);move(8+4);move(8+3);
}

// caso F4
else if( m[4][5] == m[0][4] && m[4][2] == m[1][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] && m[0][7] == m[1][4] ){
	move(8+4);move(0);move(4);move(4);move(8+0);move(4);move(8+1);move(8+4);move(1);
}
else if( m[4][1] == m[1][4] && m[4][0] == m[2][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] && m[1][7] == m[2][4] ){
	move(8+4);move(1);move(4);move(4);move(8+1);move(4);move(8+2);move(8+4);move(2);
}
else if( m[4][3] == m[2][4] && m[4][6] == m[3][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] && m[2][7] == m[3][4] ){
	move(8+4);move(2);move(4);move(4);move(8+2);move(4);move(8+3);move(8+4);move(3);
}
else if( m[4][7] == m[3][4] && m[4][8] == m[0][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] && m[3][7] == m[0][4] ){
	move(8+4);move(3);move(4);move(4);move(8+3);move(4);move(8+0);move(8+4);move(0);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_9M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_10M:
// caso R8
if( m[4][7] == m[0][4] && m[4][2] == m[0][4] && m[3][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[5][4] ){
	move(4);move(8+1);move(4);move(4);move(1);move(4);move(4);move(8+1);move(4);move(1);
}
else if( m[4][5] == m[1][4] && m[4][0] == m[1][4] && m[0][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[5][4] ){
	move(4);move(8+2);move(4);move(4);move(2);move(4);move(4);move(8+2);move(4);move(2);
}
else if( m[4][1] == m[2][4] && m[4][6] == m[2][4] && m[1][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[5][4] ){
	move(4);move(8+3);move(4);move(4);move(3);move(4);move(4);move(8+3);move(4);move(3);
}
else if( m[4][3] == m[3][4] && m[4][8] == m[3][4] && m[2][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[5][4] ){
	move(4);move(8+0);move(4);move(4);move(0);move(4);move(4);move(8+0);move(4);move(0);
}

// caso F8
else if( m[4][3] == m[1][4] && m[4][2] == m[1][4] && m[2][7] == m[0][4] && m[1][8] == m[5][4] && m[0][6] == m[0][4] ){
	move(8+4);move(0);move(4);move(4);move(8+0);move(4);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][7] == m[2][4] && m[4][0] == m[2][4] && m[3][7] == m[1][4] && m[2][8] == m[5][4] && m[1][6] == m[1][4] ){
	move(8+4);move(1);move(4);move(4);move(8+1);move(4);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][5] == m[3][4] && m[4][6] == m[3][4] && m[0][7] == m[2][4] && m[3][8] == m[5][4] && m[2][6] == m[2][4] ){
	move(8+4);move(2);move(4);move(4);move(8+2);move(4);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][1] == m[0][4] && m[4][8] == m[0][4] && m[1][7] == m[3][4] && m[0][8] == m[5][4] && m[3][6] == m[3][4] ){
	move(8+4);move(3);move(4);move(4);move(8+3);move(4);move(4);move(3);move(8+4);move(8+3);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_10M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_11M:
// caso U1
if( m[4][2] == m[5][4] && m[1][8] == m[0][4] && m[0][6] == m[1][4] && m[1][5] == m[1][4] && m[0][3] == m[0][4] ){
	move(0);move(4);move(8+0);move(8+4);move(0);move(4);move(8+0);move(8+4);move(0);move(4);move(8+0);
}
else if( m[4][0] == m[5][4] && m[2][8] == m[1][4] && m[1][6] == m[2][4] && m[2][5] == m[2][4] && m[1][3] == m[1][4] ){
	move(1);move(4);move(8+1);move(8+4);move(1);move(4);move(8+1);move(8+4);move(1);move(4);move(8+1);
}
else if( m[4][6] == m[5][4] && m[3][8] == m[2][4] && m[2][6] == m[3][4] && m[3][5] == m[3][4] && m[2][3] == m[2][4] ){
	move(2);move(4);move(8+2);move(8+4);move(2);move(4);move(8+2);move(8+4);move(2);move(4);move(8+2);
}
else if( m[4][8] == m[5][4] && m[0][8] == m[3][4] && m[3][6] == m[0][4] && m[0][5] == m[0][4] && m[3][3] == m[3][4] ){
	move(3);move(4);move(8+3);move(8+4);move(3);move(4);move(8+3);move(8+4);move(3);move(4);move(8+3);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_11M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_12M:
// caso Rd1
if( m[1][5] == m[1][4] && m[0][3] == m[0][4] && m[1][2] == m[0][4] && m[0][0] == m[5][4] && m[5][8] == m[1][4] ){
	move(0);move(4);move(4);move(0);move(4);move(8+0);move(4);move(0);move(4);move(4);move(0);move(0);
}
else if( m[2][5] == m[2][4] && m[1][3] == m[1][4] && m[2][2] == m[1][4] && m[1][0] == m[5][4] && m[5][6] == m[2][4] ){
	move(1);move(4);move(4);move(1);move(4);move(8+1);move(4);move(1);move(4);move(4);move(1);move(1);
}
else if( m[3][5] == m[3][4] && m[2][3] == m[2][4] && m[3][2] == m[2][4] && m[2][0] == m[5][4] && m[5][0] == m[3][4] ){
	move(2);move(4);move(4);move(2);move(4);move(8+2);move(4);move(2);move(4);move(4);move(2);move(2);
}
else if( m[0][5] == m[0][4] && m[3][3] == m[3][4] && m[0][2] == m[3][4] && m[3][0] == m[5][4] && m[5][2] == m[0][4] ){
	move(3);move(4);move(4);move(3);move(4);move(8+3);move(4);move(3);move(4);move(4);move(3);move(3);
}

// caso U4
else if( m[4][1] == m[1][4] && m[4][2] == m[5][4] && m[1][7] == m[0][4] && m[1][8] == m[0][4] && m[0][6] == m[1][4] ){
	move(4);move(4);move(0);move(0);move(4);move(4);move(8+0);move(8+4);move(0);move(8+4);move(0);move(0);
}
else if( m[4][3] == m[2][4] && m[4][0] == m[5][4] && m[2][7] == m[1][4] && m[2][8] == m[1][4] && m[1][6] == m[2][4] ){
	move(4);move(4);move(1);move(1);move(4);move(4);move(8+1);move(8+4);move(1);move(8+4);move(1);move(1);
}
else if( m[4][7] == m[3][4] && m[4][6] == m[5][4] && m[3][7] == m[2][4] && m[3][8] == m[2][4] && m[2][6] == m[3][4] ){
	move(4);move(4);move(2);move(2);move(4);move(4);move(8+2);move(8+4);move(2);move(8+4);move(2);move(2);
}
else if( m[4][5] == m[0][4] && m[4][8] == m[5][4] && m[0][7] == m[3][4] && m[0][8] == m[3][4] && m[3][6] == m[0][4] ){
	move(4);move(4);move(3);move(3);move(4);move(4);move(8+3);move(8+4);move(3);move(8+4);move(3);move(3);
}

// caso U9
else if( m[4][5] == m[0][4] && m[4][2] == m[5][4] && m[1][8] == m[0][4] && m[0][6] == m[1][4] && m[0][7] == m[1][4] ){
	move(4);move(4);move(1);move(1);move(4);move(4);move(1);move(4);move(8+1);move(4);move(1);move(1);
}
else if( m[4][1] == m[1][4] && m[4][0] == m[5][4] && m[2][8] == m[1][4] && m[1][6] == m[2][4] && m[1][7] == m[2][4] ){
	move(4);move(4);move(2);move(2);move(4);move(4);move(2);move(4);move(8+2);move(4);move(2);move(2);
}
else if( m[4][3] == m[2][4] && m[4][6] == m[5][4] && m[3][8] == m[2][4] && m[2][6] == m[3][4] && m[2][7] == m[3][4] ){
	move(4);move(4);move(3);move(3);move(4);move(4);move(3);move(4);move(8+3);move(4);move(3);move(3);
}
else if( m[4][7] == m[3][4] && m[4][8] == m[5][4] && m[0][8] == m[3][4] && m[3][6] == m[0][4] && m[3][7] == m[0][4] ){
	move(4);move(4);move(0);move(0);move(4);move(4);move(0);move(4);move(8+0);move(4);move(0);move(0);
}

// caso Fd1
else if( m[1][5] == m[1][4] && m[0][3] == m[0][4] && m[1][2] == m[5][4] && m[0][0] == m[1][4] && m[5][8] == m[0][4] ){
	move(0);move(0);move(4);move(4);move(8+0);move(8+4);move(0);move(8+4);move(8+0);move(4);move(4);move(8+0);
}
else if( m[2][5] == m[2][4] && m[1][3] == m[1][4] && m[2][2] == m[5][4] && m[1][0] == m[2][4] && m[5][6] == m[1][4] ){
	move(1);move(1);move(4);move(4);move(8+1);move(8+4);move(1);move(8+4);move(8+1);move(4);move(4);move(8+1);
}
else if( m[3][5] == m[3][4] && m[2][3] == m[2][4] && m[3][2] == m[5][4] && m[2][0] == m[3][4] && m[5][0] == m[2][4] ){
	move(2);move(2);move(4);move(4);move(8+2);move(8+4);move(2);move(8+4);move(8+2);move(4);move(4);move(8+2);
}
else if( m[0][5] == m[0][4] && m[3][3] == m[3][4] && m[0][2] == m[5][4] && m[3][0] == m[0][4] && m[5][2] == m[3][4] ){
	move(3);move(3);move(4);move(4);move(8+3);move(8+4);move(3);move(8+4);move(8+3);move(4);move(4);move(8+3);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_12M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


aux1 = 0;
F2L_13M:
// caso Dd1
if( m[1][5] == m[0][4] && m[0][3] == m[1][4] && m[1][2] == m[1][4] && m[0][0] == m[0][4] && m[5][8] == m[5][4] ){
	move(0);move(8+4);move(8+0);move(4);move(8+1);move(4);move(4);move(1);move(4);move(4);move(8+1);move(4);move(1);
}
else if( m[2][5] == m[1][4] && m[1][3] == m[2][4] && m[2][2] == m[2][4] && m[1][0] == m[1][4] && m[5][6] == m[5][4] ){
	move(1);move(8+4);move(8+1);move(4);move(8+2);move(4);move(4);move(2);move(4);move(4);move(8+2);move(4);move(2);
}
else if( m[3][5] == m[2][4] && m[2][3] == m[3][4] && m[3][2] == m[3][4] && m[2][0] == m[2][4] && m[5][0] == m[5][4] ){
	move(2);move(8+4);move(8+2);move(4);move(8+3);move(4);move(4);move(3);move(4);move(4);move(8+3);move(4);move(3);
}
else if( m[0][5] == m[3][4] && m[3][3] == m[0][4] && m[0][2] == m[0][4] && m[3][0] == m[3][4] && m[5][2] == m[5][4] ){
	move(3);move(8+4);move(8+3);move(4);move(8+0);move(4);move(4);move(0);move(4);move(4);move(8+0);move(4);move(0);
}
else if( aux1 < 4 ){
	move(4); aux1++; goto F2L_13M;
}
if( aux1 < 4 ){ F2lCount++; goto F2L_ini; }	// se fez algum dos casos anteriores


// se ja estiver arrumado
if( m[3][3] == m[3][4] && m[3][5] == m[3][4] && m[2][3] == m[2][4] && m[2][5] == m[2][4] && m[1][3] == m[1][4] && m[1][5] == m[1][4] && m[0][3] == m[0][4] && m[0][5] == m[0][4] && m[3][0] == m[3][4] && m[3][2] == m[3][4] && m[2][0] == m[2][4] && m[2][2] == m[2][4] && m[1][0] == m[1][4] && m[1][2] == m[1][4] && m[0][0] == m[0][4] && m[0][2] == m[0][4] && m[5][6] == m[5][4] && m[5][8] == m[5][4] && m[5][0] == m[5][4] && m[5][2] == m[5][4] ){
	F2lCount = 4;
}

// se nenhum dos casos anteriores, rotaciona pra tentar outra posicao
else {
	aux2++;
	if( aux2 < 4 ){
		if( m[1][2] != m[1][4] && m[1][2] == m[5][4] || m[0][0] == m[5][4] || m[5][8] == m[5][4] ){
			move(0);move(8+4);move(8+0);
		}
		else if( m[0][0] != m[0][4] && m[0][0] == m[5][4] || m[1][2] == m[5][4] || m[5][8] == m[5][4] ){
			move(0);move(8+4);move(8+0);
		}
		else if( m[2][2] != m[2][4] && m[2][2] == m[5][4] || m[1][0] == m[5][4] || m[5][6] == m[5][4] ){
			move(1);move(8+4);move(8+1);
		}
		else if( m[1][0] != m[1][4] && m[1][0] == m[5][4] || m[2][2] == m[5][4] || m[5][6] == m[5][4] ){
			move(1);move(8+4);move(8+1);
		}
		else if( m[3][2] != m[3][4] && m[3][2] == m[5][4] || m[2][0] == m[5][4] || m[5][0] == m[5][4] ){
			move(2);move(8+4);move(8+2);
		}
		else if( m[2][0] != m[2][4] && m[2][0] == m[5][4] || m[3][2] == m[5][4] || m[5][0] == m[5][4] ){
			move(2);move(8+4);move(8+2);
		}
		else if( m[0][2] != m[0][4] && m[0][2] == m[5][4] || m[3][0] == m[5][4] || m[5][2] == m[5][4] ){
			move(3);move(8+4);move(8+3);
		}
		else if( m[3][0] != m[3][4] && m[3][0] == m[5][4] || m[0][2] == m[5][4] || m[5][2] == m[5][4] ){
			move(3);move(8+4);move(8+3);
		}
		else if( m[0][3] != m[0][4] || m[1][5] != m[1][4] ){
			move(0);move(8+4);move(8+0);
		}
		else if( m[1][3] != m[1][4] || m[2][5] != m[2][4] ){
			move(1);move(8+4);move(8+1);
		}
		else if( m[2][3] != m[2][4] || m[3][5] != m[3][4] ){
			move(2);move(8+4);move(8+2);
		}
		else if( m[3][3] != m[3][4] || m[0][5] != m[0][4] ){
			move(3);move(8+4);move(8+3);
		}
		goto F2L_1;
	}
}

F2lCount++;
if( F2lCount < 4 ){ goto F2L_ini;}
}

void OLL(){
OLL_1:

// Caso 1
if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] ){
	move(0);move(4);move(4);move(0);move(0);move(8+4);move(0);move(0);move(8+4);move(0);move(0);move(4);move(4);move(0);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] ){
	move(1);move(4);move(4);move(1);move(1);move(8+4);move(1);move(1);move(8+4);move(1);move(1);move(4);move(4);move(1);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] ){
	move(2);move(4);move(4);move(2);move(2);move(8+4);move(2);move(2);move(8+4);move(2);move(2);move(4);move(4);move(2);
}
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] ){
	move(3);move(4);move(4);move(3);move(3);move(8+4);move(3);move(3);move(8+4);move(3);move(3);move(4);move(4);move(3);
}

// Caso 2
else if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(0);move(4);move(8+0);move(4);move(0);move(8+4);move(8+0);move(4);move(0);move(4);move(4);move(8+0);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(1);move(4);move(8+1);move(4);move(1);move(8+4);move(8+1);move(4);move(1);move(4);move(4);move(8+1);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(2);move(4);move(8+2);move(4);move(2);move(8+4);move(8+2);move(4);move(2);move(4);move(4);move(8+2);
}
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(3);move(4);move(8+3);move(4);move(3);move(8+4);move(8+3);move(4);move(3);move(4);move(4);move(8+3);
}

// Caso 3
else if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][0] == m[4][4] && m[4][1] == m[4][4] && m[3][8] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] ){
	move(0);move(4);move(8+0);move(4);move(0);move(4);move(4);move(8+0);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][6] == m[4][4] && m[4][3] == m[4][4] && m[0][8] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] ){
	move(1);move(4);move(8+1);move(4);move(1);move(4);move(4);move(8+1);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][8] == m[4][4] && m[4][7] == m[4][4] && m[1][8] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] ){
	move(2);move(4);move(8+2);move(4);move(2);move(4);move(4);move(8+2);
}
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][2] == m[4][4] && m[4][5] == m[4][4] && m[2][8] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] ){
	move(3);move(4);move(8+3);move(4);move(3);move(4);move(4);move(8+3);
}

// Caso 4
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] ){
	move(8+0);move(8+4);move(0);move(8+4);move(8+0);move(4);move(4);move(0);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] ){
	move(8+1);move(8+4);move(1);move(8+4);move(8+1);move(4);move(4);move(1);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] ){
	move(8+2);move(8+4);move(2);move(8+4);move(8+2);move(4);move(4);move(2);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] ){
	move(8+3);move(8+4);move(3);move(8+4);move(8+3);move(4);move(4);move(3);
}

// Caso 5
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(0);move(0);move(5);move(8+0);move(4);move(4);move(0);move(8+5);move(8+0);move(4);move(4);move(8+0);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(1);move(1);move(5);move(8+1);move(4);move(4);move(1);move(8+5);move(8+1);move(4);move(4);move(8+1);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(2);move(2);move(5);move(8+2);move(4);move(4);move(2);move(8+5);move(8+2);move(4);move(4);move(8+2);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(3);move(3);move(5);move(8+3);move(4);move(4);move(3);move(8+5);move(8+3);move(4);move(4);move(8+3);
}

// Caso 6
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][0] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+0);move(8+1);move(2);move(1);move(0);move(8+1);move(8+2);move(1);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][6] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+1);move(8+2);move(3);move(2);move(1);move(8+2);move(8+3);move(2);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][8] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+2);move(8+3);move(0);move(3);move(2);move(8+3);move(8+0);move(3);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][2] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+3);move(8+0);move(1);move(0);move(3);move(8+0);move(8+1);move(0);
}

// Caso 7
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[1][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+0);move(1);move(0);move(8+3);move(8+0);move(8+1);move(0);move(3);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[2][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+1);move(2);move(1);move(8+0);move(8+1);move(8+2);move(1);move(0);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[3][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+2);move(3);move(2);move(8+1);move(8+2);move(8+3);move(2);move(1);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[0][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+3);move(0);move(3);move(8+2);move(8+3);move(8+0);move(3);move(2);
}

// Caso 8
else if( m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(0);move(4);move(4);move(0);move(0);move(1);move(0);move(8+1);move(4);move(4);move(8+0);move(1);move(0);move(8+1);
}
else if( m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(1);move(4);move(4);move(1);move(1);move(2);move(1);move(8+2);move(4);move(4);move(8+1);move(2);move(1);move(8+2);
}
else if( m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(2);move(4);move(4);move(2);move(2);move(3);move(2);move(8+3);move(4);move(4);move(8+2);move(3);move(2);move(8+3);
}
else if( m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(3);move(4);move(4);move(3);move(3);move(0);move(3);move(8+0);move(4);move(4);move(8+3);move(0);move(3);move(8+0);
}

// Caso 9
else if( m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);move(3);move(4);move(2);move(8+4);move(8+2);move(8+3);
}
else if( m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);move(0);move(4);move(3);move(8+4);move(8+3);move(8+0);
}
else if( m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);move(1);move(4);move(0);move(8+4);move(8+0);move(8+1);
}
else if( m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);move(2);move(4);move(1);move(8+4);move(8+1);move(8+2);
}

// Caso 10
else if( m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(3);move(4);move(2);move(8+4);move(8+2);move(8+3);move(8+4);move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(0);move(4);move(3);move(8+4);move(8+3);move(8+0);move(8+4);move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(1);move(4);move(0);move(8+4);move(8+0);move(8+1);move(8+4);move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(2);move(4);move(1);move(8+4);move(8+1);move(8+2);move(8+4);move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);
}

// Caso 11
else if( m[4][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] ){
	move(3);move(4);move(2);move(8+4);move(8+2);move(8+3);move(4);move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][2] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] ){
	move(0);move(4);move(3);move(8+4);move(8+3);move(8+0);move(4);move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][0] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] ){
	move(1);move(4);move(0);move(8+4);move(8+0);move(8+1);move(4);move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] ){
	move(2);move(4);move(1);move(8+4);move(8+1);move(8+2);move(4);move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);
}

// Caso 12
else if( m[4][0] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(2);move(1);move(1);move(8+0);move(8+1);move(0);move(8+1);move(2);move(2);move(3);move(3);move(0);move(3);move(8+0);move(3);move(2);
}
else if( m[4][6] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(3);move(2);move(2);move(8+1);move(8+2);move(1);move(8+2);move(3);move(3);move(0);move(0);move(1);move(0);move(8+1);move(0);move(3);
}
else if( m[4][8] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(0);move(3);move(3);move(8+2);move(8+3);move(2);move(8+3);move(0);move(0);move(1);move(1);move(2);move(1);move(8+2);move(1);move(0);
}
else if( m[4][2] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(1);move(0);move(0);move(8+3);move(8+0);move(3);move(8+0);move(1);move(1);move(2);move(2);move(3);move(2);move(8+3);move(2);move(1);
}

// Caso 13
else if( m[4][6] == m[4][4] && m[4][8] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(2);move(1);move(8+0);move(1);move(0);move(1);move(1);move(2);move(2);move(8+3);move(0);move(8+3);move(8+0);move(3);move(3);move(2);
}
else if( m[4][8] == m[4][4] && m[4][2] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(3);move(2);move(8+1);move(2);move(1);move(2);move(2);move(3);move(3);move(8+0);move(1);move(8+0);move(8+1);move(0);move(0);move(3);
}
else if( m[4][2] == m[4][4] && m[4][0] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(0);move(3);move(8+2);move(3);move(2);move(3);move(3);move(0);move(0);move(8+1);move(2);move(8+1);move(8+2);move(1);move(1);move(0);
}
else if( m[4][0] == m[4][4] && m[4][6] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(1);move(0);move(8+3);move(0);move(3);move(0);move(0);move(1);move(1);move(8+2);move(3);move(8+2);move(8+3);move(2);move(2);move(1);
}

// Caso 14
else if( m[4][6] == m[4][4] && m[4][2] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(0);move(4);move(8+0);move(4);move(8+0);move(1);move(0);move(8+1);move(4);move(4);move(8+0);move(1);move(0);move(8+1);
}
else if( m[4][8] == m[4][4] && m[4][0] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] ){
	move(1);move(4);move(8+1);move(4);move(8+1);move(2);move(1);move(8+2);move(4);move(4);move(8+1);move(2);move(1);move(8+2);
}
else if( m[4][2] == m[4][4] && m[4][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] ){
	move(2);move(4);move(8+2);move(4);move(8+2);move(3);move(2);move(8+3);move(4);move(4);move(8+2);move(3);move(2);move(8+3);
}
else if( m[4][0] == m[4][4] && m[4][8] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] ){
	move(3);move(4);move(8+3);move(4);move(8+3);move(0);move(3);move(8+0);move(4);move(4);move(8+3);move(0);move(3);move(8+0);
}

// Caso 15
else if( m[4][6] == m[4][4] && m[4][8] == m[4][4] && m[4][0] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(0);move(8+2);move(3);move(0);move(3);move(8+0);move(8+3);move(0);move(0);move(2);move(2);move(1);move(0);move(8+1);move(8+2);
}

// Caso 16
else if( m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);
}

// Caso 17
else if( m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] ){
	move(0);move(4);move(8+0);move(8+4);move(8+0);move(1);move(0);move(8+1);
}
else if( m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] ){
	move(1);move(4);move(8+1);move(8+4);move(8+1);move(2);move(1);move(8+2);
}
else if( m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] ){
	move(2);move(4);move(8+2);move(8+4);move(8+2);move(3);move(2);move(8+3);
}
else if( m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] ){
	move(3);move(4);move(8+3);move(8+4);move(8+3);move(0);move(3);move(8+0);
}

// Caso 18
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][0] == m[4][4] && m[4][1] == m[4][4] && m[2][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+0);move(8+4);move(8+0);move(1);move(0);move(8+1);move(4);move(0);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][6] == m[4][4] && m[4][3] == m[4][4] && m[3][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+1);move(8+4);move(8+1);move(2);move(1);move(8+2);move(4);move(1);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][8] == m[4][4] && m[4][7] == m[4][4] && m[0][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+2);move(8+4);move(8+2);move(3);move(2);move(8+3);move(4);move(2);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][2] == m[4][4] && m[4][5] == m[4][4] && m[1][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+3);move(8+4);move(8+3);move(0);move(3);move(8+0);move(4);move(3);
}

// Caso 19
else if( m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][0] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[1][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(0);move(4);move(0);move(0);move(8+4);move(8+0);move(1);move(0);move(4);move(0);move(8+4);move(8+1);
}
else if( m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][6] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[2][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(1);move(4);move(1);move(1);move(8+4);move(8+1);move(2);move(1);move(4);move(1);move(8+4);move(8+2);
}
else if( m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][8] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[3][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(2);move(4);move(2);move(2);move(8+4);move(8+2);move(3);move(2);move(4);move(2);move(8+4);move(8+3);
}
else if( m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][2] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[0][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(3);move(4);move(3);move(3);move(8+4);move(8+3);move(0);move(3);move(4);move(3);move(8+4);move(8+0);
}

// Caso 20
else if( m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] ){
	move(2);move(1);move(1);move(8+0);move(8+1);move(0);move(8+1);move(8+2);
}
else if( m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] ){
	move(3);move(2);move(2);move(8+1);move(8+2);move(1);move(8+2);move(8+3);
}
else if( m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] ){
	move(0);move(3);move(3);move(8+2);move(8+3);move(2);move(8+3);move(8+0);
}
else if( m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] ){
	move(1);move(0);move(0);move(8+3);move(8+0);move(3);move(8+0);move(8+1);
}

// Caso 21
else if( m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+2);move(3);move(3);move(0);move(3);move(8+0);move(3);move(2);
}
else if( m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+3);move(0);move(0);move(1);move(0);move(8+1);move(0);move(3);
}
else if( m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+0);move(1);move(1);move(2);move(1);move(8+2);move(1);move(0);
}
else if( m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+1);move(2);move(2);move(3);move(2);move(8+3);move(2);move(1);
}

// Caso 22
else if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[3][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(2);move(1);move(8+0);move(1);move(0);move(1);move(1);move(8+2);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[0][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(3);move(2);move(8+1);move(2);move(1);move(2);move(2);move(8+3);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[1][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(0);move(3);move(8+2);move(3);move(2);move(3);move(3);move(8+0);
}
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[2][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(1);move(0);move(8+3);move(0);move(3);move(0);move(0);move(8+1);
}

// Caso 23
else if( m[4][6] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+2);move(8+3);move(0);move(8+3);move(8+0);move(3);move(3);move(2);
}
else if( m[4][8] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+3);move(8+0);move(1);move(8+0);move(8+1);move(0);move(0);move(3);
}
else if( m[4][2] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+0);move(8+1);move(2);move(8+1);move(8+2);move(1);move(1);move(0);
}
else if( m[4][0] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+1);move(8+2);move(3);move(8+2);move(8+3);move(2);move(2);move(1);
}

// Caso 24
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] ){
	move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] ){
	move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] ){
	move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] ){
	move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);
}

// Caso 25
else if( m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(2);move(1);move(8+0);move(1);move(8+0);move(5);move(0);move(8+5);move(0);move(1);move(1);move(8+2);
}
else if( m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(3);move(2);move(8+1);move(2);move(8+1);move(5);move(1);move(8+5);move(1);move(2);move(2);move(8+3);
}
else if( m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(0);move(3);move(8+2);move(3);move(8+2);move(5);move(2);move(8+5);move(2);move(3);move(3);move(8+0);
}
else if( m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(1);move(0);move(8+3);move(0);move(8+3);move(5);move(3);move(8+5);move(3);move(0);move(0);move(8+1);
}

// Caso 26
else if( m[4][6] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+0);move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);move(4);move(0);
}
else if( m[4][8] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+1);move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);move(4);move(1);
}
else if( m[4][2] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+2);move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);move(4);move(2);
}
else if( m[4][0] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+3);move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);move(4);move(3);
}

// Caso 27
else if( m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][0] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(0);move(8+3);move(8+0);move(8+4);move(0);move(4);move(3);move(8+4);move(8+0);
}
else if( m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(1);move(8+0);move(8+1);move(8+4);move(1);move(4);move(0);move(8+4);move(8+1);
}
else if( m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(2);move(8+1);move(8+2);move(8+4);move(2);move(4);move(1);move(8+4);move(8+2);
}
else if( m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][2] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(3);move(8+2);move(8+3);move(8+4);move(3);move(4);move(2);move(8+4);move(8+3);
}

// Caso 28
else if( m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+0);move(4);move(4);move(0);move(0);move(4);move(8+0);move(4);move(0);move(4);move(4);move(8+3);move(8+0);move(3);
}
else if( m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+1);move(4);move(4);move(1);move(1);move(4);move(8+1);move(4);move(1);move(4);move(4);move(8+0);move(8+1);move(0);
}
else if( m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+2);move(4);move(4);move(2);move(2);move(4);move(8+2);move(4);move(2);move(4);move(4);move(8+1);move(8+2);move(1);
}
else if( m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+3);move(4);move(4);move(3);move(3);move(4);move(8+3);move(4);move(3);move(4);move(4);move(8+2);move(8+3);move(2);
}

// Caso 29
else if( m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(0);move(4);move(8+0);move(4);move(0);move(8+4);move(3);move(8+4);move(8+3);move(8+0);
}
else if( m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(1);move(4);move(8+1);move(4);move(1);move(8+4);move(0);move(8+4);move(8+0);move(8+1);
}
else if( m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(2);move(4);move(8+2);move(4);move(2);move(8+4);move(1);move(8+4);move(8+1);move(8+2);
}
else if( m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(3);move(4);move(8+3);move(4);move(3);move(8+4);move(2);move(8+4);move(8+2);move(8+3);
}

// Caso 30
else if( m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(1);move(4);move(0);move(8+4);move(8+0);move(4);move(0);move(8+4);move(8+0);move(8+1);
}
else if( m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(2);move(4);move(1);move(8+4);move(8+1);move(4);move(1);move(8+4);move(8+1);move(8+2);
}
else if( m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(3);move(4);move(2);move(8+4);move(8+2);move(4);move(2);move(8+4);move(8+2);move(8+3);
}
else if( m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(0);move(4);move(3);move(8+4);move(8+3);move(4);move(3);move(8+4);move(8+3);move(8+0);
}

// Caso 31
else if( m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+2);move(8+3);move(2);move(8+4);move(8+0);move(4);move(0);move(8+4);move(8+0);move(4);move(0);move(8+2);move(3);move(2);
}
else if( m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+3);move(8+0);move(3);move(8+4);move(8+1);move(4);move(1);move(8+4);move(8+1);move(4);move(1);move(8+3);move(0);move(3);
}
else if( m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+0);move(8+1);move(0);move(8+4);move(8+2);move(4);move(2);move(8+4);move(8+2);move(4);move(2);move(8+0);move(1);move(0);
}
else if( m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+1);move(8+2);move(1);move(8+4);move(8+3);move(4);move(3);move(8+4);move(8+3);move(4);move(3);move(8+1);move(2);move(1);
}

// Caso 32
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] ){
	move(0);move(4);move(8+3);move(8+4);move(8+0);move(4);move(0);move(3);move(8+0);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] ){
	move(1);move(4);move(8+0);move(8+4);move(8+1);move(4);move(1);move(0);move(8+1);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] ){
	move(2);move(4);move(8+1);move(8+4);move(8+2);move(4);move(2);move(1);move(8+2);
}
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] ){
	move(3);move(4);move(8+2);move(8+4);move(8+3);move(4);move(3);move(2);move(8+3);
}

// Caso 33
else if( m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+0);move(8+4);move(1);move(4);move(0);move(8+4);move(8+0);move(8+1);move(0);
}
else if( m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+1);move(8+4);move(2);move(4);move(1);move(8+4);move(8+1);move(8+2);move(1);
}
else if( m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+2);move(8+4);move(3);move(4);move(2);move(8+4);move(8+2);move(8+3);move(2);
}
else if( m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+3);move(8+4);move(0);move(4);move(3);move(8+4);move(8+3);move(8+0);move(3);
}

// Caso 34
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(3);move(4);move(2);move(8+4);move(8+2);move(8+3);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(0);move(4);move(3);move(8+4);move(8+3);move(8+0);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(1);move(4);move(0);move(8+4);move(8+0);move(8+1);
}
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(2);move(4);move(1);move(8+4);move(8+1);move(8+2);
}

// Caso 35
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+0);move(8+4);move(8+1);move(4);move(1);move(0);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+1);move(8+4);move(8+2);move(4);move(2);move(1);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+2);move(8+4);move(8+3);move(4);move(3);move(2);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+3);move(8+4);move(8+0);move(4);move(0);move(3);
}

// Caso 36
else if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(1);move(0);move(4);move(8+0);move(8+4);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(2);move(1);move(4);move(8+1);move(8+4);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(3);move(2);move(4);move(8+2);move(8+4);move(2);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(0);move(3);move(4);move(8+3);move(8+4);move(3);move(4);move(8+3);move(8+4);move(8+0);
}

// Caso 37
else if( m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+1);move(8+2);move(8+4);move(2);move(4);move(8+2);move(8+4);move(2);move(4);move(1);
}
else if( m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+2);move(8+3);move(8+4);move(3);move(4);move(8+3);move(8+4);move(3);move(4);move(2);
}
else if( m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+3);move(8+0);move(8+4);move(0);move(4);move(8+0);move(8+4);move(0);move(4);move(3);
}
else if( m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+0);move(8+1);move(8+4);move(1);move(4);move(8+1);move(8+4);move(1);move(4);move(0);
}

// Caso 38
else if( m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(2);move(8+1);move(2);move(2);move(3);move(2);move(2);move(1);move(2);move(2);move(8+3);move(2);
}
else if( m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(3);move(8+2);move(3);move(3);move(0);move(3);move(3);move(2);move(3);move(3);move(8+0);move(3);
}
else if( m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(0);move(8+3);move(0);move(0);move(1);move(0);move(0);move(3);move(0);move(0);move(8+1);move(0);
}
else if( m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(1);move(8+0);move(1);move(1);move(2);move(1);move(1);move(0);move(1);move(1);move(8+2);move(1);
}

// Caso 39
else if( m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+2);move(3);move(2);move(2);move(8+1);move(2);move(2);move(8+3);move(2);move(2);move(1);move(8+2);
}
else if( m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+3);move(0);move(3);move(3);move(8+2);move(3);move(3);move(8+0);move(3);move(3);move(2);move(8+3);
}
else if( m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+0);move(1);move(0);move(0);move(8+3);move(0);move(0);move(8+1);move(0);move(0);move(3);move(8+0);
}
else if( m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+1);move(2);move(1);move(1);move(8+0);move(1);move(1);move(8+2);move(1);move(1);move(0);move(8+1);
}

// Caso 40
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+2);move(3);move(3);move(0);move(3);move(8+0);move(8+3);move(0);move(3);move(8+0);move(3);move(2);
}
else if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+3);move(0);move(0);move(1);move(0);move(8+1);move(8+0);move(1);move(0);move(8+1);move(0);move(3);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+0);move(1);move(1);move(2);move(1);move(8+2);move(8+1);move(2);move(1);move(8+2);move(1);move(0);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+1);move(2);move(2);move(3);move(2);move(8+3);move(8+2);move(3);move(2);move(8+3);move(2);move(1);
}

// Caso 41
else if( m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] ){
	move(2);move(1);move(8+0);move(1);move(0);move(8+1);move(8+0);move(1);move(0);move(1);move(1);move(8+2);
}
else if( m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] ){
	move(3);move(2);move(8+1);move(2);move(1);move(8+2);move(8+1);move(2);move(1);move(2);move(2);move(8+3);
}
else if( m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] ){
	move(0);move(3);move(8+2);move(3);move(2);move(8+3);move(8+2);move(3);move(2);move(3);move(3);move(8+0);
}
else if( m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] ){
	move(1);move(0);move(8+3);move(0);move(3);move(8+0);move(8+3);move(0);move(3);move(0);move(0);move(8+1);
}

// Caso 42
else if( m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[3][8] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] ){
	move(0);move(4);move(8+0);move(4);move(0);move(8+4);move(8+0);move(8+4);move(8+0);move(1);move(0);move(8+1);
}
else if( m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[0][8] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] ){
	move(1);move(4);move(8+1);move(4);move(1);move(8+4);move(8+1);move(8+4);move(8+1);move(2);move(1);move(8+2);
}
else if( m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[1][8] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] ){
	move(2);move(4);move(8+2);move(4);move(2);move(8+4);move(8+2);move(8+4);move(8+2);move(3);move(2);move(8+3);
}
else if( m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[2][8] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] ){
	move(3);move(4);move(8+3);move(4);move(3);move(8+4);move(8+3);move(8+4);move(8+3);move(0);move(3);move(8+0);
}

// Caso 43
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[3][6] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+2);move(8+4);move(2);move(8+4);move(8+2);move(4);move(2);move(4);move(2);move(8+1);move(8+2);move(1);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[0][6] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+3);move(8+4);move(3);move(8+4);move(8+3);move(4);move(3);move(4);move(3);move(8+2);move(8+3);move(2);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[1][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+0);move(8+4);move(0);move(8+4);move(8+0);move(4);move(0);move(4);move(0);move(8+3);move(8+0);move(3);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[2][6] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+1);move(8+4);move(1);move(8+4);move(8+1);move(4);move(1);move(4);move(1);move(8+0);move(8+1);move(0);
}

// Caso 44
else if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][2] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(0);move(4);move(8+0);move(8+4);move(8+0);move(1);move(0);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][0] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] ){
	move(1);move(4);move(8+1);move(8+4);move(8+1);move(2);move(1);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][6] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] ){
	move(2);move(4);move(8+2);move(8+4);move(8+2);move(3);move(2);move(2);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][8] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] ){
	move(3);move(4);move(8+3);move(8+4);move(8+3);move(0);move(3);move(3);move(4);move(8+3);move(8+4);move(8+0);
}

// Caso 45
else if( m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+0);move(8+4);move(0);move(4);move(0);move(8+3);move(0);move(0);move(8+4);move(0);move(4);move(3);
}
else if( m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+1);move(8+4);move(1);move(4);move(1);move(8+0);move(1);move(1);move(8+4);move(1);move(4);move(0);
}
else if( m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+2);move(8+4);move(2);move(4);move(2);move(8+1);move(2);move(2);move(8+4);move(2);move(4);move(1);
}
else if( m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+3);move(8+4);move(3);move(4);move(3);move(8+2);move(3);move(3);move(8+4);move(3);move(4);move(2);
}

// Caso 46
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][2] == m[4][4] && m[3][6] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(2);move(4);move(4);move(2);move(2);move(3);move(2);move(8+3);move(2);move(4);move(4);move(8+2);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][0] == m[4][4] && m[0][6] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] ){
	move(3);move(4);move(4);move(3);move(3);move(0);move(3);move(8+0);move(3);move(4);move(4);move(8+3);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][6] == m[4][4] && m[1][6] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] ){
	move(0);move(4);move(4);move(0);move(0);move(1);move(0);move(8+1);move(0);move(4);move(4);move(8+0);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][8] == m[4][4] && m[2][6] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] ){
	move(1);move(4);move(4);move(1);move(1);move(2);move(1);move(8+2);move(1);move(4);move(4);move(8+1);
}

// Caso 47
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][2] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] ){
	move(1);move(8+0);move(8+1);move(0);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][0] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] ){
	move(2);move(8+1);move(8+2);move(1);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][6] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] ){
	move(3);move(8+2);move(8+3);move(2);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][8] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] ){
	move(0);move(8+3);move(8+0);move(3);move(4);move(3);move(8+4);move(8+3);
}

// Caso 48
else if( m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+0);move(1);move(0);move(4);move(8+0);move(8+1);move(0);move(1);move(8+4);move(8+1);
}
else if( m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+1);move(2);move(1);move(4);move(8+1);move(8+2);move(1);move(2);move(8+4);move(8+2);
}
else if( m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+2);move(3);move(2);move(4);move(8+2);move(8+3);move(2);move(3);move(8+4);move(8+3);
}
else if( m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+3);move(0);move(3);move(4);move(8+3);move(8+0);move(3);move(0);move(8+4);move(8+0);
}

// Caso 49
else if( m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][0] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] ){
	move(2);move(8+1);move(8+2);move(8+4);move(2);move(1);move(8+2);move(8+1);move(4);move(1);
}
else if( m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][6] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] ){
	move(3);move(8+2);move(8+3);move(8+4);move(3);move(2);move(8+3);move(8+2);move(4);move(2);
}
else if( m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] ){
	move(0);move(8+3);move(8+0);move(8+4);move(0);move(3);move(8+0);move(8+3);move(4);move(3);
}
else if( m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][2] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] ){
	move(1);move(8+0);move(8+1);move(8+4);move(1);move(0);move(8+1);move(8+0);move(4);move(0);
}

// Caso 50
else if( m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] ){
	move(2);move(1);move(0);move(8+2);move(4);move(8+0);move(8+4);move(2);move(8+1);move(8+2);
}
else if( m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] ){
	move(3);move(2);move(1);move(8+3);move(4);move(8+1);move(8+4);move(3);move(8+2);move(8+3);
}
else if( m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[1][7] == m[4][4] && m[0][6] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][6] == m[4][4] ){
	move(0);move(3);move(2);move(8+0);move(4);move(8+2);move(8+4);move(0);move(8+3);move(8+0);
}
else if( m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[2][7] == m[4][4] && m[1][6] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][6] == m[4][4] ){
	move(1);move(0);move(3);move(8+1);move(4);move(8+3);move(8+4);move(1);move(8+0);move(8+1);
}

// Caso 51
else if( m[4][6] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[3][7] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[0][8] == m[4][4] ){
	move(8+0);move(8+1);move(0);move(8+2);move(8+4);move(2);move(4);move(8+0);move(1);move(0);
}
else if( m[4][8] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[0][7] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[1][8] == m[4][4] ){
	move(8+1);move(8+2);move(1);move(8+3);move(8+4);move(3);move(4);move(8+1);move(2);move(1);
}
else if( m[4][2] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[1][7] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[2][8] == m[4][4] ){
	move(8+2);move(8+3);move(2);move(8+0);move(8+4);move(0);move(4);move(8+2);move(3);move(2);
}
else if( m[4][0] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[2][7] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[3][8] == m[4][4] ){
	move(8+3);move(8+0);move(3);move(8+1);move(8+4);move(1);move(4);move(8+3);move(0);move(3);
}

// Caso 52
else if( m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][2] == m[4][4] && m[3][8] == m[4][4] && m[1][6] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(0);move(4);move(8+0);move(8+4);move(0);move(8+4);move(8+0);move(8+1);move(8+4);move(1);move(0);move(4);move(8+0);
}
else if( m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][0] == m[4][4] && m[0][8] == m[4][4] && m[2][6] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] ){
	move(1);move(4);move(8+1);move(8+4);move(1);move(8+4);move(8+1);move(8+2);move(8+4);move(2);move(1);move(4);move(8+1);
}
else if( m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][6] == m[4][4] && m[1][8] == m[4][4] && m[3][6] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] ){
	move(2);move(4);move(8+2);move(8+4);move(2);move(8+4);move(8+2);move(8+3);move(8+4);move(3);move(2);move(4);move(8+2);
}
else if( m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][8] == m[4][4] && m[2][8] == m[4][4] && m[0][6] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] ){
	move(3);move(4);move(8+3);move(8+4);move(3);move(8+4);move(8+3);move(8+0);move(8+4);move(0);move(3);move(4);move(8+3);
}

// Caso 53
else if( m[4][6] == m[4][4] && m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][1] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] && m[2][8] == m[4][4] && m[0][6] == m[4][4] ){
	move(3);move(4);move(2);move(4);move(4);move(8+2);move(8+4);move(2);move(4);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][8] == m[4][4] && m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][3] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] && m[3][8] == m[4][4] && m[1][6] == m[4][4] ){
	move(0);move(4);move(3);move(4);move(4);move(8+3);move(8+4);move(3);move(4);move(4);move(8+3);move(8+4);move(8+0);
}
else if( m[4][2] == m[4][4] && m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][7] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] && m[0][8] == m[4][4] && m[2][6] == m[4][4] ){
	move(1);move(4);move(0);move(4);move(4);move(8+0);move(8+4);move(0);move(4);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][0] == m[4][4] && m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][5] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] && m[1][8] == m[4][4] && m[3][6] == m[4][4] ){
	move(2);move(4);move(1);move(4);move(4);move(8+1);move(8+4);move(1);move(4);move(4);move(8+1);move(8+4);move(8+2);
}

// Caso 54
else if( m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[4][2] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(0);move(4);move(8+0);move(4);move(0);move(4);move(4);move(8+0);move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[4][0] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] ){
	move(1);move(4);move(8+1);move(4);move(1);move(4);move(4);move(8+1);move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[4][6] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] ){
	move(2);move(4);move(8+2);move(4);move(2);move(4);move(4);move(8+2);move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[4][8] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] ){
	move(3);move(4);move(8+3);move(4);move(3);move(4);move(4);move(8+3);move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);
}

// Caso 55
else if( m[4][6] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][1] == m[4][4] && m[3][7] == m[4][4] && m[1][6] == m[4][4] && m[1][8] == m[4][4] && m[0][7] == m[4][4] ){
	move(8+0);move(8+4);move(0);move(8+4);move(8+0);move(4);move(4);move(0);move(1);move(0);move(4);move(8+0);move(8+4);move(8+1);
}
else if( m[4][8] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][3] == m[4][4] && m[0][7] == m[4][4] && m[2][6] == m[4][4] && m[2][8] == m[4][4] && m[1][7] == m[4][4] ){
	move(8+1);move(8+4);move(1);move(8+4);move(8+1);move(4);move(4);move(1);move(2);move(1);move(4);move(8+1);move(8+4);move(8+2);
}
else if( m[4][2] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][7] == m[4][4] && m[1][7] == m[4][4] && m[3][6] == m[4][4] && m[3][8] == m[4][4] && m[2][7] == m[4][4] ){
	move(8+2);move(8+4);move(2);move(8+4);move(8+2);move(4);move(4);move(2);move(3);move(2);move(4);move(8+2);move(8+4);move(8+3);
}
else if( m[4][0] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][5] == m[4][4] && m[2][7] == m[4][4] && m[0][6] == m[4][4] && m[0][8] == m[4][4] && m[3][7] == m[4][4] ){
	move(8+3);move(8+4);move(3);move(8+4);move(8+3);move(4);move(4);move(3);move(0);move(3);move(4);move(8+3);move(8+4);move(8+0);
}

// Caso 56
else if( m[4][6] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][5] == m[4][4] && m[4][0] == m[4][4] && m[4][2] == m[4][4] && m[3][7] == m[4][4] && m[1][7] == m[4][4] ){
	move(0);move(4);move(8+0);move(8+4);move(8+0);move(2);move(1);move(0);move(8+1);move(8+2);
}
else if( m[4][8] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][1] == m[4][4] && m[4][6] == m[4][4] && m[4][0] == m[4][4] && m[0][7] == m[4][4] && m[2][7] == m[4][4] ){
	move(1);move(4);move(8+1);move(8+4);move(8+1);move(3);move(2);move(1);move(8+2);move(8+3);
}
else if( m[4][2] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][3] == m[4][4] && m[4][8] == m[4][4] && m[4][6] == m[4][4] && m[1][7] == m[4][4] && m[3][7] == m[4][4] ){
	move(2);move(4);move(8+2);move(8+4);move(8+2);move(0);move(3);move(2);move(8+3);move(8+0);
}
else if( m[4][0] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][7] == m[4][4] && m[4][2] == m[4][4] && m[4][8] == m[4][4] && m[2][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(3);move(4);move(8+3);move(8+4);move(8+3);move(1);move(0);move(3);move(8+0);move(8+1);
}

// Caso 57
else if( m[4][6] == m[4][4] && m[4][7] == m[4][4] && m[4][8] == m[4][4] && m[4][3] == m[4][4] && m[4][0] == m[4][4] && m[4][2] == m[4][4] && m[1][7] == m[4][4] && m[0][7] == m[4][4] ){
	move(2);move(1);move(8+0);move(8+1);move(0);move(8+2);move(4);move(0);move(8+4);move(8+0);
}
else if( m[4][8] == m[4][4] && m[4][5] == m[4][4] && m[4][2] == m[4][4] && m[4][7] == m[4][4] && m[4][6] == m[4][4] && m[4][0] == m[4][4] && m[2][7] == m[4][4] && m[1][7] == m[4][4] ){
	move(3);move(2);move(8+1);move(8+2);move(1);move(8+3);move(4);move(1);move(8+4);move(8+1);
}
else if( m[4][2] == m[4][4] && m[4][1] == m[4][4] && m[4][0] == m[4][4] && m[4][5] == m[4][4] && m[4][8] == m[4][4] && m[4][6] == m[4][4] && m[3][7] == m[4][4] && m[2][7] == m[4][4] ){
	move(0);move(3);move(8+2);move(8+3);move(2);move(8+0);move(4);move(2);move(8+4);move(8+2);
}
else if( m[4][0] == m[4][4] && m[4][3] == m[4][4] && m[4][6] == m[4][4] && m[4][1] == m[4][4] && m[4][2] == m[4][4] && m[4][8] == m[4][4] && m[0][7] == m[4][4] && m[3][7] == m[4][4] ){
	move(1);move(0);move(8+3);move(8+0);move(3);move(8+1);move(4);move(3);move(8+4);move(8+3);
}

}

void PLL(){
int loop;	// variavel para fazer 4 repeticoes

PLL_ini:

// Caso U Horário
if( m[3][6] == m[3][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] ){
	move(8+0);move(4);move(8+0);move(8+4);move(8+0);move(8+4);move(8+0);move(4);move(0);move(4);move(0);move(0);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] ){
	move(8+1);move(4);move(8+1);move(8+4);move(8+1);move(8+4);move(8+1);move(4);move(1);move(4);move(1);move(1);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] ){
	move(8+2);move(4);move(8+2);move(8+4);move(8+2);move(8+4);move(8+2);move(4);move(2);move(4);move(2);move(2);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] ){
	move(8+3);move(4);move(8+3);move(8+4);move(8+3);move(8+4);move(8+3);move(4);move(3);move(4);move(3);move(3);
}

// Caso U Anti-Horário
else if( m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] ){
	move(0);move(0);move(8+4);move(8+0);move(8+4);move(0);move(4);move(0);move(4);move(0);move(8+4);move(0);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] ){
	move(1);move(1);move(8+4);move(8+1);move(8+4);move(1);move(4);move(1);move(4);move(1);move(8+4);move(1);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] ){
	move(2);move(2);move(8+4);move(8+2);move(8+4);move(2);move(4);move(2);move(4);move(2);move(8+4);move(2);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] ){
	move(3);move(3);move(8+4);move(8+3);move(8+4);move(3);move(4);move(3);move(4);move(3);move(8+4);move(3);
}

// Caso Z
else if( m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] ){
	move(0);move(0);move(2);move(2);move(5);move(0);move(0);move(2);move(2);move(4);move(2);move(8+0);move(3);move(3);move(0);move(0);move(2);move(2);move(1);move(1);move(2);move(8+0);move(4);move(4);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] ){
	move(1);move(1);move(3);move(3);move(5);move(1);move(1);move(3);move(3);move(4);move(3);move(8+1);move(0);move(0);move(1);move(1);move(3);move(3);move(2);move(2);move(3);move(8+1);move(4);move(4);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] ){
	move(2);move(2);move(0);move(0);move(5);move(2);move(2);move(0);move(0);move(4);move(0);move(8+2);move(1);move(1);move(2);move(2);move(0);move(0);move(3);move(3);move(0);move(8+2);move(4);move(4);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] ){
	move(3);move(3);move(1);move(1);move(5);move(3);move(3);move(1);move(1);move(4);move(1);move(8+3);move(2);move(2);move(3);move(3);move(1);move(1);move(0);move(0);move(1);move(8+3);move(4);move(4);
}

// Caso H
else if( m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] ){
	move(0);move(0);move(2);move(2);move(5);move(0);move(0);move(2);move(2);move(4);move(4);move(0);move(0);move(2);move(2);move(5);move(0);move(0);move(2);move(2);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] ){
	move(1);move(1);move(3);move(3);move(5);move(1);move(1);move(3);move(3);move(4);move(4);move(1);move(1);move(3);move(3);move(5);move(1);move(1);move(3);move(3);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] ){
	move(2);move(2);move(0);move(0);move(5);move(2);move(2);move(0);move(0);move(4);move(4);move(2);move(2);move(0);move(0);move(5);move(2);move(2);move(0);move(0);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] ){
	move(3);move(3);move(1);move(1);move(5);move(3);move(3);move(1);move(1);move(4);move(4);move(3);move(3);move(1);move(1);move(5);move(3);move(3);move(1);move(1);
}

// Caso A Horário
else if( m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[2][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] ){
	move(8+2);move(3);move(8+2);move(1);move(1);move(2);move(8+3);move(8+2);move(1);move(1);move(2);move(2);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[3][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] ){
	move(8+3);move(0);move(8+3);move(2);move(2);move(3);move(8+0);move(8+3);move(2);move(2);move(3);move(3);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[0][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] ){
	move(8+0);move(1);move(8+0);move(3);move(3);move(0);move(8+1);move(8+0);move(3);move(3);move(0);move(0);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[1][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] ){
	move(8+1);move(2);move(8+1);move(0);move(0);move(1);move(8+2);move(8+1);move(0);move(0);move(1);move(1);
}

// Caso A Anti-Horário
else if( m[3][6] == m[1][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[2][4] ){
	move(0);move(8+3);move(0);move(1);move(1);move(8+0);move(3);move(0);move(1);move(1);move(0);move(0);
}
else if( m[0][6] == m[2][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[3][4] ){
	move(1);move(8+0);move(1);move(2);move(2);move(8+1);move(0);move(1);move(2);move(2);move(1);move(1);
}
else if( m[1][6] == m[3][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[0][4] ){
	move(2);move(8+1);move(2);move(3);move(3);move(8+2);move(1);move(2);move(3);move(3);move(2);move(2);
}
else if( m[2][6] == m[0][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[1][4] ){
	move(3);move(8+2);move(3);move(0);move(0);move(8+3);move(2);move(3);move(0);move(0);move(3);move(3);
}

// Caso E
else if( m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[1][4] ){
	move(0);move(8+3);move(8+0);move(1);move(0);move(3);move(8+0);move(8+1);move(0);move(3);move(8+0);move(1);move(0);move(8+3);move(8+0);move(8+1);
}
else if( m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[2][4] ){
	move(1);move(8+0);move(8+1);move(2);move(1);move(0);move(8+1);move(8+2);move(1);move(0);move(8+1);move(2);move(1);move(8+0);move(8+1);move(8+2);
}
else if( m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[3][4] ){
	move(2);move(8+1);move(8+2);move(3);move(2);move(1);move(8+2);move(8+3);move(2);move(1);move(8+2);move(3);move(2);move(8+1);move(8+2);move(8+3);
}
else if( m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[0][4] ){
	move(3);move(8+2);move(8+3);move(0);move(3);move(2);move(8+3);move(8+0);move(3);move(2);move(8+3);move(0);move(3);move(8+2);move(8+3);move(8+0);
}

// Caso R 8
else if( m[3][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] ){
	move(2);move(4);move(4);move(8+2);move(4);move(4);move(2);move(8+1);move(8+2);move(8+4);move(2);move(4);move(2);move(1);move(2);move(2);move(4);
}
else if( m[0][6] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] ){
	move(3);move(4);move(4);move(8+3);move(4);move(4);move(3);move(8+2);move(8+3);move(8+4);move(3);move(4);move(3);move(2);move(3);move(3);move(4);
}
else if( m[1][6] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] ){
	move(0);move(4);move(4);move(8+0);move(4);move(4);move(0);move(8+3);move(8+0);move(8+4);move(0);move(4);move(0);move(3);move(0);move(0);move(4);
}
else if( m[2][6] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] ){
	move(1);move(4);move(4);move(8+1);move(4);move(4);move(1);move(8+0);move(8+1);move(8+4);move(1);move(4);move(1);move(0);move(1);move(1);move(4);
}

// Caso R 9
else if( m[3][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[1][4] && m[0][8] == m[3][4] ){
	move(8+0);move(4);move(4);move(0);move(4);move(4);move(8+0);move(1);move(0);move(4);move(8+0);move(8+4);move(8+0);move(8+1);move(0);move(0);move(8+4);
}
else if( m[0][6] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[2][4] && m[1][8] == m[0][4] ){
	move(8+1);move(4);move(4);move(1);move(4);move(4);move(8+1);move(2);move(1);move(4);move(8+1);move(8+4);move(8+1);move(8+2);move(1);move(1);move(8+4);
}
else if( m[1][6] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[3][4] && m[2][8] == m[1][4] ){
	move(8+2);move(4);move(4);move(2);move(4);move(4);move(8+2);move(3);move(2);move(4);move(8+2);move(8+4);move(8+2);move(8+3);move(2);move(2);move(8+4);
}
else if( m[2][6] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[0][4] && m[3][8] == m[2][4] ){
	move(8+3);move(4);move(4);move(3);move(4);move(4);move(8+3);move(0);move(3);move(4);move(8+3);move(8+4);move(8+3);move(8+0);move(3);move(3);move(8+4);
}

// Caso J 10
else if( m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[3][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] ){
	move(1);move(1);move(0);move(4);move(8+0);move(1);move(1);move(2);move(8+5);move(2);move(5);move(2);move(2);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[0][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] ){
	move(2);move(2);move(1);move(4);move(8+1);move(2);move(2);move(3);move(8+5);move(3);move(5);move(3);move(3);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[1][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] ){
	move(3);move(3);move(2);move(4);move(8+2);move(3);move(3);move(0);move(8+5);move(0);move(5);move(0);move(0);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[2][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] ){
	move(0);move(0);move(3);move(4);move(8+3);move(0);move(0);move(1);move(8+5);move(1);move(5);move(1);move(1);
}

// Caso J 11
else if( m[3][6] == m[0][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[3][4] && m[0][8] == m[1][4] ){
	move(1);move(1);move(8+2);move(8+4);move(2);move(1);move(1);move(8+0);move(5);move(8+0);move(8+5);move(0);move(0);
}
else if( m[0][6] == m[1][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[0][4] && m[1][8] == m[2][4] ){
	move(2);move(2);move(8+3);move(8+4);move(3);move(2);move(2);move(8+1);move(5);move(8+1);move(8+5);move(1);move(1);
}
else if( m[1][6] == m[2][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[1][4] && m[2][8] == m[3][4] ){
	move(3);move(3);move(8+0);move(8+4);move(0);move(3);move(3);move(8+2);move(5);move(8+2);move(8+5);move(2);move(2);
}
else if( m[2][6] == m[3][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[2][4] && m[3][8] == m[0][4] ){
	move(0);move(0);move(8+1);move(8+4);move(1);move(0);move(0);move(8+3);move(5);move(8+3);move(8+5);move(3);move(3);
}

// Caso N 1-2
else if( m[3][6] == m[1][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[2][4] ){
	move(4);move(2);move(8+4);move(0);move(4);move(4);move(8+2);move(4);move(8+0);move(2);move(8+4);move(0);move(4);move(4);move(8+2);move(4);move(8+0);
}
else if( m[0][6] == m[2][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[3][4] ){
	move(4);move(3);move(8+4);move(1);move(4);move(4);move(8+3);move(4);move(8+1);move(3);move(8+4);move(1);move(4);move(4);move(8+3);move(4);move(8+1);
}
else if( m[1][6] == m[3][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[0][4] ){
	move(4);move(0);move(8+4);move(2);move(4);move(4);move(8+0);move(4);move(8+2);move(0);move(8+4);move(2);move(4);move(4);move(8+0);move(4);move(8+2);
}
else if( m[2][6] == m[0][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[1][4] ){
	move(4);move(1);move(8+4);move(3);move(4);move(4);move(8+1);move(4);move(8+3);move(1);move(8+4);move(3);move(4);move(4);move(8+1);move(4);move(8+3);
}

// Caso N 2-1
else if( m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] ){
	move(8+4);move(8+0);move(4);move(8+2);move(4);move(4);move(0);move(8+4);move(2);move(8+0);move(4);move(8+2);move(4);move(4);move(0);move(8+4);move(2);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] ){
	move(8+4);move(8+1);move(4);move(8+3);move(4);move(4);move(1);move(8+4);move(3);move(8+1);move(4);move(8+3);move(4);move(4);move(1);move(8+4);move(3);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] ){
	move(8+4);move(8+2);move(4);move(8+0);move(4);move(4);move(2);move(8+4);move(0);move(8+2);move(4);move(8+0);move(4);move(4);move(2);move(8+4);move(0);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] ){
	move(8+4);move(8+3);move(4);move(8+1);move(4);move(4);move(3);move(8+4);move(1);move(8+3);move(4);move(8+1);move(4);move(4);move(3);move(8+4);move(1);
}

// Caso G 18
else if( m[3][6] == m[1][4] && m[3][7] == m[2][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[0][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[2][4] ){
	move(0);move(0);move(5);move(8+3);move(4);move(8+3);move(8+4);move(3);move(8+5);move(0);move(0);move(8+1);move(4);move(1);
}
else if( m[0][6] == m[2][4] && m[0][7] == m[3][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[1][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[3][4] ){
	move(1);move(1);move(5);move(8+0);move(4);move(8+0);move(8+4);move(0);move(8+5);move(1);move(1);move(8+2);move(4);move(2);
}
else if( m[1][6] == m[3][4] && m[1][7] == m[0][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[2][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[0][4] ){
	move(2);move(2);move(5);move(8+1);move(4);move(8+1);move(8+4);move(1);move(8+5);move(2);move(2);move(8+3);move(4);move(3);
}
else if( m[2][6] == m[0][4] && m[2][7] == m[1][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[3][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[1][4] ){
	move(3);move(3);move(5);move(8+2);move(4);move(8+2);move(8+4);move(2);move(8+5);move(3);move(3);move(8+0);move(4);move(0);
}

// Caso G 19
else if( m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[0][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[2][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] ){
	move(0);move(0);move(8+5);move(1);move(8+4);move(1);move(4);move(8+1);move(5);move(0);move(0);move(3);move(8+4);move(8+3);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[1][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[3][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] ){
	move(1);move(1);move(8+5);move(2);move(8+4);move(2);move(4);move(8+2);move(5);move(1);move(1);move(0);move(8+4);move(8+0);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[2][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[0][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] ){
	move(2);move(2);move(8+5);move(3);move(8+4);move(3);move(4);move(8+3);move(5);move(2);move(2);move(1);move(8+4);move(8+1);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[3][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[1][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] ){
	move(3);move(3);move(8+5);move(0);move(8+4);move(0);move(4);move(8+0);move(5);move(3);move(3);move(2);move(8+4);move(8+2);
}

// Caso G 20
else if( m[3][6] == m[1][4] && m[3][7] == m[2][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[1][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[2][4] ){
	move(0);move(4);move(8+0);move(1);move(1);move(8+5);move(2);move(8+4);move(8+2);move(4);move(8+2);move(5);move(1);move(1);
}
else if( m[0][6] == m[2][4] && m[0][7] == m[3][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[2][4] && m[3][8] == m[0][4] && m[2][6] == m[3][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[3][4] ){
	move(1);move(4);move(8+1);move(2);move(2);move(8+5);move(3);move(8+4);move(8+3);move(4);move(8+3);move(5);move(2);move(2);
}
else if( m[1][6] == m[3][4] && m[1][7] == m[0][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[3][4] && m[0][8] == m[1][4] && m[3][6] == m[0][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[0][4] ){
	move(2);move(4);move(8+2);move(3);move(3);move(8+5);move(0);move(8+4);move(8+0);move(4);move(8+0);move(5);move(3);move(3);
}
else if( m[2][6] == m[0][4] && m[2][7] == m[1][4] && m[2][8] == m[3][4] && m[1][6] == m[2][4] && m[1][7] == m[0][4] && m[1][8] == m[2][4] && m[0][6] == m[1][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[1][4] ){
	move(3);move(4);move(8+3);move(0);move(0);move(8+5);move(1);move(8+4);move(8+1);move(4);move(8+1);move(5);move(0);move(0);
}

// Caso G 21
else if( m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[3][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[2][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] ){
	move(8+0);move(8+4);move(0);move(3);move(3);move(5);move(8+2);move(4);move(2);move(8+4);move(2);move(8+5);move(3);move(3);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[0][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[3][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] ){
	move(8+1);move(8+4);move(1);move(0);move(0);move(5);move(8+3);move(4);move(3);move(8+4);move(3);move(8+5);move(0);move(0);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[1][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[0][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] ){
	move(8+2);move(8+4);move(2);move(1);move(1);move(5);move(8+0);move(4);move(0);move(8+4);move(0);move(8+5);move(1);move(1);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[2][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[1][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] ){
	move(8+3);move(8+4);move(3);move(2);move(2);move(5);move(8+1);move(4);move(1);move(8+4);move(1);move(8+5);move(2);move(2);
}

//  Caso F
else if( m[3][6] == m[0][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[0][4] && m[0][8] == m[1][4] ){
	move(8+0);move(8+4);move(8+1);move(0);move(4);move(8+0);move(8+4);move(8+0);move(1);move(0);move(0);move(8+4);move(8+0);move(8+4);move(0);move(4);move(8+0);move(4);move(0);
}
else if( m[0][6] == m[1][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[1][4] && m[1][8] == m[2][4] ){
	move(8+1);move(8+4);move(8+2);move(1);move(4);move(8+1);move(8+4);move(8+1);move(2);move(1);move(1);move(8+4);move(8+1);move(8+4);move(1);move(4);move(8+1);move(4);move(1);
}
else if( m[1][6] == m[2][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[2][4] && m[2][8] == m[3][4] ){
	move(8+2);move(8+4);move(8+3);move(2);move(4);move(8+2);move(8+4);move(8+2);move(3);move(2);move(2);move(8+4);move(8+2);move(8+4);move(2);move(4);move(8+2);move(4);move(2);
}
else if( m[2][6] == m[3][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[3][4] && m[3][8] == m[0][4] ){
	move(8+3);move(8+4);move(8+0);move(3);move(4);move(8+3);move(8+4);move(8+3);move(0);move(3);move(3);move(8+4);move(8+3);move(8+4);move(3);move(4);move(8+3);move(4);move(3);
}

// Caso T
else if( m[3][6] == m[0][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[0][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[0][4] && m[0][6] == m[3][4] && m[0][7] == m[2][4] && m[0][8] == m[1][4] ){
	move(0);move(4);move(8+0);move(8+4);move(8+0);move(1);move(0);move(0);move(8+4);move(8+0);move(8+4);move(0);move(4);move(8+0);move(8+1);
}
else if( m[0][6] == m[1][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[1][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[1][4] && m[1][6] == m[0][4] && m[1][7] == m[3][4] && m[1][8] == m[2][4] ){
	move(1);move(4);move(8+1);move(8+4);move(8+1);move(2);move(1);move(1);move(8+4);move(8+1);move(8+4);move(1);move(4);move(8+1);move(8+2);
}
else if( m[1][6] == m[2][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[2][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[2][4] && m[2][6] == m[1][4] && m[2][7] == m[0][4] && m[2][8] == m[3][4] ){
	move(2);move(4);move(8+2);move(8+4);move(8+2);move(3);move(2);move(2);move(8+4);move(8+2);move(8+4);move(2);move(4);move(8+2);move(8+3);
}
else if( m[2][6] == m[3][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[3][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[3][4] && m[3][6] == m[2][4] && m[3][7] == m[1][4] && m[3][8] == m[0][4] ){
	move(3);move(4);move(8+3);move(8+4);move(8+3);move(0);move(3);move(3);move(8+4);move(8+3);move(8+4);move(3);move(4);move(8+3);move(8+0);
}

// Caso V
else if( m[3][6] == m[1][4] && m[3][7] == m[2][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[3][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[2][4] ){
	move(8+0);move(4);move(8+0);move(8+4);move(8+3);move(8+0);move(3);move(3);move(8+4);move(8+3);move(4);move(8+3);move(0);move(3);move(0);
}
else if( m[0][6] == m[2][4] && m[0][7] == m[3][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[0][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[3][4] ){
	move(8+1);move(4);move(8+1);move(8+4);move(8+0);move(8+1);move(0);move(0);move(8+4);move(8+0);move(4);move(8+0);move(1);move(0);move(1);
}
else if( m[1][6] == m[3][4] && m[1][7] == m[0][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[1][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[0][4] ){
	move(8+2);move(4);move(8+2);move(8+4);move(8+1);move(8+2);move(1);move(1);move(8+4);move(8+1);move(4);move(8+1);move(2);move(1);move(2);
}
else if( m[2][6] == m[0][4] && m[2][7] == m[1][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[2][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[1][4] ){
	move(8+3);move(4);move(8+3);move(8+4);move(8+2);move(8+3);move(2);move(2);move(8+4);move(8+2);move(4);move(8+2);move(3);move(2);move(3);
}

// Caso Y
else if( m[3][6] == m[3][4] && m[3][7] == m[2][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[3][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] ){
	move(1);move(0);move(8+4);move(8+0);move(8+4);move(0);move(4);move(8+0);move(8+1);move(0);move(4);move(8+0);move(8+4);move(8+0);move(1);move(0);move(8+1);
}
else if( m[0][6] == m[0][4] && m[0][7] == m[3][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[0][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] ){
	move(2);move(1);move(8+4);move(8+1);move(8+4);move(1);move(4);move(8+1);move(8+2);move(1);move(4);move(8+1);move(8+4);move(8+1);move(2);move(1);move(8+2);
}
else if( m[1][6] == m[1][4] && m[1][7] == m[0][4] && m[1][8] == m[3][4] && m[0][6] == m[2][4] && m[0][7] == m[1][4] && m[0][8] == m[0][4] && m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[1][4] && m[2][6] == m[0][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] ){
	move(3);move(2);move(8+4);move(8+2);move(8+4);move(2);move(4);move(8+2);move(8+3);move(2);move(4);move(8+2);move(8+4);move(8+2);move(3);move(2);move(8+3);
}
else if( m[2][6] == m[2][4] && m[2][7] == m[1][4] && m[2][8] == m[0][4] && m[1][6] == m[3][4] && m[1][7] == m[2][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[2][4] && m[3][6] == m[1][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] ){
	move(0);move(3);move(8+4);move(8+3);move(8+4);move(3);move(4);move(8+3);move(8+0);move(3);move(4);move(8+3);move(8+4);move(8+3);move(0);move(3);move(8+0);
}


// Cubo Resolvido
else if( m[3][6] == m[3][4] && m[3][7] == m[3][4] && m[3][8] == m[3][4] && m[2][6] == m[2][4] && m[2][7] == m[2][4] && m[2][8] == m[2][4] && m[1][6] == m[1][4] && m[1][7] == m[1][4] && m[1][8] == m[1][4] && m[0][6] == m[0][4] && m[0][7] == m[0][4] && m[0][8] == m[0][4] ){
	loop = 4;
}

else {
	loop++;
	if( loop < 4 ){ move(4); goto PLL_ini; }
}
}

void main(){
	Cruz();
	F2L();
	OLL();
	PLL();
}