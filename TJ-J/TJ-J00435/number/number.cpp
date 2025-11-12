#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int jiecheng(int n)  //correct
{
    int cnt=1;
    for (int i=n;i>0;i--)
    {
        cnt*=i;
    }
    return cnt;
}
vector< vector<int> > t;
int pailie(int downindex)
{
    if (t[downindex].size()==1)
    {
        return downindex;
    }
    vector<int> returnvalue;
    for (int i=0;i<t[downindex].size();i++)
    {
        vector<int> temp1;
        for (int j=0;j<t[downindex].size();j++)
        {
            if (j==i)
            {
                continue;
            }
            int ee=t[downindex][j];
            vector<int> aa;
            while(ee>=10)
            {
                aa.push_back(ee/10);
            }
            vector<int> aaa;
            int eee=0;
            for (int s=aa.size()-1;s>=0;s++)
            {
                eee+=aa[s]*(s*10);
            }
            temp1.push_back(eee);
        }
        t.push_back(temp1);
        int f=t.size()-1;
        int g=pailie(f);
        vector<int> temp2=t[g];
        for (int j=0;j<temp2.size();j++)
        {
            int e=(temp2.size()*10)+temp2[j];
            returnvalue.push_back(e);
        }
    }
    /*
    for (int i=0;i<returnvalue.size();i++)
    {

        cout<<returnvalue[i]<<' ';
    }
    cout<<endl;
    */
    t.push_back(returnvalue);
    int h=t.size()-1;
    return h;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    vector<int> number;
    for (int i=0;i<str.size();i++)    //First,get the number list.
    {
        if (str[i]=='0' || str[i]=='1' || str[i]=='2'|| str[i]=='3'|| str[i]=='4' || str[i]=='5'|| str[i]=='6'|| str[i]=='7'|| str[i]=='8'|| str[i]=='9')
        {
            number.push_back(str[i]-'0');
        }
    }
    //correct
    t.push_back(number);
    int f=t.size()-1;
    //correct
    int g=pailie(f);
    vector<int> result=t[g];
    int maxn=0;
    for (int i=0;i<result.size();i++)
    {
        maxn=max(maxn,result[i]);
    }
    cout<<maxn<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
