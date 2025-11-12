#include<bits/stdc++.h>
using namespace std;
int i,j,n,f[1010];
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a+1;
	n=strlen(a+1);
	for(i=1;i<=n;i++)
		f[a[i]]++;
	for(i='9';i>='0';i--)
		for(j=1;j<=f[i];j++)
			cout<<char(i);
}
