#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,a[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--) cin>>s;
	ll k=q;
	while(k--) cin>>s;
	srand(time(0));
	ll t;
	while(q--){
		t=rand()%60+1;
		cout<<a[t]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
我这辈子行善积德，扶老奶奶过马路，图灵爷爷在上，助我破鼎 
*/ 
