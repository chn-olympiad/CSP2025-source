#include<bits/stdc++.h>
using namespace std;
struct st{
	long long x,y,z;
}s[1000005],s2[200005],s3[100005];
long long n,m,tot,k,fa[200005],ans,cnt,ch[105],c[105],a[15][10005];
bool cmp(st q,st w){
	return q.z<w.z;
}
long long find(long long x){
	if(x!=fa[x]){
		return fa[x]=find(fa[x]);
	}
	return x;
}
vector<st>ss[1005];
void dfs(int x){
	if(x==k+1){
		long long p=0,sum=0;
		cnt=0;
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int i=1;i<=k;i++){
			if(ch[i]==1){
				p++;
				sum+=c[i];
				int xx;
				if(ss[i].size()>=1){
					xx=ss[i][0].x;
					long long zz=ss[i][0].z;
					sum+=zz;
				}
				for(unsigned int j=1;j<ss[i].size();j++){
					int fx=find(xx),fy=find(ss[i][j].x);
					if(fx!=fy){
						fa[fx]=fy;
						sum+=ss[i][j].z;
					}
				}
			}
		}
		for(int i=1;i<=tot;i++){
			int fx=find(s2[i].x),fy=find(s2[i].y);
			if(fx!=fy){
				fa[fx]=fy;
				sum+=s2[i].z;
				cnt++;
				if(cnt==n-1+p){
					break;
				}
			}
		}
		ans=min(ans,sum);
		return ;
	}
	ch[x]=1;
	dfs(x+1);
	ch[x]=0;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>s[i].x>>s[i].y>>s[i].z;	
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=m;i++){
		long long fx=find(s[i].x),fy=find(s[i].y);
		if(fx!=fy){
			s2[++tot]=s[i];
			s3[tot]=s2[tot];
			ans+=s[i].z;
			cnt++;
			fa[fx]=fy;
			if(cnt==n-1){
				break;
			}
		}
	}
	long long tt=0,sum=0;
	for(int i=1;i<=k;i++){
		cnt=0;
		sum+=c[i];
		tt=0;
		for(int j=1;j<=n;j++){
			tt++;
			s2[tot+tt].x=j;
			s2[tot+tt].y=1+n;
			s2[tot+tt].z=a[i][j];
		}
		sort(s2+1,s2+1+tt+tot,cmp);
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=1;j<=tot+tt;j++){
			long long fx=find(s2[j].x),fy=find(s2[j].y);
			if(fx!=fy){
				cnt++;
				if(s2[j].y==n+1){
					ss[i].push_back({s2[j].x,s2[j].y,s2[j].z});
				}
				fa[fx]=fy;
				if(cnt==n){
					break;
				}
			}
		}
		for(int j=1;j<=tot;j++){
			s2[j]=s3[j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
//chzx_lfw AKIOI!!!!!
