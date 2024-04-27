#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>

using namespace std;


int main() {

	srand(time(0)); // ������ ���������� ��������� �����
	system("title Snake Game");
	system("mode con cols=70 lines=31"); // ��������� �������� ���� �������
	MoveWindow(GetConsoleWindow(), 50, 50, 2000, 2000, true); // ��������� ��������� ������� ���� ������� (50 � 50 - ��� �������
	// ������������ �������� ������ ���� ��������
	const int width = 50, height = 30; // ������� ����, �� �������� ������ ������

	
	const int max_length = 6; // ��������� ������������ ����� "������"
	const int max_length2 = 6;
	int array_X[max_length]; // ������,�������� �������� ������� "������"
	int array_Y[max_length];// ������, �������� �������� ������� "������"
	int array_X2[max_length]; // ������,�������� �������� ������� "������"
	int array_Y2[max_length];

	int length = 1; // ���������� ����� "������"
	int length2= 1;
	array_X[0] = width / 2; // ��������� ��������� �������� "������"
	array_Y[0] = height / 2; // ��������� ��������� �������� "������"
	array_X2[0] =  (width / 2) + 1; // ��������� ��������� �������� "������"
	array_Y2[0] =  (height / 2) + 1;

	int dx = 1, dy = 0; // �������� �������� �� ���� ��� �������� "������"
	int dx2 = 1, dy2 = 0;
	int X_apple; // �������� "������"
	int Y_apple; // �������� "������"
	do // ���� ������ ���������� ������ �������� ������� - �� ����� ��� �� ��������� �� "�������"
	{
		X_apple = rand() % (width - 2) + 1;
		Y_apple = rand() % (height - 2) + 1;
	} while (X_apple != array_X[length - 1] && Y_apple != array_Y[length - 1]&& X_apple != array_X2[length2 - 1] && Y_apple != array_Y2[length2 - 1]);

	int sleep_time = 200; // ���������� ������� ������ SPEED

	char snake = '*'; // ������ ��� ����������� ���� "������"

	char apple = 'o'; // ������ ��� ����������� "������"
	char head = 1; // ������ ��� ����������� ������ "������"
	char head2 = 1;
	COORD c; // ������ ��� �������� ���������
	COORD c2;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ������ ������ ������
	HANDLE h2 = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false }; // �������� ���������� �� ����������� �������
	CONSOLE_CURSOR_INFO cci2 = { sizeof(cci2), false };
	SetConsoleCursorInfo(h, &cci); //���������� ���������� � ������
	SetConsoleCursorInfo(h2, &cci2);

	SetConsoleTextAttribute(h, 4); // ��������� �����, ������� �������� ����� ����
	for (int y = 0; y < height; y++) // ����������� ������� ���� �� ��������� �����
	{
		for (int x = 0; x < width; x++)
		{
			char s;
			 if (x == 0 && y == 0) // � ������� ����� ���� ���� - ������ ���������������� ����
				s = '#'; // 218
			else if (x == 0 && y == height - 1) // ������ ����� ����
				s = '#'; // 192
			else if (y == 0 && x == width - 1) // ������� ������ ����
				s = '#'; // 191
			else if (y == height - 1 && x == width - 1) // ������ ������ ����
				s = '#'; // 217
			else if (y == 0 || y == height - 1) // ������� � ������ ������� ����
				s = '#'; // 196
			else if (x == 0 || x == width - 1) // ����� � ������ ������� ����
				s = '#'; // 179
			else s = ' '; // �� ���� ��������� ������� ������ ���� ������ ������ (�������� ������ ������� ����)
			cout << s; // ������� ������
			
		}
		cout << "\n";
	}

	c.X = X_apple; // ��������� ������ ��������� � ��������� "������"dfgdf
	c.Y = Y_apple;
	SetConsoleCursorPosition(h, c); // ���������� ������ �� ������� "������"
	SetConsoleTextAttribute(h, 12); // ������������� ������� ���� ��� ��������� "������"
	cout << apple; // ���������� ������ "������"

	c.X = array_X[0]; // ��������� ������ ��������� �� ��������� �������� "������"
	c.Y = array_Y[0];
	SetConsoleCursorPosition(h, c); // ���������� ������ �� ������� ������ "������"
	SetConsoleTextAttribute(h, 10); // ������������� ������� ���� ��� ��������� "������"
	cout << head; // ���������� ������ ������ "������"

	c2.X = array_X2[0]; 
	c2.Y = array_Y2[0];
	SetConsoleCursorPosition(h2, c2); 
	SetConsoleTextAttribute(h2, 11); 
	cout << head2; 

	bool flag = true; // ���������� ��� ���������� ����� �����
	do //  ���� ����
	{
		Sleep(sleep_time); // �������� ������ ��������� �� �������� ����� ��������
		
		if (_kbhit()) // ���������, ���� �� ������ �����-���� ������� � ��������� � ��������� � ������ ������
		{
			int k = _getch(); // ��������� ��� ������� �� ������
			if (k == 0 || k == 224) // ���� ������ ��� - ���������������, ��������� ������ ���
				k = _getch();
			switch (k) // ���������� ��� ������� ������� ������ ��������� ������
			{
			case 80 : // ���� ���� ������ ������� ����
					dy = 1; // �� ���������� �� ��� ������� ����� �������������
					dx = 0;// �� ��� ������� ���������� �������
					break;
				
			case  115:
				dy2 = 1; 
				dx2 = 0;
				break;
								
			case 72: // ���� �����
				dy = -1; // ���������� �������� �������������� ������
				dx = 0;
				break;
			case 119: // ���� �����
				dy2 = -1; // ���������� �������� �������������� ������
				dx2 = 0;
				break;

			case 75: // ���� �����
				dy = 0;
				dx = -1;
				break;

			case 97: // ���� �����
				dy2 = 0;
				dx2 = -1;
				break;

			case 77: // ���� ������
				dy = 0;
				dx = 1;
				break;

			case 100: // ���� ������
				dy2 = 0;
				dx2 = 1;
				break;

			case 27: // ���� ���� ������ ������� ESC
				flag = false; // ������������� ������ �� ����, ���� ��������� ����� ��������
				break;
			}
		}

		int X = array_X[length - 1] + dx; // ���������� �������� �������� ������ "������" ����� ��������
		int Y = array_Y[length - 1] + dy; // �� �� ����� ��� ��������
		int X2 = array_X2[length2 - 1] + dx2;
		int Y2 = array_Y2[length2 - 1] + dy2;
			

		if (X == X_apple && Y == Y_apple || X2 == X_apple && Y2 == Y_apple) // �������� �� ���������� "������"
		{
		
			if (X == X_apple && Y == Y_apple)
			{
				c.X = array_X[length - 1]; // ��������� � ������ ��������� ������� ������ "������"
				c.Y = array_Y[length - 1];
				SetConsoleCursorPosition(h, c); // ��������� ������� � ��� �������
				SetConsoleTextAttribute(h, 10);
				cout << snake; // ����������� ������� ���� "������"

				length++; // ���������� ����� "������" (������ ����������)
				c.X = array_X[length - 1] = X; // ��������� � ������� ������� ������ ����� "������"
				c.Y = array_Y[length - 1] = Y;

				SetConsoleCursorPosition(h, c); // ��������� ���� �������
				SetConsoleTextAttribute(h, 10);
				cout << head; // � ����������� ��� ������� ������ "������"
			}

			if (X2 == X_apple && Y2 == Y_apple)
			{
				c2.X = array_X2[length2 - 1]; 
				c2.Y = array_Y2[length2 - 1];
				SetConsoleCursorPosition(h2, c2); 
				SetConsoleTextAttribute(h2, 11);
				cout << snake; 

				length2++; 
				c2.X = array_X2[length2 - 1] = X2; 
				c2.Y = array_Y2[length2 - 1] = Y2;
				SetConsoleCursorPosition(h2, c2); 
				SetConsoleTextAttribute(h2, 11);
				cout << head; 

			}

			if (length == max_length || length2 == max_length2) // ��������, �������� �� ����� "������" ������ ������������� ��������
			{
				if (length == max_length) { cout << " Win Player 1 GREEN "; };
				if (length2 == max_length2) { cout << " Win Player 2 BLUE "; };
				this_thread::sleep_for(chrono::milliseconds(2000));
				break; 
			}
			
			
			int i,r; // ���������� ��� �������� ���������� ������� "������", �� ����������� � �������� "������"
			do {
				X_apple = rand() % (width - 2) + 1; // ��������� ����� ��������� "������"
				Y_apple = rand() % (height - 2) + 1;
				i = 0; r = 0;// ��������� ����� ������������� ���������
				for (; i < length; i++) // ������ ����� �� ������ ����������
					if (X_apple == array_X[i] && Y_apple == array_Y[i] ) // ���� ���������� �������
						break; 

				for (; r < length2; r++) 
					if ( X_apple == array_X2[r] && Y_apple == array_Y2[r]) 
						break;

			} while (i < length || r < length2); // ����� ����� ��������� ������������, ���� ����� ������������� ��������� ������ ����� "������"

			c.X = X_apple; // ��������� � ������ ��������� ����� ���������� ������� "������"
			c.Y = Y_apple;
			SetConsoleCursorPosition(h, c); // �������� ���� �������
			SetConsoleTextAttribute(h, 12); // ��������� ����� � �������
			cout << apple; // ����������� ������� "������"

			SetConsoleTextAttribute(h, 10); // �������� ��������� ����� � ������� - ��� ����������� ����������� "������"
			
		}
	
		else // ������, ����� ������ "������" ��������� �� ����� ������ �������
		{
		
			int i = 1;// ���������� �� ���������� �������, �� ����������� � ����� �������� - ����� ������ "������"
			int r = 1;
			for (; i < length; i++)
				if (X == array_X[i] && Y == array_Y[i] ) // ���� ���������� ������� � ����� - �����������
				{
					cout << " Crash - Win Player 1 BLUE ";
					this_thread::sleep_for(chrono::milliseconds(2000));
					break;
				};
					
			if (i < length ) // ���� ����� ������������� ������� ������ ����� "������" - �� ��������� �������� ���� ����
				break;

			for (; r < length2; r++)
				if ( X2 == array_X2[r] && Y2 == array_Y2[r]) // ���� ���������� ������� � ����� - �����������
				{
					cout << " Crash - Win Player 1 GREEN ";
					this_thread::sleep_for(chrono::milliseconds(2000));
					break;
				};
					
			if ( r < length2) // ���� ����� ������������� ������� ������ ����� "������" - �� ��������� �������� ���� ����
				break;



			else  // � ����� ��������� ��������� ������ "������"
			{
				
				if (X != 0 && X != width - 1 && Y != 0 && Y != height - 1)
				{
					c.X = array_X[0]; // ������������� � ������ ��������� ������� ������ "������"
					c.Y = array_Y[0];
					SetConsoleCursorPosition(h, c); // ������� ���� ������
					cout << ' '; // � ���������� ������ (������� ������)
				}

				if (X2 != 0 && X2 != width - 1 && Y2 != 0 && Y2 != height - 1)
				{
					c2.X = array_X2[0];
					c2.Y = array_Y2[0];
					SetConsoleCursorPosition(h2, c2);
					cout << ' ';
				}

				if (X != 0 && X != width - 1 && Y != 0 && Y != height - 1)
				{
					if (length > 1) // ���� ����� ������ ������ 
					{
						c.X = array_X[length - 1]; // ������������� � ������ ��������� ���������� ������� ������ "������"
						c.Y = array_Y[length - 1];
						SetConsoleCursorPosition(h, c);  // ������� ���� ������
						SetConsoleTextAttribute(h, 10);
						putchar(snake); // ������� ������ ���� "������"
					}
				}
				
				if (X2 != 0 && X2 != width - 1 && Y2 != 0 && Y2 != height - 1)
				{
					if (length2 > 1)
					{
						c2.X = array_X2[length2 - 1];
						c2.Y = array_Y2[length2 - 1];
						SetConsoleCursorPosition(h2, c2);
						SetConsoleTextAttribute(h2, 11);
						putchar(snake);
					}
				}
				
				if (X != 0 && X != width - 1 && Y != 0 && Y != height - 1)
				{
					for (int i = 0; i < length - 1; i++) // ��������� ���� ������ ��������� ������� "������"
					{
						array_X[i] = array_X[i + 1]; // ������������ ��� ������ - ����� ����������
						array_Y[i] = array_Y[i + 1];
						
					}
				}

				if (X2 != 0 && X2 != width - 1 && Y2 != 0 && Y2 != height - 1)
				{
					for (int r = 0; r < length2 - 1; r++)
					{
						array_X2[r] = array_X2[r + 1];
						array_Y2[r] = array_Y2[r + 1];
						
					}
				}

				if (X != 0 && X != width - 1 && Y != 0 && Y != height - 1)
				{
					c.X = array_X[length - 1] = X; // ������������� ����� ������� ������ "������"
					c.Y = array_Y[length - 1] = Y;
					SetConsoleCursorPosition(h, c); // ������� ���� �������
					SetConsoleTextAttribute(h, 10);
					cout << head; // ���������� ������ ������ "������"
				}
								
				if (X2 != 0 && X2 != width - 1 && Y2 != 0 && Y2 != height - 1)
				{
					c2.X = array_X2[length2 - 1] = X2;
					c2.Y = array_Y2[length2 - 1] = Y2;
					SetConsoleCursorPosition(h2, c2);
					SetConsoleTextAttribute(h2, 11);
					cout << head2;
					
				}

				for (size_t i = 0; i < length2; i++) //��������� ������ ����� �����������
				{
					c2.X = array_X2[i];
					c2.Y = array_Y2[i];
					SetConsoleCursorPosition(h2, c2);
					SetConsoleTextAttribute(h2, 11);
					if (i == length2 - 1) {
						cout << head2; break;
					}
					putchar(snake);
				}

				for (size_t i = 0; i < length; i++)
				{
					c.X = array_X[i];
					c.Y = array_Y[i];
						SetConsoleCursorPosition(h, c);
						SetConsoleTextAttribute(h, 10);
						if (i == length -1) {
							cout << head; break;
						}
						putchar(snake);
				}

			}
					
		}
		
	} while (flag); // ������� �� �����, ���� �������� ����������� ����������
	system("cls"); // ������� �����
	cout << "GAME OVER\n"; // ������� ��������� � ����� ����
};