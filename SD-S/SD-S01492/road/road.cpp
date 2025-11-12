#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int fa[20005],isans[1000005],a[15][10005];
pair<int,pair<int,int> > bian[1000005],newbian[1000005],nnw[1000005];
int go(int x){
	if(fa[x]==x) return x;
	return fa[x]=go(fa[x]);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		bian[i].second.first=read();
		bian[i].second.second=read();
		bian[i].first=read();
	}
	int f=0; 
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=read();
		} 
		if(a[i][0]) f=1;
	}
	sort(bian+1,bian+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	int ans=0;
	for(int i=1;i<=m;i++){
		int l=bian[i].second.first;
		int r=bian[i].second.second;
		int w=bian[i].first;
		int fl=go(l),fr=go(r);
		if(fl!=fr){
			fa[fl]=fr;
			isans[i]=1;
			ans+=w;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(isans[i]) newbian[++cnt]=bian[i];
	}
	if(!f){
		int cn=cnt;
		for(int i=1;i<=cnt;i++) nnw[i]=newbian[i];
		int sum=0,jia=0;
		for(int i=1;i<=k;i++){
			jia++;
			for(int j=1;j<=n;j++){
				nnw[++cn].second.first=j;
				nnw[cn].second.second=n+jia;
				nnw[cn].first=a[i][j];
			}
		}
		for(int i=1;i<=n+jia;i++) fa[i]=i;
		sort(nnw+1,nnw+cn+1);
		for(int i=1;i<=cn;i++){
			int l=nnw[i].second.first;
			int r=nnw[i].second.second;
			int w=nnw[i].first;
//			cout<<l<<' '<<r<<' '<<w<<'\n';
			int fl=go(l),fr=go(r);
			if(fl!=fr){
				fa[fl]=fr;
				sum+=w;
			}
		}
		ans=min(ans,sum);
		cout<<ans<<'\n';
		return 0;
	}
	for(int qp=1;qp<(1<<k);qp++){
		int cn=cnt;
		for(int i=1;i<=cnt;i++) nnw[i]=newbian[i];
		int sum=0,jia=0;
		for(int i=1;i<=k;i++){
			if((qp>>(i-1))&1){
				sum+=a[i][0];
				jia++;
				for(int j=1;j<=n;j++){
					nnw[++cn].second.first=j;
					nnw[cn].second.second=n+jia;
					nnw[cn].first=a[i][j];
				}
			}
		}
		for(int i=1;i<=n+jia;i++) fa[i]=i;
		sort(nnw+1,nnw+cn+1);
		for(int i=1;i<=cn;i++){
			int l=nnw[i].second.first;
			int r=nnw[i].second.second;
			int w=nnw[i].first;
//			cout<<l<<' '<<r<<' '<<w<<'\n';
			int fl=go(l),fr=go(r);
			if(fl!=fr){
				fa[fl]=fr;
				sum+=w;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}
