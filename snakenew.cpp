#include <iostream>
#include <windows.h>
#include <conio.h>
#include<unistd.h>
#include<ctime>
#include<cstdlib>

using namespace std;
//dinh nghia
class snake
{
    public:
    int x;
    int y;
    int xcu; 
    int ycu;
    snake ()
    {
        
        xcu = 1; 
        ycu = 1;
        x = 1;
        y = 1;
    }
};
void dieukhien ();
void dinhnghiadieukhien ();
void inramanhinh ();
void xoamanhinh ();
void khoitaomoi ();
void rungame ();
void Vatcan1 ();
void KTVCVatcan();

int Soluongduoi = 0;

float timerunning = 200;
bool Run = true;
char key;
int diem = 0;

const int CaoConsole = 25;
const int RongConsole = 50;

snake ran[CaoConsole * RongConsole];
snake moi;

enum dieukhien
{
    LEN = 1, XUONG, TRAI, PHAI
};


int check = PHAI;
int doublecheck = PHAI;
//ham gotoxy
void gotoxy(short x, short y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

//ve khung
void vekhung ()
{
    for (int i = 0; i <= CaoConsole; i++)
    {
        gotoxy(RongConsole, i);
        cout << "*" ;
        gotoxy(0, i);
        cout << "*" ;
    }
    for (int i = 0; i <= RongConsole; i++)
    {
        gotoxy(i, CaoConsole);
        cout << "|";
        gotoxy(i, 0);
        cout << "|";
    }
}

//dieu khien
void dieukhien ()
{
    if (kbhit() == true)
    {
        key = getch();
        if (key == 'a' && doublecheck != PHAI )
        {
            check = TRAI;
            doublecheck = TRAI;
        }
        else if (key == 'd' && doublecheck != TRAI )
        {
            check = PHAI;
            doublecheck = PHAI;
        }
        else if (key == 's' && doublecheck != LEN )
        {
            check = XUONG;
            doublecheck = XUONG;
        }
        else if (key == 'w' && doublecheck != XUONG )
        {
            check = LEN;
            doublecheck = LEN;
        }
        else if (key == 'f')
        {
            Run = false;
            gotoxy((RongConsole - 8) / 2 , CaoConsole / 2);
            cout << "ket thuc";
            getch();
        }
        else if (key == 't')
        {
            timerunning -= 100; Soluongduoi++;
        }
        else if (key == 'g')
        {
            timerunning += 100; 
        }
    }
}

void dinhnghiadieukhien ()
{
        if (check == TRAI)
        {
            ran[0].x--;
        }
        else if (check == PHAI)
        {
            ran[0].x++;
        }
        else if (check == XUONG)
        {
            ran[0].y++;
        }
        else if (check == LEN)
        {
            ran[0].y--;
        }   
}

//khoi tao ran
void khoitaoran ()
{
    //update vi tri ran cu
    for (int i = 0; i < 10; i++)
    {
        ran[i].xcu = ran[i].x;
        ran[i].ycu = ran[i].y; 
    }
    //update vi tri moi cho duoi
    for (int i = 10 - 1; i >= 1; i--)
    {
        ran[i].x = ran[i - 1].x;
        ran[i].y = ran[i - 1].y;
    }
}

//in man hinh
void vedauran () 
{
    //ve dau ran
    gotoxy(ran[0].x, ran[0].y);
    cout << "0";
}
void veduoiran () 
{
    for (int i = 1; i <= Soluongduoi; i++)
    {
        gotoxy(ran[i].x, ran[i].y);
        cout << "o";    
    }
}
void inramanhinh ()
{
    //xu ly cham bien
    if (ran[0].x == RongConsole)
    {
        ran[0].x = 1;
    }
    if (ran[0].y == CaoConsole)
    {
        ran[0].y = 1;
    }
    if (ran[0].y == 0)
    {
        ran[0].y = CaoConsole - 1;
    }
    if (ran[0].x == 0)
    {
        ran[0].x = RongConsole - 1;
    }
    
    if (ran[0].x == moi.x && ran[0].y == moi.y)
    {
        khoitaomoi();
        Soluongduoi++;
        timerunning -= 10;
        diem++;
    }
    veduoiran();
    vedauran();
}

void xoadauran ()
{
    gotoxy(ran[0].xcu, ran[0].ycu);
    cout << " ";
}
void xoaduoiran ()
{
    for (int i = 1; i <= Soluongduoi; i++)
    {
        gotoxy(ran[i].xcu, ran[i].ycu);
        cout << " ";    
    } 
}
void xoamanhinh ()
{
    //thay the bang cach chen dau cach vo vi tri cu cua dau ran va duoi ran
    xoadauran();
    xoaduoiran();
}
//moi
bool KiemTraMoivoiVatcan()
{
    int y = 5;
    for (int x = 10; x <= 20; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    for (int x = 30; x <= 40; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    int x = 20;
    for (int y = 5; y <= 10; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    x = 30;
    for (int y = 5; y <= 10; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    y = 10;
    for (int x = 20; x <= 30; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    y = 20;
    for (int x = 10; x <= 20; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    y = 20;
    for (int x = 30; x <= 40; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    x = 20;
    for (int y = 15; y <= 20; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    x = 30;
    for (int y = 15; y <= 20; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    y = 15;
    for (int x = 20; x <= 30; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            return false;
        }
    }
    return true;
}

void khoitaomoi ()
{
    srand(time(NULL));
    QUAYLAIDEKHOITAOLAIMOI:
    moi.x = 0;
    while((moi.x == RongConsole) || (moi.y == CaoConsole) || (moi.x == 0) || (moi.y == 0))
    {
    moi.x = rand() % 100;
    if (moi.x > RongConsole)
    {
        moi.x = moi.x - RongConsole * (moi.x / RongConsole);
    }
    moi.y = rand() % 100;
    if (moi.y > CaoConsole)
    {
        moi.y = moi.y - CaoConsole * (moi.y / CaoConsole);
    }
    }
    for (int i = 0; i <= Soluongduoi; i++)
    {
        if (moi.x == ran[i].x && moi.y == ran[i].y)
        {
            goto QUAYLAIDEKHOITAOLAIMOI;//tránh mồi dính vào con rắn
        }
    }
    bool t;
    if (KiemTraMoivoiVatcan() == false)
    {
        goto QUAYLAIDEKHOITAOLAIMOI;
    }
    gotoxy(moi.x, moi.y);
    cout << "s";
}
bool kiemtravacham ()
{
    for (int i = 1; i <= Soluongduoi; i++)
    {
        if (ran[0].x == ran[i].x && ran[0].y == ran[i].y)
        {
            return true;
        } 
    }
    return false;
}
//ham ve vat can
void Vatcan()
{
    int y = 5;
    for (int x = 10; x <= 20; x++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    y = 5;
    for (int x = 30; x <= 40; x++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    int x = 20;
    for (int y = 5; y <= 10; y++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    x = 30;
    for (int y = 5; y <= 10; y++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    y = 10;
    for (int x = 20; x <= 30; x++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    y = 20;
    for (int x = 10; x <= 20; x++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    y = 20;
    for (int x = 30; x <= 40; x++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    //
    x = 20;
    for (int y = 15; y <= 20; y++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    x = 30;
    for (int y = 15; y <= 20; y++)
    {
        gotoxy(x, y);
        cout << "X";
    }
    y = 15;
    for (int x = 20; x <= 30; x++)
    {
        gotoxy(x, y);
        cout << "X";
    }

}

void KTVCVatcan()
{
    int y = 5;
    for (int x = 10; x <= 20; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    for (int x = 30; x <= 40; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    int x = 20;
    for (int y = 5; y <= 10; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    x = 30;
    for (int y = 5; y <= 10; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    y = 10;
    for (int x = 20; x <= 30; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    y = 20;
    for (int x = 10; x <= 20; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    y = 20;
    for (int x = 30; x <= 40; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    x = 20;
    for (int y = 15; y <= 20; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    x = 30;
    for (int y = 15; y <= 20; y++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
    y = 15;
    for (int x = 20; x <= 30; x++)
    {
        if (ran[0].x == x && ran[0].y == y)
        {
            Run = false;
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }
    }
}






//ham chay game
void rungame () 
{
    system("cls"); 

    ran[0].x = Soluongduoi+1;
    vekhung();
    Vatcan();
    khoitaomoi();
    while (Run)
    {
        
        khoitaoran();     
        dieukhien();
        dinhnghiadieukhien();
        xoamanhinh();
        inramanhinh();

        KTVCVatcan();
        
        if (kiemtravacham() && Soluongduoi > 1)
        {
            Run = false;
            
            gotoxy((RongConsole - 13) / 2 , CaoConsole / 2);
            cout << "ban thua roi!";
            getch();
        }

        gotoxy(RongConsole + 5, 0);
        cout << "Points: " << diem;

        Sleep(timerunning);
    }
    system("cls");
}


//ham main
int main () 
{
    rungame();
    return 0;
}