#include <iostream>
#include<windows.h>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;



class Player
{
private:

public:
    int xp = 10;
    string name_player;
    string back[5];

    Player()
    {
        this->name_player = "Player";
        this->xp = 10;
    }

    void Set_Player(string name_player, int xp)
    {
        this->name_player = name_player;
        this->xp = xp;
    }

    int Get_XP()
    {
        return xp;
    }

    string* Get_backpuck()
    {
        string backpuck[sizeof(back) / sizeof(back[0])];

        for (int i = 0; i < sizeof(back) / sizeof(back[0]); i++)
        {
            backpuck[i] = back[i];
        }
        return backpuck;
    }

    void see_backpuck()
    {
        for (int i = 0; i < sizeof(back) / sizeof(back[0]); i++)
        {
            cout << back[i] << endl;
        }
        cout << endl;
    }

    void Set_XP(int damage)
    {
        xp -= damage;
    }

    string Set_thing(string thing)
    {
        for (int i = 0; i < sizeof(back) / sizeof(back[0]); i++)
        {
            if (back[i] == "0")
            {
                back[i] = thing;
                return "Complete setup";
            }
            else
            {
                return "None space";
            }
        }
    }
};


class Game : public Player
{
public:

    int speed_text = 80;

    ~Game()
    {
        delete[] text_part;
    }

    void Create_text(string need_unswer_to_transfer, string text, char* pages)
    {
        Text text1(need_unswer_to_transfer, text, speed_text, pages);

        for (int i = 0; i < TEXT_SIZE; i++)
        {
            if (text_part[i].need_unswer_to_transfer == "need_unswer_to_transfer")
            {
                text_part[i] = text1;
                break;
            }
        }
    }

    void Create_text(string need_unswer_to_transfer, string text)
    {
        Text text1(need_unswer_to_transfer, text, speed_text);

        for (int i = 0; i < TEXT_SIZE; i++)
        {
            if (text_part[i].need_unswer_to_transfer == "need_unswer_to_transfer")
            {
                text_part[i] = text1;
                break;
            }
        }
    }

    void Create_text(string need_unswer_to_transfer, string text, int time_sleep, char* pages)
    {
        Text text1(need_unswer_to_transfer, text, time_sleep, pages);

        for (int i = 0; i < TEXT_SIZE; i++)
        {
            if (text_part[i].need_unswer_to_transfer == "need_unswer_to_transfer")
            {
                text_part[i] = text1;
                break;
            }
        }
    }

    void Create_text(string need_unswer_to_transfer, string text, int time_sleep)
    {
        Text text1(need_unswer_to_transfer, text, time_sleep);

        for (int i = 0; i < TEXT_SIZE; i++)
        {
            if (text_part[i].need_unswer_to_transfer == "need_unswer_to_transfer")
            {
                text_part[i] = text1;
                break;
            }
        }
    }

    void start()
    {
        cout << "Start Engine\n";

        int text_index = 0;

        /*for (size_t i = 0; i < 9; i++)
        {
            cout << (int)text_part[text_index].urls_text[i]-'0' << "-----"<< (int)text_part[text_index].urls_text[i] - '0' - 1 << endl;
        }*/

        while (true)
        {
            if (!text_part[text_index].Start())
            {
                break;
            }

        link:
            string what_enter;
            cin >> what_enter;

            try
            {
                stoi(what_enter);
            }
            catch (const exception& ex)
            {
                cout << "Enter true value!!!" << endl;
                goto link;
            }

            if (what_enter == " ")
            {
                text_index++;
            }
            else
            {
                int need = (int)text_part[text_index].urls_text[stoi(what_enter) - 1] - '0';
                text_index = need;
            }

        }
    }

    int change_speed()
    {
        cout << "На какой скорости печатать текст? \n1. Нормальная\n2. Быстрая \n3. Своя" << endl;
        int number;
    link:
        try
        {
            cin >> number;
        }
        catch (const exception& ex)
        {
            cout << "Enter true value!!!" << endl;
            goto link;
        }

        switch (number)
        {
        case 1:
            return 80;
            break;
        case 2:
            return 10;
            break;
        case 3:
            int speed;
            cin >> speed;
            return speed;
            break;
        }

    }

private:
    int TEXT_SIZE = 5;

    class Text
    {
    private:
        string text;
        int time_sleep;

    public:
        char urls_text[10];
        string need_unswer_to_transfer;

        Text()
        {
            this->need_unswer_to_transfer = "need_unswer_to_transfer";
            this->text = "text";
            this->time_sleep = 80;
        }

        Text(string need_unswer_to_transfer, string text, int time_sleep)
        {
            this->need_unswer_to_transfer = need_unswer_to_transfer;
            this->text = text;
            this->time_sleep = time_sleep;
        }

        Text(string need_unswer_to_transfer, string text, int time_sleep, char* pages)
        {
            this->need_unswer_to_transfer = need_unswer_to_transfer;
            this->text = text;
            this->time_sleep = time_sleep;

            for (int i = 0; i < sizeof(urls_text) / sizeof(urls_text[0]); i++)
            {
                urls_text[i] = pages[i];
            }
        }

        bool Start()
        {
            for (char i : text)
            {
                if (i == '%')
                {
                    return false;
                }
                else
                {
                    cout << i;
                    Sleep(time_sleep);
                }
            }
            cout << endl;
            return true;

        }
    };

    Text* text_part = new Text[TEXT_SIZE];

    class location
    {
    private:
        string location_name;
        Text* text = new Text[6];

    public:

        location(string location)
        {
            this->location_name = location;
        }

        ~location()
        {
            delete[] text;
        }

        void Add_text_parts(Text* pages)
        {
            for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
            {
                text[i] = pages[i];
            }
        }

        void Start()
        {
            for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
            {
                text[i].Start();
            }
        }
    };
};





int main()
{
    setlocale(LC_ALL, "Rus");

    Game game1;


    game1.see_backpuck();
    game1.Set_Player("Borikmm", 10);
    game1.see_backpuck();

    /*int speed_text1 = game1.change_speed();
    game1.speed_text = speed_text1;

    game1.Create_text("First", "Вы находитесь в темной комнате. У вас в карманах ничего нет. Что будете делать? \n1. Проснуться \n2. Попытаться нащупать зажигалку", new char[2] {'1', '2'});
    game1.Create_text("1", "Вы проснулись и игра закончилась%");
    game1.Create_text("2", "Вы нашли зажигалку и зажгли огонь \n1. Искать выход \n2. Поджечь комнату", new char[2] {'3', '4'});
    game1.Create_text("3", "Вы ищите выход, и вскоре обнаруживаете дверь. \n1. Открыть дверь \n2. Поджечь дверь", new char[2] {'5', '6'});
    game1.Create_text("4", "Вы подожгли комнату и сгорели заживо. Ваши крики никем не были услышаны%");

    game1.start();*/

    return 0;
}


