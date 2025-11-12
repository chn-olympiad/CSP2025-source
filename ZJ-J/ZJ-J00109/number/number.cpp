#include<bits/stdc++.h>
using namespace std;
int a[99];
string x; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	int l=x.size();
	for(int i=0;i<=l-1;i++) 
		if('0'<=x[i] && x[i]<='9')
			a[x[i]-'0']++;
//	for(int i=0;i<=9;i++) cout<<a[i]<<" ";
	for(int i=9;i>=0;i--)
		for(int j=0;j<=a[i]-1;j++)
			printf("%d",i);
	
	
	return 0;
}
