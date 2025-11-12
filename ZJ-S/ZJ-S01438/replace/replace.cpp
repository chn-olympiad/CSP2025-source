#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[1000][2];
vector<int> find1(string s1,int b)
{
    vector<int> v1;
    for(int i=0;i<=s1.size()-s[b][0].size();i++)
    {
        int p=0;
        for(int j=0;j<s[b][0].size();j++)
        {
            if(s1[i+j]!=s[b][0][j])
            {
                p=1;
                break;
            }
        }
        if(p==0) v1.push_back(i);
    }
    return v1;
}
int replac(string s1,string s2)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        vector<int> v1=find1(s1,i);
        for(int j=0;j<v1.size();j++)
        {
            string s3=s1.substr(0,v1[j])+s[i][1]+s1.substr(v1[j]+s[i][0].size(),s1.size()-v1[j]+s[i][0].size());
            if(s3==s2)
                ans++;
        }
    }
    return ans;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.ans","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=0;i<q;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<<replac(s1,s2)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
