#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string ari;
int bri[100001];
bool cmp(int a,int b)
{
    return a>b;
}
int sum;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>ari;
    int lenh=ari.length();
    for(int i=0;i<lenh;i++)
    {
        if(ari[i]>'0'&&ari[i]<='9')
        {
            bri[i]=ari[i]-'0';
        }
        else if(ari[i]=='0')
        {
            sum++;
            bri[i]=ari[i]-'0';
        }
    }
    sort(bri,bri+lenh,cmp);
    for(int i=0;i<lenh;i++)
    {
       if(bri[i]!=0)
       {
           cout<<bri[i];
       }
    }
    while(sum>0)
    {
        cout<<"0";
        sum--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
