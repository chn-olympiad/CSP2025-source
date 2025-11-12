#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum[500010],nnow=0,cnt,ans;
long long vis[500010],vi;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nnow=(nnow^a[i]);
		sum[i]=nnow;
	}
	for(int l=0;l<=n-1;l++){
		for(int st=1;st<=(n-l);st++){
			int en=st+l;
			if(st==1){
				cnt=sum[en];
			}else{
				cnt=(sum[en]^sum[st-1]);
			}
			
			if(cnt==k){
				bool sp=1; 
				for(int i=1;i<=vi;i++){
					if(st<=vis[i] && vis[i]<=en){
						sp=0;
						break;
					}	
				}
				if(sp){
					ans++;
					vi++;
					vis[vi]=st;
					vi++;
					vis[vi]=en;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
