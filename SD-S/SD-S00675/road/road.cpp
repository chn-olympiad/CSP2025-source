#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],u[1000010],v[1000010],w[1000010],r[1001010];
long long sumw=0,ans=0;
int main(){
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	cin>>n>>m>>k;
	int h[10010];
	bool jing[10010];
	for(int i=1;i<=n;i++){
		h[i]=999999999;
		jing[i]=true;
	}
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		r[i]=w[i];
		h[u[i]]=min(h[u[i]],w[i]); 
		h[v[i]]=min(h[v[i]],w[i]); 
		sumw+=w[i];
	}
	if(k==0){
		sort(w+1,w+m+1);
		cout<<sumw-w[m]<<'\n';
		return 0;
	}
	int l=m,a[10010];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			l++;
			r[l]=a[j];
			h[j]=min(h[j],a[j]);
		}
	}
	sort(r+1,r+l+1);
	int t=n+k-1;
	for(int i=1;i<=t;i++){
		ans+=r[i];
	}
	for(int i=1;i<=n;i++){
		if(h[i]>r[t]){
			jing[i]=false;
		}
	}
	for(int i=1;i<=n;i++){
		if(jing[i]==false){
			ans-=r[t];
			t--;
			ans+=h[i];
		}
		if(t==0) break;
	}
	cout<<ans<<"\n";
	return 0;
}

