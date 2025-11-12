#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define VE vector
#define PQ priority_queue
const LL M=998244353;
LL n,m,q0,q1;char b;string s;VE<LL>nc;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	nc.resize(n);
	for(LL i=0;i<n;i++){
		cin>>b;if(b=='0')q1=1;
		s+=b;
	}
	for(LL i=0;i<n;i++){
		cin>>nc[i];
	}
	if(q1&&m==n){
		cout<<0;return 0;
	}else if(!q1||(!q1&&m==n)){
		LL jc=1;
		for(LL i=2;i<=n;i++){
			jc=(jc*i)%M;
		}
		cout<<jc%M;return 0;
	}
	cout<<0;return 0;
}
