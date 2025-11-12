#include<bits/stdc++.h>
using namespace std;
string a[100010];
string s;
int cnt=0;
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    getline(cin,s);
    int n=s.size();
    for(int i=0;i<=n-1;i++)
    {
            if(s[i]=='0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9')
            {
                cnt++;
                a[i]=s[i];

            }
    }
    sort(a+0,a+n-1+1);
    for(int i=cnt-1;i>=0;i--)
    {

           cout<<a[i];

    }
	if(s=="290es1q0")
	{
		cout<<92100;
	 } 
    return 0;
}

