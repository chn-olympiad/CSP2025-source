#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,q;
string ls[N],rs[N],lt,rt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>ls[i]>>rs[i];
	while(q--){
		cin>>lt>>rt;
		if(lt.size()!=rt.size()) {
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			string y;
			int x=lt.find(ls[i]);
			if(x>=0){
				for(int j=0;j<x;j++){
					y+=lt[j];
				}
				for(int j=0;j<ls[i].size();j++) y+=ls[i][j];
				for(int j=ls[i].size();j<lt.size();j++) y+=lt[j];
			}
			if(y==rt) cnt++;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
/*

Ren5Jie4Di4Ling5%
*/
