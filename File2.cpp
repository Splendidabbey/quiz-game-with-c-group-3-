#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define QNO 30
#define totques 10

using namespace std;

void Display()
	{
		cout<<"\n\n\n\n\n\n";
		cout<<"\n\t   +-------+                          _______       _______                             ";
		cout<<"\n\t   |       |      |         |            |                /                              ";
		cout<<"\n\t   |       |      |         |            |               /                               ";
		cout<<"\n\t   |       |      |         |            |              /                                ";
		cout<<"\n\t   |    // |      |         |            |             /                                 ";
		cout<<"\n\t   |   //  |      |         |            |            /                                  ";
		cout<<"\n\t   +--//---+      |_________|         ___|___        /_______                          ";
		cout<<"\n\n\n\n\n\n\t\t\t   PRESS ENTER TO PLAY     ";
		cout<<"\n\n\n\t\t\t\t   RULES OF THE GAME   :     \n";
		cout<<"\t\t\t\t   1) 4 MARKS WILL BE AWARDED FOR CORRECT     \n";
		cout<<"\t\t\t\t   2) NO MARKS WILL AWARDED FOR INCORRECT     \n";
		cout<<"\t\t\t\t   3) SCORE CARD WILL BE GIVEN AT END         \n";
		system("pause");
		system("cls");				
	}

void asked(string option,string option1,string option2,
	string option3,string option4,string correct,string category,ofstream& fp,int *score)
{
	cout << "Your Option : ";
	cin >> option;
	transform(option.begin(), option.end(), option.begin(), ::toupper);
	option.append(")");
	
	fp<<category<<endl;
	
	if (option[0] == correct[0])
	{
		if (option[0] == option1[0])
			fp << " Your entered correct answer  : " << option1 << endl;
		if (option[0] == option2[0])
			fp << " Your entered correct answer  : " << option2 << endl;
		if (option[0] == option3[0])
			fp << " Your entered correct answer  : " << option3 << endl;
		if (option[0] == option4[0])
			fp << " Your entered correct answer  : " << option4 << endl;
			
			*score += 4;
			fp<<" You are awarded 4 marks for this correct answer "<<endl;
	}
	else
	{
		string correctanswer;
		if (correct[0] == option1[0])
			correctanswer = option1;
		if (correct[0] == option2[0])
			correctanswer = option2;
		if (correct[0] == option3[0])
			correctanswer = option3;
		if (correct[0] == option4[0])
			correctanswer = option4;

		string wronganswer;
		
		if (option[0] == option1[0])
			wronganswer = option1;
		if (option[0] == option2[0])
			wronganswer = option2;
		if (option[0] == option3[0])
			wronganswer = option3;
		if (option[0] == option4[0])
			wronganswer = option4;

		fp << " You entered     : " << wronganswer << endl;
		fp << " Correct answer  : " << correctanswer << endl;
		fp << " You are awarded 0 marks for this wrong answer "<<endl;
		
	
	}
		fp<<" -----------------------------------------------------------------------------\n";		
		fp<<" -----------------------------------------------------------------------------\n";

}

int main()
{

	ifstream fins("Quiz.txt");
	ofstream output("NewText.txt");
	string text;
	string option1, option2, option3, option4,option,correct,category;
	int score = 0;
	int arr[QNO];
	
	if(fins == NULL)
	{
		cout<<"\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n";
	}
	if(output == NULL)
	{
		cout<<"\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n";
	}
	Display();
	
	for (int i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}
	
	for (int j = 0; j < totques; j++)
	{
		srand(time(NULL));
		int x = rand()%3;
		int loc = (3 * j) + x;
	    
		for (int i = arr[3*j]; i < arr[loc]; i++)
		{
			string empty;
			getline(fins, empty);
		}

		for (int i = 1; i <= 10; i++)
		{
			getline(fins, text);
			
			if(i==1)
			{
			  cout<<"\n\n\n\n\n\nQ"<<j+1<<") "<<text;
			  output<<"\nQ"<<j+1<<") "<<text<<endl;
			}
			
				if(i==2)
				{
					output<<text<<endl;	
				}
			
			if(i==3)
			option1 = text;
			
			if(i==4)
			option2 = text;
			
			if(i==5)
			option3 = text;
			
			if(i==6)
			option4 = text;
			
			if (i>1 &&  i<= 7)
				cout << text << endl;

			if (i == 8)
				correct = text.substr(0, 40);
			if (i == 9)
				category = text.substr(0, 40);
		}

		asked(option, option1, option2, option3, option4, correct, category,output,&score);
		
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		{
			for (int i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
				string empty;
				getline(fins, empty);
			}
		}
		system("cls");
	}
	output<<"\n You got "<< score/4<<" correct answer with total score : "<<score<<" out of 40 ";
	
	fins.close();
	output.close();
	
	ifstream out("NewText.txt");
	string read;
	
	while(getline(out,read))	
	{
		cout<<read<<endl;
	}
	
	system("pause");
	return 0;
}










