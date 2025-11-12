#include<bits/stdc++.h>
using namespace std;
int ai[10005],bi[10005],ci[10005];
int aj,bj,cj;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t; 
	for(int i = 1;i<=t;i++){
		cin>>n;
		for(int j = 1;j<=n;j++){
			cin>>ai[j]>>bi[j]>>ci[j];
			aj += ai[j];
			bj += bi[j];
			cj += ci[j];
		}
		
		cout<<(aj+bj+cj)/3;
	}
	return 0;
}
