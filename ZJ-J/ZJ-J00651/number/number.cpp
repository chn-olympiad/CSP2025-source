#include<bits/stdc++.h>
using namespace std;
int n,i,j,a[10];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c)
		if('0'<=c&&c<='9')
			a[c-'0']++;
	for(i=9;i>=0;i--)
		for(j=1;j<=a[i];j++)
			cout<<i;
	return 0;
}