#include<bits/stdc++.h>;
using namespace std;
struct mn{
	long long x,y,s;
}b[2000005];
int f[20005],op[2000005];
long long n,m,k,ans,sum,mx;
set<pair<int,int>> w,q;
int fing(int jk){
	if(f[jk]==jk) return jk;
	f[jk]=fing(f[jk]);
	return f[jk];
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&b[i].x,&b[i].y,&b[i].s);
		q.insert({b[i].s,i}); 
	}
	for(auto i=q.begin();i!=q.end();i++){
		int kv=(*i).second;
		int u=b[kv].x,v=b[kv].y;
		if(fing(u)!=fing(v)){
			w.insert((*i));
			f[f[u]]=f[v];
			op[kv]=1;
			ans+=b[kv].s;
			sum++;
			if(sum==n-1){
				mx=b[kv].s;
				break;
			}
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	long long kl[15],su=m,ja=0,cv[15]={};
	for(int i=1;i<=k;i++){
		long long as=ja,us[15]={},us1[15]={},sa=0;
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		cin>>kl[i];
		as+=kl[i];
		sum=0;
		for(int j=1;j<=n;j++){
			long long s1;
			scanf("%lld",&s1);
			b[++su].x=n+i;
			b[su].y=j;
			b[su].s=s1;
			w.insert({b[su].s,su});
		}
		for(auto j=w.begin();j!=w.end();j++){
			int kv=(*j).second;
			int u=b[kv].x,v=b[kv].y;
			if(fing(u)!=fing(v)){
				f[f[u]]=f[v];
				as+=b[kv].s;
				sum++;
				if(u>n){
					us1[u-n]++;
					if(us1[u-n]==1){
						sa++;
						us[u-n]=b[kv].s;
					}
				}else if(v>n){
					us1[v-n]++;
					if(us1[v-n]==1){
						sa++;
						us[v-n]=b[kv].s;
					}
				}
				if(sum==n-1+sa){
					break;
				}
			}
		}
		for(int z=1;z<i;z++){
			if(us1[z]==1){
				as-=kl[z];
				as-=us[z];
				ja-=kl[z];
				cv[z]=0;
				for(int j=1;j<=n;j++){
					w.erase({b[m+(z-1)*n+j].s,m+(z-1)*n+j});
				}
			}
			if(us1[z]==0&&cv[z]==1){
				as-=kl[z];
				ja-=kl[z];
				cv[z]=0;
				for(int j=1;j<=n;j++){
					w.erase({b[m+(z-1)*n+j].s,m+(z-1)*n+j});
				}
			}
		}
		if(as<ans){
			ans=as;
			ja+=kl[i];
			cv[i]=1;
		}else{
			for(int j=1;j<=n;j++){
				w.erase({b[m+(i-1)*n+j].s,m+(i-1)*n+j});
			}
		}
	}
	cout<<ans;
	return 0;
} 