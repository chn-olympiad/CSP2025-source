#include<bits/stdc++.h>
inline int read(){
	int X=0;char ch;bool f=0;
	do{ch=getchar();f|=(ch=='-');}while(!isdigit(ch));
	do{X=(X<<1)+(X<<3)+(ch^48);}while(isdigit(ch=getchar()));
	return f?-X:X;
}
const int N=1e5;
int a[N+5][3],mxx[N+5],id[N+5],n;
std::vector<int> vec[8];
bool cmp(int x,int y){return x>y;}
void solve(){
	for(int i=0;i<8;i++) vec[i].clear();
	n=read();
	for(int i=1;i<=n;i++){
		a[i][0]=read();a[i][1]=read();a[i][2]=read();
		mxx[i]=std::max({a[i][0],a[i][1],a[i][2]});
		id[i]=((mxx[i]==a[i][0])<<2)+((mxx[i]==a[i][1])<<1)+(mxx[i]==a[i][2]);
		vec[id[i]].emplace_back(i);
	}
	int ans=0,m=n/2;
	for(int i=1;i<=n;i++) ans+=mxx[i];
	if (vec[1].size()<=m&&vec[2].size()<=m&&vec[4].size()<=m){
		printf("%d\n",ans);
		return;
	}
	for(int i=0;i<8;i++){
		if (vec[i].size()>m){
			for(int j=0;j<vec[i].size();j++){
				int k=vec[i][j];
				int mnx;
				if (i==1) mnx=std::max(a[k][0],a[k][1]);
				if (i==2) mnx=std::max(a[k][0],a[k][2]);
				if (i==4) mnx=std::max(a[k][1],a[k][2]);
				vec[i][j]=mnx-mxx[k];
			}
			sort(vec[i].begin(),vec[i].end(),cmp);
			for(int j=0;j<vec[i].size()-m;j++) ans+=vec[i][j];
			printf("%d\n",ans);
			return;
		}
	}
	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}