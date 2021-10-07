#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class player
{
    public:
    string name;
    int id;

//  Pawns name:position
//  eg: P1:[0,0] 
    map<string,vector<int>> pawns; 

//  initalising the player 
    player()
    {
        name = "";
        id = 0;
    }
    player(string name, int n)
    {
        this->name = name;
        id = n;
    }

//  display all the attributes 
    void display()
    {
        cout << "   Player attributes   ";
        cout << "Name: " << name<< endl;
        cout << "Player ID: " << id << endl;
    }
};

class character
{
    public: 
    string name;
    vector<int> pos;
// Initialising the character 
    character(string st, vector<int> pos)
    {
        string name = st;
        this->pos = pos;
    }

//  Display all the attributes
    void display()
    {
        cout << "   character attributes   ";
        cout << "Name: " << name;
        cout << "position (x,y): (" << pos[0] << "," << pos[1] << ")" << endl;
    }
};

class board
{
    public:
    vector<vector<int>> grid;
    vector<player> player_onboard;
    int row = 5;
    int column = 5;


//  Commands 
    enum cmd {
            L = -1,
            R = 1,
            F = 1,
            B = -1
            };
    void cmd_list()
    {
        cout<< "L : left" << endl;
        cout<< "R : right" << endl;
        cout<< "F : forward" << endl;
        cout<< "B : backward" << endl;
    }

// Initalising the board
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

//  Initialising players
    void init_b(player p1, vector<string> pawns)
    {
        int id = p1.id;
        int r;
        if (id == 1)    r = 4;
        else if (id == 2)   r = 0;

        player_onboard[id-1] = p1;
        for (int j=0; j<column ; j++)
        {    
            // eg: player 1's pawns ["P1"] = (0,0)
            player_onboard[id-1].pawns[pawns[j]] = {r,j};
            grid[r][j] = 1;
        }
    }

// Displaying the current state of the board
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

void run()
{
    player p1("A",1), p2("B",2);
    board b(p1,p2);
    
    vector<string> p1_init = {"P1","P2","P3","P4","P5"};
    vector<string> p2_init = {"P3","P1","P2","P5","P4"};
    b.init_b(p1,p1_init);
    b.display();
    b.init_b(p2,p2_init);
    b.display();
}

int main()
{
    run();
    return 0;
}