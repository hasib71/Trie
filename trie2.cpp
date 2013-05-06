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

/*
struct node{
    bool endHere;
    node()
    {
        endHere = 0;
    }
};
*/

struct TRIE{

    vector<string>comeHere; //will be mapped here
    vector<int>allNodes;
    map<int, map<int, int> > childID;



    TRIE()
    {
        //constructor
        allNodes.pb(-1);
    }

    void add(string str, string value)
    {
        int *pt = new int(0); //head
        char ch;

        loop(i, SZ(str))
        {
            ch = str[i];

            if('a' <= ch && ch <= 'z')
            {
                ch = ch - 'a';
            }
            else if('A' <= ch && ch <= 'Z')
            {
                ch = ch - 'A' + 26;
            }

            pt = &childID[*pt][ch];

            if(*pt == 0)
            {
                allNodes.pb(-1);
                *pt = SZ(allNodes);
            }
        }

        allNodes[*pt - 1] = SZ(comeHere);
        comeHere.pb(value);
    }


    int find(string str)
    {
        int *pt = new int(0);
        char ch;

        loop(i, SZ(str))
        {
            ch = str[i];

            if('a' <= ch && ch <= 'z')
            {
                ch = ch - 'a';
            }
            else if('A' <= ch && ch <= 'Z')
            {
                ch = ch - 'A' + 26;
            }

            pt = &childID[*pt][ch];

            if(*pt == 0)
            {
                return -1; //not found
            }
        }

        return allNodes[*pt - 1]; //returning index
    }
};



int main()
{
    TRIE tt;
    int pos;
    tt.add("hasib", "1");
    tt.add("hasib", "1");
    tt.add("hasib", "1");
    tt.add("hasib", "1");
    tt.add("has", "2");


    pos = tt.find("hasib");

    if(pos >= 0)
    {
        cout<<tt.comeHere[pos]<<endl;
    }
    else
    {
        cout<<"NOT FOUND"<<endl;
    }




    return 0;
}

