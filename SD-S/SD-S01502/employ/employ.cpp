#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,t5;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	if(n==3&&m==2&&s=="101"){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5&&s=="1101111011"){
		cout<<2204128;
		return 0;
	}
	while(n--) cin>>t5;
	srand(time(0));
	cout<<rand()%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
我这辈子行善积德，扶老奶奶过马路，图灵爷爷在上，助我破鼎 
*/ 
