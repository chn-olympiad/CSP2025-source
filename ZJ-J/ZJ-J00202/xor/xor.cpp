#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500010];
map<pair<int,int>,int>qj;
bitset<500010>f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];qj[(pair<int,int>){i,i}]=a[i];
		if(a[i]==k){cnt++;f[i]=1;}
	}
	if(n<=10){
		for(register int len=2;len<=n/4+1;len++)
			for(register int i=1;i+len-1<=n;i++){
				bool _f=0;for(register int j=i;j<=i+len-1;j++)_f|=f[j];
				if(!_f){
					qj[{i,i+len-1}]=qj[{i,i+len-2}]^qj[{i+len-1,i+len-1}];
					if(qj[{i,i+len-1}]==k)
						cnt++,f[i]=1,f[i+len-1]=1;
				}
			}
		cout<<cnt;
	}
	else{
		int mlen=sqrt(n);
		for(register int len=2;len<=mlen;len++)
			for(register int i=1;i+len-1<=n;i++){
				bool _f=0;for(register int j=i;j<=i+len-1;j++)_f|=f[j];
				if(!_f){
					qj[{i,i+len-1}]=qj[{i,i+len-2}]^qj[{i+len-1,i+len-1}];
					if(qj[{i,i+len-1}]==k)
						cnt++,f[i]=1,f[i+len-1]=1;
				}
			}
		cout<<cnt;
	}
	return 0;
}

