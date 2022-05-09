#include <iostream>

#define MAX 52

#define MAX10(X) (X > 10) ? 10 : X

using namespace std;

//int Max10(int Number)
//{
//	return (Number > 10) ? 10 : Number;
//}

int main()
{
	int Deck[MAX] = { 0, };

	for (int i = 0; i < 52; ++i)
	{
		Deck[i] = (i % 13) + 1;
	}

	srand(static_cast<unsigned int>(time(NULL)));


	int ShuffleCount = (rand() % 20) + 2;
	for (int i = 0; i < MAX * ShuffleCount; ++i)
	{
		int FirstNumber = rand() % MAX;
		int SecondNumber = rand() % MAX;
		int Temp = Deck[FirstNumber];
		Deck[FirstNumber] = Deck[SecondNumber];
		Deck[SecondNumber] = Temp;
	}

	int Player[3] = { 0, }; // 카드칸 3개 생성
	int AI[3] = { 0, };

	for (int i = 0; i < 3; ++i)
	{
		Player[i] = Deck[i * 2];  //카드 3개를 카드칸에 대입
		AI[i] = Deck[(i * 2) + 1];
	}

	int PlayerSum = 0; 
	int AISum = 0;

	for (int i = 0; i < 3; ++i)//카드 3개중 리미트10 제한
	{
		//PlayerSum += (Player[i] > 10) ? 10 : Player[i];
		PlayerSum += MAX10(Player[i]);
		//AISum += (AI[i] > 10) ? 10 : AI[i];
		AISum += MAX10(AI[i]);

		

	}
	cout << "Player : " << Player[0] << " " << Player[1] << " " << Player[2] << " " << endl;
	cout << "AI : " << AI[0] << " " << AI[1] << " " << AI[2] << " " << endl;

	cout << "Player : " << PlayerSum << endl;
	cout << "AI : " << AISum << endl;


	if (AISum >= 22)// 이기는 조권들
	{
		cout << "Player Win" << endl;
	}
	else if (AISum <= 21 && PlayerSum <= 21)
	{
		if (PlayerSum >= AISum)
		{
			cout << "Player Win" << endl;
		}
		else
		{
			cout << "AI Win" << endl;
		}
	}
	else
	{
		cout << "AI Win" << endl;
	}





	return 0;
}
