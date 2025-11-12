#include<bits/stdc++.h>
using namespace std;
int const N=1e6+5;
char str[N];
int num[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(str+1);
	int len=strlen(str+1);
	int n=0;
	for(int i=1;i<=len;i++)
		if(str[i]>='0'&&str[i]<='9')
			num[++n]=(str[i]^48);
	sort(num+1,num+n+1);
	if(num[n]==0){
		cout<<0;
		return 0;
	}
	for(int i=n;i>=1;i--)
		cout<<num[i];
	return 0;
}