#include <bits/stdc++.h>
using namespace std;
long long x;
long long fk[500005];
long long a,b;
stack<long long>st[500005];
queue<long long>stls[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(long long i = 1;i<=a;i++){
		scanf("%lld",&x);
		stls[i].push(x);
		if(x==b){
			st[i].push(1); 
		} 
		for(int j=2;j<=i;j++){
			long long pl=x^stls[i-1].front();
			stls[i].push(pl);
			if(pl==b){
				st[i].push(j);
			} 
			stls[i-1].pop();
		}
	}
	long long maxn=0;
	for(long long i = 1;i<=a;i++){
		while(!(st[i].empty())){
			fk[i]=max(fk[i],fk[i-st[i].top()]+1);
			st[i].pop();
		}
		maxn=max(maxn,fk[i]);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
