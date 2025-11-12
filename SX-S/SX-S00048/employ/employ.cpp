#include<bits/stdc++.h>
using namespace std;
long long int a,b,c[1000000];
char d[1000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>d;
	for(int i=1;i<=a;i++)
		cin>>c[i];
	cout<<c[a];
	return 0;
}    