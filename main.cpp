#include <iostream>
using namespace std;

char matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'O';  //players are 'X' and 'O'.  Initialized player goes 2nd.
int move_count = 0;

void Draw();
void Input();
void TogglePlayer();
char Victory();
int SetSquare();

int main() {
	char win_con = 'N';

	while (win_con == 'N') {
		TogglePlayer();
		Draw();
		Input();
		win_con = Victory();
	}
	Draw();
	if (win_con == 'd') {
		cout << endl << "The game is a draw!" << endl;
	}
	else{
	cout << endl << player << " has won the match!" << endl;
	}

	system("pause");
	return 0;
}

void Draw() {
	system("cls");
	cout << "Tic Tac Toe" << endl << endl;
	//cout << "There have been " << move_count << " moves so far." << endl;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
}

int SetSquare(int row, int col) {
	// given a choice of 1-9, this marks the selected square.
	if (matrix[row][col] == 'X' || matrix[row][col] == 'O') {
		Draw();
		cout << endl << "INVALID SELECTION!  That space is already taken!" << endl;
		return 0;
	}
	matrix[row][col] = player;
	return 1;
}
void Input() {
	int a = 0;
	while(a<1 || a>9){
	cout <<endl<< "It is " << player << "'s turn." << endl;
	cout<<"Press the number of the field: ";
	cin >> a;
	switch(a){
	case 1:
		a = SetSquare(0, 0);
		break;
	case 2:
		a = SetSquare(0, 1);
		break;
	case 3:
		a = SetSquare(0, 2);
		break;
	case 4:
		a = SetSquare(1, 0);
		break;
	case 5:
		a = SetSquare(1, 1);
		break;
	case 6:
		a = SetSquare(1, 2);
		break;
	case 7:
		a = SetSquare(2, 0);
		break;
	case 8:
		a = SetSquare(2, 1);
		break;
	case 9:
		a = SetSquare(2, 2);
		break;
	default:
		Draw();
		cout << endl << "Invalid selection.  1-9 only." << endl;
		break;
	} //end of switch
	} //end of while loop
	move_count++;  //tracks moves, in case of a draw game.
}

void TogglePlayer() {  //changes current player
	if (player == 'X') {
		player = 'O';}
	else {
		player = 'X';}
}

char Victory() { //this function checks if someone has 3 in a row.
	for (int hor = 0;hor<3;hor++){ //check for 3 across victory
		if (matrix[hor][0] == player && matrix[hor][1] == player && matrix[hor][2] == player) {
			//cout << endl << "Horizontal victory";
			return('w');
		}
	}
	for (int vert = 0; vert<3; vert++) { //check for 3 down victory
		if (matrix[0][vert] == player && matrix[1][vert] == player && matrix[2][vert] == player) {
			//cout << endl << "vertical victory";
			return('w');
		}
	}
	if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) {
		//cout << endl << "diagonal victory1";
		return('w');
	}
	if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player) {
		//cout << endl << "diagonal victory2";
		return('w');
	}
if(move_count==9){
	return('d');  // there are no available spaces.  Game is a draw.
}
return('N');  //no one has 3 in a row
}
