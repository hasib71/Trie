#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define gi(a) sf("%d", &a)
#define gi2(a, b) sf("%d%d", &a, &b)
#define gi3(a, b, c) sf("%d%d%d", &a, &b, &c)
#define gi4(a, b, c, d) sf("%d%d%d%d", &a, &b, &c, &d)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)

using namespace std;


map<int, map<int , int > > dir;

struct node{
    bool end_here;
    int id;
    node()
    {
        end_here = 0;
    }
};

vector<node>allnodes;

node head;


void addNode(string str)
{
    node *current = &head;
    char ch;
    int *pt;

    loop(i, SZ(str))
    {
        ch = str[i] - 'a';

        pt = &dir[current->id][ch];

        if(*pt == 0)
        {
            *pt = SZ(allnodes) + 1;
            current = new node();
            current->id = *pt;
            allnodes.pb(*current);
        }
        else
        {
            current = &allnodes[*pt - 1];
        }
    }
    allnodes[*pt - 1].end_here = 1;
}


bool find(string str)
{
    node *current = &head;
    char ch;
    int *pt;
    loop(i, SZ(str))
    {
        ch = str[i] - 'a';

        pt = &dir[current->id][ch];

        if(*pt == 0)
        {
            return 0;
        }
        else
        {
            current = &allnodes[*pt - 1];
        }
    }

    return current->end_here;
}


int main()
{
    head.end_here = -1;
    head.id = 1;
    allnodes.pb(head);

    addNode("hasib");
    addNode("enjam");
    addNode("enjami");

    cout<<find("hasib")<<endl;
    cout<<find("rajakar")<<endl;
    cout<<find("enjami")<<endl;
    cout<<find("enzam");




    return 0;
}

