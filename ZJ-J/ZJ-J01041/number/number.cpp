#include<bits/stdc++.h>
using namespace std;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=10;i++)
	cnt[i]=0;
	string s;
	cin>>s;
	int x,n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			x=int(s[i]-'0');
			cnt[x]++;
		}
	}
	for(int i=9;i>=0;i--)
		while(cnt[i]--)printf("%d",i);
	return 0;
}
