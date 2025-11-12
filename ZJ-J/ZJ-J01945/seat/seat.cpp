#include<bits/stdc++.h>
using namespace std;
int s[114],r,n,m;
bool csp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	s[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
	}
	sort(s+1,s+n*m+1,csp);
	int lie=1,hang=1,up=1;
	for(int i=1;i<=n*m;i++){
		if(r==s[i]){
			cout<<lie<<' '<<hang;
			return 0;
		}
		hang+=up;
		if(hang==0||hang>n){
			lie++;
			hang-=up;
			up=-up;
		}
	}
	return 0;
}
