#include <iostream>
#include<windows.h>
#include <string>
#include <chrono>
#include <time.h>


/*#include <iostream>
#include "game.cpp"*/


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

    Player(string name_player, int xp)
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

    void Set_thing(string thing)
    {
        for (int i = 0; i < sizeof(back) / sizeof(back[0]); i++)
        {
            if (back[i] == "")
            {
                back[i] = thing;
                return;
            }
        }
    }

    void del_thing(string thing)
    {

        for (int i = 0; i < sizeof(back) / sizeof(back[0]); i++)
        {
            if (back[i] == thing)
            {
                back[i] = "";
                return;
            }
        }
    }

    void change_hp(int xp)
    {
        this->xp += xp;
    }



};


class Action
{

public:

    string condition;

    Action()
    {
        this->type_action = "type";
        this->thing = "thing";
        this->condition = "None";
    }

    Action(string type, string thing)
    {
        this->type_action = type;
        this->thing = thing;
        this->condition = "ops";
        this->xp = xp;
    }    
    
    Action(string type, int xp)
    {
        this->type_action = type;
        this->condition = "ops";
        this->xp = xp;
    }

    void Create_action(Player & player)
    {
        if (type_action == "give_up")
        {
            player.Set_thing(thing);
        }
        else if (type_action == "lose_up")
        {
            player.del_thing(thing);
        }
        else if (type_action == "change_hp")
        {
            player.change_hp(xp);
        }
    }

private:
    string type_action;
    string thing;
    int xp;

};


class Game
{
public:

    int TEXT_SIZE = 21;
    int speed_text = 80;
    Player player;

    Game(bool player_mode, Player player)
    {
        this->player_mode = player_mode;
        this->player = player;
    }

    Game()
    {
        this->player_mode = false;
    }

    ~Game()
    {
        delete[] text_part;
    }

    void Create_text(string need_unswer_to_transfer, string text, int* pages)
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


