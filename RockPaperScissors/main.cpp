// RPS.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RockPaperScissors{
public:
    int score;
    char cpu1,player;
    char values[3];
    
	RockPaperScissors(){
		this->score = 0;
		this->values[0] = 'R';
		this->values[1] = 'P';
		this->values[2] = 'S';
	}
    
	char generateRandom(){
		srand (time(NULL));
		return values[rand() % 3];
	}
    
	char getAction(){
		char action;
		int approved = 0;
		do{
			 cout<<"\nEnter an action : \nR - Rock, P - Paper, S - Scissors :: ";
			 cin>>action;
			action = toupper(action);
			approved = (action =='R' || action == 'P'|| action == 'S') ? 1 : 0;
		} while(approved == 0);
		if(approved == 1){
			return action;
		}
        else{
            return '0';
        }
	}
    
	void updateScore(char cpu,char player){
		if(cpu == 'R' && player == 'P'){
			score++;
		}
        
		if(cpu == 'P' && player == 'S'){
			score++;
		}
		
		if(cpu == 'S' && player == 'R'){
			score++;
		} else if (cpu == player) {
            
        } else {
            score--;
        }
        
	}
    
	int getScore(){
		return score;
	}
    
	void printScoreData(){
		 cout <<"\n----------------------------------\n\tCPU\t|\tPlayer\n----------------------------------\n\t  ";
		 cout <<this->cpu1<<"\t|\t    "<<this->player;
		 cout <<"\n----------------------------------\n";
         cout << "\n\nScore : "<<this->getScore();
	}
};

int main()
{
	int times;
	RockPaperScissors game;

	do{
        std::cout<<"How many times do you want to try (1-20)? ";
        std::cin>>times;
	}while(times>20 || times <1);
	for(int i=1;i<=times;i++){
		game.cpu1 = game.generateRandom();
		game.player = game.getAction();
		game.updateScore(game.cpu1,game.player);
		game.printScoreData();
	}
    
	std::cout<<"\n\n\nFinal Score :: "<<game.getScore();
	

	return 0;
    
    
}

