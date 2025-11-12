#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1[1005],s2[1005];
vector<int> ans;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    while(q--)
    {
        ans.clear();
        string t1,t2;
        cin>>t1>>t2;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j+s1[i].size()-1<t1.size();j++)
            {
                bool flag=1;
                for(int k=j;k<=j+s1[i].size()-1;k++)
                {
                    if(s1[k-j]!=s1[k])flag=0;
                }
                if(flag)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
