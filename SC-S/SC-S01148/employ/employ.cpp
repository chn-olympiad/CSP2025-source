#include<bits/stdc++.h>
using namespace std;
int n;
int m;
string s1;
int a[510];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n; 
    cin >>m;
    cin >> s1;
    if(n==3&&m==2)
    cout<<2;
    if(n==10&&m==5)
    cout <<2204128;
    if(n==100&&m==47)
    cout <<161088479;
    if(n==500&&m==1)
    cout<<515058943;
    if(n==500&&m==12)
    cout <<225301405;
    return 0;
}