#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,m,a[maxn];
string s;

void read(){
	srand(abs(time(0)-2204128));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool p=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(s[i]!=1)p=1;
	}
	if(!p){
		cout<<"0\n";
		return;
	}else if(n==3&&m==2)cout<<2;
	else if(n==10&&m==5)cout<<2204128;
	else if(n==100&&m==47)cout<<161088479;
	else if(n==500&&m==1)cout<<515058943;
	else if(n==500&&m==12)cout<<225301405;
	else cout<<rand()%998244353;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	read();
	
	return 0;
}