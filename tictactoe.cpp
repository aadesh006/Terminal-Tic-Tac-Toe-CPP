#include<iostream>
#include<ctime>
#include<windows.h>

void Board(char *spaces);
void PlayerMove(char *spaces, char player);
void ComputerMove(char *spaces, char player);
bool CheckWinner(char *spaces, char player, char computer);
bool CheckTie(char *spaces);

int main(){

    system("cls");
    char tempspaces[9] = {'1','2','3','4','5','6','7','8','9'};
    char player = 'X';
    char computer = 'O';
    bool running;

    std::cout<<"Welcome to the game of Tic Tac Toe!\nLet's have some fun!"<<std::endl;

    Board(tempspaces);
    std::cout<<"Remeber the Number Corresponding to Spots"<<std::endl;
    system("pause");
    system("cls");

    std::cout<<"X will go first!"<<std::endl;
    std::cout<<"What would like you choose(X/O): ";
    char choice;
    std::cin>>choice;
    if(choice == 'X'|| choice == 'x'){
        player = 'X';
        computer = 'O';
    }
    else if(choice == 'O' || choice == 'o'){
        player = 'O';
        computer = 'X';
    }
    else{
        std::cout<<"Invalid Choice! It will be random"<<std::endl;
        int random = rand() % 2;
        if(random == 0){
            player = 'O';
            computer = 'X';
            std::cout<<"\nComputer will go first!\n"<<std::endl;
            system("pause");
        }
        else{
        player = 'X';
        computer = 'O';
        std::cout<<"\nPlayer will go first!\n"<<std::endl;
        system("pause");
        }
    }

    system("cls");

    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    std::cout<<"Lets's Start the Game!"<<std::endl;
     std::cout << "Tic Tac Toe" << std::endl;
    Board(spaces);

    if(player == 'O'){
        while (running = true) {

        Sleep(1000);
        ComputerMove(spaces, computer);
        Board(spaces);
        if(CheckWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if (CheckTie(spaces)) {
            std::cout << "It's a tie!" << std::endl;
            running = false;
            break;
        }

        PlayerMove(spaces, player);
        Board(spaces);
        if (CheckWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (CheckTie(spaces)) {
            std::cout << "It's a tie!" << std::endl;
            running = false;
            break;
        }
        
    }

    }

    else{
    while (running = true) {

        PlayerMove(spaces, player);
        Board(spaces);
        if (CheckWinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if (CheckTie(spaces)) {
            std::cout << "It's a tie!" << std::endl;
            running = false;
            break;
        }

        Sleep(1000);
        ComputerMove(spaces, computer);
        Board(spaces);
        if(CheckWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if (CheckTie(spaces)) {
            std::cout << "It's a tie!" << std::endl;
            running = false;
            break;
        }
        
    }
    }

    system("pause");
    system("cls");
    char playAgain;

    std::cout<<"Thanks for playing!"<<std::endl;
    std::cout<<"Woud you like to play again?(Y/N): "<<std::endl;

    std::cin>>playAgain;
    if(playAgain == 'Y' || playAgain == 'y'){
        main();
    }
    else if(playAgain == 'N' || playAgain == 'n'){
        system("cls");
        std::cout<<"Thanks for playing!"<<std::endl;
        std::cout<<"Hope you had fun!"<<std::endl;
        std::cout<<"Goodbye!"<<std::endl;
    }
    else{
        std::cout<<"We assume it's a NO!"<<std::endl;
        std::cout<<"Hope you had fun!\nGoodbye!"<<std::endl;
    }

    return 0;
}

void Board(char *spaces){

    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << std::endl;
    std::cout << "     |     |     " << std::endl;

}

void PlayerMove(char *spaces, char player){
    int num;
    do{
        std::cout << "Enter a number correspoding to spot you'd like to place your " << player << " in: ";
        std::cin >> num;
        num--;
        if (num < 0 || num > 8) {
            std::cout << "Invalid move. Please try again." << std::endl;
        } 
        else if (spaces[num] == 'X' || spaces[num] == 'O') {
            std::cout << "That spot is already taken. Please try again." << std::endl;
        } 
        else {
            spaces[num] = player;
            break;
        }
    }while(num > 0 || num < 8);
}

void ComputerMove(char *spaces, char computer){
    int num;
    do{
        num = rand() % 9;
        if (spaces[num] != 'X' && spaces[num] != 'O') {
            spaces[num] = computer;
            std::cout << "Computer placed " << computer << " in spot " << num + 1 << std::endl;
            break;
        }
        else if (spaces[num] == 'X' || spaces[num] == 'O') {

            num = (rand() % 5)-1;

            if (spaces[num] == ' ') {
            spaces[num] = computer;
            std::cout << "Computer placed " << computer << " in spot " << num + 1 << std::endl;
            break;
            }
            else{
                continue;
            }
        }
    }while(true);
}

bool CheckWinner(char *spaces, char player, char computer){

    if(spaces[0] == player && spaces[1] == player && spaces[2] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[3] == player && spaces[4] == player && spaces[5] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[6] == player && spaces[7] == player && spaces[8] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[0] == player && spaces[3] == player && spaces[6] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[1] == player && spaces[4] == player && spaces[7] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[2] == player && spaces[5] == player && spaces[8] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[0] == player && spaces[4] == player && spaces[8] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[2] == player && spaces[4] == player && spaces[6] == player){
        std::cout << "Player wins!" << std::endl;
        return true;
    }
    else if(spaces[0] == computer && spaces[1] == computer && spaces[2] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(spaces[3] == computer && spaces[4] == computer && spaces[5] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(spaces[6] == computer && spaces[7] == computer && spaces[8] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(spaces[0] == computer && spaces[3] == computer && spaces[6] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(spaces[1] == computer && spaces[4] == computer && spaces[7] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(spaces[2] == computer && spaces[5] == computer && spaces[8] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(spaces[0] == computer && spaces[4] == computer && spaces[8] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(spaces[2] == computer && spaces[4] == computer && spaces[6] == computer){
        std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else{
        return false;
    }
}

bool CheckTie(char *spaces){
    for(int i =0; i<9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout<<"Its a Tie!\n";
    return true;
}