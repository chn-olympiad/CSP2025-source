#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int vis[N],num=0,cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++)
	{
 	 		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5')
	        {
	            vis[i]=s[i]-48;
	            cnt++;
            }
            else if(s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
            {
                vis[i]=s[i]-48;
	            cnt++;
            }
            else if(!s[i])
            {
                break;
            }
        
    }
    sort(vis,vis+cnt+1);
    for(int i=cnt;i>0;i--)
    {
        cout<<vis[i];
    }
    return 0;
}
