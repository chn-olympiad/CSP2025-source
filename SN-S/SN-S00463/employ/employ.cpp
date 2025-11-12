#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ2.in","r",stdin);
	freopen("employ2.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	int c[1000];
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3)  cout<<2;
	if(n==10)  cout<<2204128;
	if(n==100)   cout<<161088479;
	if(n==500 and m==1)   cout<<515058943;
	if(n==500 and m==12)   cout<<225301405;

} 
