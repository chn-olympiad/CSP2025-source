#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],ans;
long long x[100005],totx,y[100005],toty,z[100005],totz;
int cmp1(int p,int q){
	int u,v;
	u=min(a[x[p]][1]-a[x[p]][2],a[x[p]][1]-a[x[p]][3]);
	v=min(a[x[q]][1]-a[x[q]][2],a[x[q]][1]-a[x[q]][3]);
	return u>v;
}
int cmp2(int p,int q){
	int u,v;
	u=min(a[y[p]][2]-a[y[p]][1],a[y[p]][2]-a[y[p]][3]);
	v=min(a[y[q]][2]-a[y[q]][1],a[y[q]][2]-a[y[q]][3]);
	return u>v;
}
int cmp3(int p,int q){
	int u,v;
	u=min(a[z[p]][3]-a[z[p]][1],a[z[p]][3]-a[z[p]][2]);
	v=min(a[z[q]][3]-a[z[q]][1],a[z[q]][3]-a[z[q]][2]);
	return u>v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long k=n/2;
		ans=totx=toty=totz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				x[++totx]=i;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				y[++toty]=i;
			}else{
				z[++totz]=i;
			}
		}
		if(totx>k){
			sort(x+1,x+1+totx,cmp1);
			for(int i=k+1;i<=totx;i++){
				if(a[x[i]][2]>=a[x[i]][3]){
					y[++toty]=x[i];
				}else{
					z[++totz]=x[i];
				}
			}
			totx=k;
		}else if(toty>k){
			sort(y+1,y+1+toty,cmp2);
			for(int i=k+1;i<=toty;i++){
				if(a[y[i]][1]>=a[y[i]][3]){
					x[++totx]=y[i];
				}else{
					z[++totz]=y[i];
				}
			}
			toty=k;
		}else if(totz>k){
			sort(z+1,z+1+totz,cmp3);
			for(int i=k+1;i<=totz;i++){
				if(a[z[i]][1]>=a[z[i]][2]){
					x[++totx]=z[i];
				}else{
					y[++toty]=z[i];
				}
			}
			totz=k;
		}
		for(int i=1;i<=totx;i++){
			ans=ans+a[x[i]][1]; 
		}
		for(int i=1;i<=toty;i++){
			ans=ans+a[y[i]][2]; 
		}
		for(int i=1;i<=totz;i++){
			ans=ans+a[z[i]][3]; 
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
