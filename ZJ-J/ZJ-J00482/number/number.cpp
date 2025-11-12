#include<bits/stdc++.h>
using namespace std;
int a[1000010];
char c[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c+1;
	int l = strlen(c+1);
	int cnt = 0;
	for(int i = 1 ; i <= l ; i ++)
		if(c[i]<='9' && c[i] >= 0)
			a[++cnt] = c[i]-'0';
	sort(a+1,a+cnt+1);
	if(a[cnt] == 0)
	{
		cout<<0;
	}
	else
	{
		for(int i = cnt;i >= 1 ; i--)
		{
			cout<<a[i];
		}
	}
	return 0;
}

