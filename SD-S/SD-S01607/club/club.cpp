#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,a[100005][3],v[100005],minn[100005];
int read(){
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return f*sum;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read(); 
	while(t--){
		int n,tot[4]={0,0,0,0},f=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			::minn[i]=1e18;
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			int maxn=max(max(a[i][1],a[i][2]),a[i][3]),cnt=0,vis[4],minn=1e18;
			if(a[i][1]==maxn)vis[++cnt]=1;
			if(a[i][2]==maxn)vis[++cnt]=2;
			if(a[i][3]==maxn)vis[++cnt]=3;
			for(int j=1;j<=cnt;j++){
				if(tot[vis[j]]<=minn){
					v[i]=vis[j];
					minn=tot[vis[j]];
				}
			}
			tot[v[i]]++;
			sum+=maxn;
		}
		if(tot[1]>n/2)f=1;
		if(tot[2]>n/2)f=2;
		if(tot[3]>n/2)f=3;
		if(!f){
			cout<<sum<<'\n';
			continue; 
		}
		else{
			for(int i=1;i<=n;i++){
				if(v[i]!=f)continue;
				for(int j=1;j<=3;j++){
					if(j==f)continue;
					minn[i]=min(minn[i],a[i][f]-a[i][j]);
				}
			}
			sort(minn+1,minn+n+1);
			for(int i=1;i<=tot[f]-n/2;i++)sum-=minn[i];
			cout<<sum<<'\n';
		}
	}
} 
