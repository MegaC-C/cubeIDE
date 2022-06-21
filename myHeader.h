void displayNum (uint8_t num)
{
	uint8_t digit1_9   = num % 10;
	uint8_t digit10_90 = num / 10;
	// turn off then set digit1_9
	HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, RESET);
	HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, RESET);
	HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, RESET);
	HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
	HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, RESET);
	HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, RESET);
	HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, RESET);
	HAL_GPIO_WritePin(DP2_GPIO_Port, DP2_Pin, RESET);
	switch (digit1_9)
	{
		case 0:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, SET);
			HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
		break;
		case 3:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
		break;
		case 4:
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
		break;
		case 5:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, SET);
			HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
			break;
		case 7:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, SET);
			HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
			break;
		case 9:
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, SET);
			HAL_GPIO_WritePin(C2_GPIO_Port, C2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
			break;
		default:	//display "E"
			HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, SET);
			HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, SET);
			HAL_GPIO_WritePin(F2_GPIO_Port, F2_Pin, SET);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, SET);
	}
	// turn off then set digit10_90
	HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET);
	HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, RESET);
	HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, RESET);
	HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, RESET);
	HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, RESET);
	HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, RESET);
	HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, RESET);
	HAL_GPIO_WritePin(DP1_GPIO_Port, DP1_Pin, RESET);
	switch (digit10_90)
	{
		case 0:
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, SET);
			HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			break;        
		case 2:           
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
		break;               
		case 3:              
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
		break;               
		case 4:              
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
		break;              
		case 5:             
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
			break;             
		case 6:                
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, SET);
			HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
			break;            
		case 7:               
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			break;           
		case 8:              
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, SET);
			HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
			break;        
		case 9:           
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, SET);
			HAL_GPIO_WritePin(C1_GPIO_Port, C1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
			break;               
		default:	//display "E" 
			HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, SET);
			HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, SET);
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, SET);
			HAL_GPIO_WritePin(F1_GPIO_Port, F1_Pin, SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, SET);
	}
}

