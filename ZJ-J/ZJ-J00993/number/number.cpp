#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto i:s)
    {
        if(isdigit(i))
        {
            v.push_back(i-'0');
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    size_t i=0;
    while(i>1 && v[i]==0) i++;
    for(;i<v.size();i++)
    {
        cout<<v[i];
    }
    return 0;
}