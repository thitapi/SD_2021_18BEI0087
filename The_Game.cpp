#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class player
{
    public:
    string name;
    int num;

    player(string name, int n)
    {
        this->name = name;
        num = n;
    }
};
class character
{
    public: 
    string name;
    vector<int> pos;

    character(string st, vector<int> pos)
    {
        string name = st;
        this->pos = pos;
    }

};

class board
{
    public:
    vector<vector<int>> grid;
    vector<player> player_onboard;
    int row = 5;
    int column = 5;

    board()
    {
        for(int i =0; i<row; i++)
        {
            vector<int> temp;
            for(int j=0; j<column; j++)
            {
                temp.push_back(0);
            }
            grid.push_back(temp);
        } 
    }

    board(player p1, player p2)
    {
        player_onboard = {p1,p2};
        for(int i =0; i<row; i++)
        {
            vector<int> temp;
            for(int j=0; j<column; j++)
            {
                temp.push_back(0);
            }
            grid.push_back(temp);
        } 
    }

    void display()
    {
        for(int i = 0; i<row; i++)
        {
            for (int j=0; j<column ; j++)
            cout << grid[i][j] << "     ";
            cout << endl;
        }
    }
};

int main()
{
    player p1("A",1), p2("B",2);
    board b(p1,p2);
    b.display();
    return 0;
}