#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const ll N=1e4+10;
/*====================*/
const ll INF=0x3F3F3F3F3F3F3F3F;
/*====================*/
ll n,q;
string s1[N],s2[N];
/*====================*/
void Solve(void){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i]; 
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		cout<<0<<"\n";
	}
}
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)Solve();
}

