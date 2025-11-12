#include<bits/stdc++.h>
//priority_queue
//unsigned
//cout.flush()
//sync_with_stdio
//long long,file,momrey
using namespace std;
//road
struct z{
	long long u,v,w,id;
};
vector<z>b;
int c[20];
bool cmp(z a,z b){
	return a.w<b.w;
}
long long ans;
int n,m,k;
int f[100005];
int find(int i){
	if(f[i]==i){
		return i;
	}
	return f[i]=find(f[i]);
}
void init(){
	for(int i=0;i<=n;i++){
		f[i]=i;
	}
}
bool ma(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return 0;
	}
	f[x]=y;
	return 1;
}
void kl(int l){
//	cout<<"__"<<l<<"__\n";
	long long cnt=0;
	init();
	for(int i=0;i<m;i++){
		if(((l>>b[i].id)&1)==0){
			continue;
		}
		if(ma(b[i].u,b[i].v)){
			cnt+=b[i].w;
//			cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<" "<<b[i].id<<" "<<((l>>b[i].id)&1)<<"\n";
		}
	}
//	cout<<"_____\n";
	for(int i=1;i<=k;i++){
		if((l>>i)&1){
			cnt+=c[i];
//			cout<<i<<" "<<c[i]<<"\n";
		}
	}
	ans=min(ans,cnt);
//	cout<<"______\n"<<cnt<<" "<<ans<<"\n______\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		b.push_back({u,v,w,0});
	}
	int n1=n;
	for(int i=1;i<=k;i++){
		long long ci;
		cin>>ci;
		n++;
		if(ci!=0){
			c[i]=ci;
		}else{
			i--;
			k--;
		}
		for(int j=1;j<=n1;j++){
			long long aj;
			cin>>aj;
			if(ci==0){
				b.push_back({n,j,aj,0});
			}else{
				b.push_back({n,j,aj,i});
			}
			m++;
		}
	}
	ans=1e18;
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<(1<<k);i++){
		kl((i<<1)|1);
	}
	cout<<ans;
}

