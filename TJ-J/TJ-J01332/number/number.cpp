#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    vector<int> vct;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            vct.push_back(s[i]-'0');
        }
    }
    sort(vct.begin(),vct.end(),cmp);
    for(int i=0;i<vct.size();i++)
    {
        cout<<vct[i];
    }
    return 0;
}
