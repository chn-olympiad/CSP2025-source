#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int ax[123456];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	n=s.size();
	int y=0;
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'and s[i]<='9')
		{
			ax[y++]=s[i]-'0';
			y++;
		}
	}
	sort(ax+1,ax+y+1);
	for(int i=y;i>1;i--)
	{
		cout<<ax[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
