#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;
int read(){
	int sum=0,fg=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') fg=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*fg;
}

bool valid[N][4];//ÊÇ·ñÄÜ½»»»
int n,a[N][4],b[N],cnt[4];

struct node{
	int dat,pos,id;
	node(int d,int p,int i){
		dat=d,pos=p,id=i;
	}
	bool operator<(const node &o) const{
		return dat<o.dat;
	}
};

void init(){
	memset(valid,true,sizeof(valid));
	memset(cnt,0,sizeof(cnt));
	n=read();
	for(int i=1;i<=n;++i){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			cnt[b[i]=1]++;
			valid[i][1]=false;
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			cnt[b[i]=2]++;
			valid[i][2]=false;
		}
		else{
			cnt[b[i]=3]++;
			valid[i][3]=false;
		}
	}
}

void solve(){
	vector<node> ex;
	ex.clear();
	if(cnt[1]>n/2){
		for(int i=1;i<=n;++i){
			if(b[i]^1) continue;
			if(a[i][2]>a[i][3]&&valid[i][2]) ex.push_back(node(a[i][1]-a[i][2],i,2));
			else ex.push_back(node(a[i][1]-a[i][3],i,3));
		}
		sort(ex.begin(),ex.end());
		auto it=ex.begin();
		while(cnt[1]>n/2){
			int pos=it->pos,id=it->id;
			valid[pos][id]=false;
			cnt[1]--;
			cnt[b[pos]=id]++;
			it++;
		}
	}
	ex.clear();
	if(cnt[2]>n/2){
		for(int i=1;i<=n;++i){
			if(b[i]^2) continue;
			if(a[i][1]>a[i][3]&&valid[i][1]) ex.push_back(node(a[i][2]-a[i][1],i,1));
			else ex.push_back(node(a[i][2]-a[i][3],i,3));
		}
		sort(ex.begin(),ex.end());
		auto it=ex.begin();
		while(cnt[2]>n/2){
			int pos=it->pos,id=it->id;
			valid[pos][id]=false;
			cnt[2]--;
			cnt[b[pos]=id]++;
			it++;
		}
	}
	ex.clear();
	if(cnt[3]>n/2){
		for(int i=1;i<=n;++i){
			if(b[i]^3) continue;
			if(a[i][1]>a[i][2]&&valid[i][1]) ex.push_back(node(a[i][3]-a[i][1],i,1));
			else ex.push_back(node(a[i][3]-a[i][2],i,2));
		}
		sort(ex.begin(),ex.end());
		auto it=ex.begin();
		while(cnt[3]>n/2){
			int pos=it->pos,id=it->id;
			valid[pos][id]=false;
			cnt[3]--;
			cnt[b[pos]=id]++;
			it++;
		}
	}
	int res=0;
	for(int i=1;i<=n;++i) res+=a[i][b[i]];
	cout<<res<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		init();
		solve();
	}
	return 0;
}