    void Create_text(string need_unswer_to_transfer, string text, Action & action, int* link)
    {
        Text text1(need_unswer_to_transfer, text, action, link);

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

    void Create_text(string need_unswer_to_transfer, string text, int* pages, int cha)
    {
        Text text1(need_unswer_to_transfer, text, speed_text, pages, cha);

        for (int i = 0; i < TEXT_SIZE; i++)
        {
            if (text_part[i].need_unswer_to_transfer == "need_unswer_to_transfer")
            {
                text_part[i] = text1;
                break;
            }
        }
    }

    void Create_text(string need_unswer_to_transfer, string text, int time_sleep, int* pages)
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



    void start()
    {
        cout << "Start Engine\n";

        bool start = false;
        int text_index = 0;

        /*for (size_t i = 0; i < 9; i++)
        {
            cout << (int)text_part[text_index].urls_text[i]-'0' << "-----"<< (int)text_part[text_index].urls_text[i] - '0' - 1 << endl;
        }*/

        while (true)
        {
            string result = text_part[text_index].Start(player_mode, player);
            if (result == "end")
            {
                break;
            }
            else if (result == "0" || result == "1")
            {
                text_index = text_part[text_index].urls_text[stoi(result)];
                continue;
            }


        link:
            string what_enter = "";
            //cin >> what_enter;

            if (!start)
            {
                getline(cin, what_enter);
                start = true;
            }

            getline(cin, what_enter);


            if (what_enter.length() == 0)
            {
                int need = text_part[text_index].urls_text[0];
                text_index = need;
            }
            else
            {
                try
                {
                    stoi(what_enter);
                }
                catch (const exception& ex)
                {
                    cout << "Enter true value!!!" << endl;
                    goto link;
                }

                int need = text_part[text_index].urls_text[stoi(what_enter) - 1];
                text_index = need;
            }
        }
    }

    int change_speed()
    {
        cout << "�� ����� �������� �������� �����? \n1. ����������\n2. ������� \n3. ����" << endl;
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

    bool player_mode;

    class Text
    {
    private:
        string text;
        int time_sleep;
        int cha;
        Action action;

    public:
        int urls_text[5];
        string need_unswer_to_transfer;

        Text()
        {
            this->need_unswer_to_transfer = "need_unswer_to_transfer";
            this->text = "text";
            this->time_sleep = 80;
        }

        Text(string need_unswer_to_transfer, string text, Action & action, int* pages)
        {
            this->need_unswer_to_transfer = need_unswer_to_transfer;
            this->text = text;
            this->time_sleep = 80;
            this->action = action;

            for (int i = 0; i < sizeof(urls_text) / sizeof(urls_text[0]); i++)
            {
                urls_text[i] = pages[i];
            }
        }

        Text(string need_unswer_to_transfer, string text, int time_sleep)
        {
            this->need_unswer_to_transfer = need_unswer_to_transfer;
            this->text = text;
            this->time_sleep = time_sleep;
        }

        Text(string need_unswer_to_transfer, string text, int time_sleep, int* pages)
        {
            this->need_unswer_to_transfer = need_unswer_to_transfer;
            this->text = text;
            this->time_sleep = time_sleep;

            for (int i = 0; i < sizeof(urls_text) / sizeof(urls_text[0]); i++)
            {
                urls_text[i] = pages[i];
            }
        }

        Text(string need_unswer_to_transfer, string text, int time_sleep, int* pages, int cha)
        {
            this->need_unswer_to_transfer = need_unswer_to_transfer;
            this->text = text;
            this->time_sleep = time_sleep;
            this->cha = cha;

            for (int i = 0; i < sizeof(urls_text) / sizeof(urls_text[0]); i++)
            {
                urls_text[i] = pages[i];
            }
        }

        string Start(bool player_mode, Player & player)
        {
            if (action.condition != "None")
            {
                action.Create_action(player);
            }

            for (char i : text)
            {
                if (i == '%')
                {
                    if (player_mode == true)
                    {
                        cout << "\nYour inventory:" << endl;
                        player.see_backpuck();
                    }
                    return "end";
                }
                else if (i == '@')
                {
                    if (chance(cha))
                    {
                        return "0";
                    }
                    else
                    {
                        return "1";
                    }
                }


                else
                {
                    cout << i;
                    Sleep(time_sleep);
                }
            }
            cout << endl;
            return "countinue";

        }

        bool chance(int num)
        {
            srand(time(NULL));
            return (num >= rand() % 10) ? true : false;
        }



    };

    Text* text_part = new Text[TEXT_SIZE];

};


int main()
{
    setlocale(LC_ALL, "Rus");


    Player player1("Borikmm", 10);

    Game game1(true, player1);


    int speed_text1 = game1.change_speed();
    game1.speed_text = speed_text1;


    // give_up, lose_up, change_hp
    Action action1("give_up", "���������");
    Action action2("lose_up", "Door");
    Action action3("change_xp", 1);
    Action action4("change_xp", -1);

    game1.Create_text("0", "�� ���������� � ������ �������. � ��� � �������� ������ ���. ��� ������ ������? \n1. ���������� \n2. ���������� �������� ���������", new int[2] {1, 2});
    game1.Create_text("1", "@", new int[2] {6, 7}, 5);
    game1.Create_text("2", "�� ����� ��������� <Enter>", action1, new int[1] {5});
    game1.Create_text("3", "�� ����� �����, � ������ ������������� �����. \n1. ������� ����� \n2. ������� �����", new int[2] {8, 4});
    game1.Create_text("4", "�� �������� ������� � ������� ������. ���� ����� ����� �� ���� ��������%");
    game1.Create_text("5", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("6", "�� ���������� � ���� �����������%");
    game1.Create_text("7", "�� �� ������ ���������� <Enter>", new int[1] {0});
    game1.Create_text("8", "�� ���������� ����� � ������ ����� ����� ������. �� �������� ���������� � ��� ��� �������. ��� ������ ������? \n1. ������� \n2. ������� \n3. ������������", new int[3] {9, 10, 11});
    game1.Create_text("9", "�� �������� � �������. �� ����, � ���� �������� ��� 5 ��. \n1.������� ����� \n2.���������� ������ ����������", new int[2] {3, 4});
    game1.Create_text("10", "@", new int[2] {6, 6}, 8);
    game1.Create_text("11", "����� ��� �� ��������", new int[1] {9});
    game1.Create_text("12", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("13", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("14", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("15", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("16", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("17", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("18", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("19", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});
    game1.Create_text("20", "��� ����� ������ ������? \n1. ������ ����� \n2. ������� �������", new int[2] {3, 4});


    game1.start();

    return 0;
}