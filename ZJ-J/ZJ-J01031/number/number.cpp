#include<bits/stdc++.h>
using namespace std;
string s;
vector <int> a;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(auto c:s)
    {
        if(c>='0'&&c<='9')
        {
            a.push_back(c-'0');
        }
    }
    sort(a.begin(),a.end(),cmp);
    for (auto i : a)
    {
        cout << i;
    }
    return 0;
}