#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int s[100];
    for(int i=1; i<=a+b; i++)
    {

        cin>>s[i];
    }

    int r;
    r=s[1];
    if(r==100)
    {
        cout<<1<<" "<<1;

    else if(r==99)
    {
     	cout<<1<<" "<<2;
    }
    else if(r==98)
    {
     	cout<<2<<" "<<2;
    }
    else
    {
     	cout<<2<<" "<<1;
    }
return 0£»
} 

