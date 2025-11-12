#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n,i,b[N],t;
char a[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a+1;
	n=strlen(a+1);
	for(i=1;i<=n;i++)
		if(a[i]>='0'&&a[i]<='9')b[++t]=a[i]-48;
	sort(b+1,b+1+t);
	for(i=t;i>=1;i--)cout<<b[i];
	return 0;
}
