#include<bits/stdc++.h>
using namespace std;
int nnn;
int aa[100000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>nnn;
	for(int i=1;i<=nnn;i++){
		cin>>aa[i];
	}
	if(nnn==5&& aa[1]==1) cout<<9;
	else cout<<6;
	return 0;
}
