//韩骁-SN-S00770-西安高新第一中学南校区
#include<iostream>
#include<algorithm> 
using namespace std;
struct road{
	long long int a,b,w;
}r[2000010];
long long int n,m,k,mp,ans;
long long int is_visit[1000010],q[2000010];
bool cmp(road a,road b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	mp=n;
	for(int long long i=1;i<=m;i++){
		cin>>r[i].a>>r[i].b>>r[i].w;
	}
	for(int i=1;i<=k;i++){
		long long int w; cin>>w;
		for(long long int i=1;i<=n;i++) cin>>q[i];
		for(long long int i=1;i<=n;i++){
			for(long long int j=1;j<=n;j++){
				if(i!=j){
					mp++;
					r[mp].a=i;
				    r[mp].b=j;
				    r[mp].w=q[i]+q[j]+w;
				}
			}
		}
	}
	sort(r+1,r+mp+1,cmp);
    for(long long int i=1;i<=n;i++) is_visit[i]=i;
    for(long long int i=1;i<=mp;i++){
    	if(is_visit[r[i].a]!=is_visit[r[i].b]){
    		for(long long int j=1;j<=n;j++){
    			if(is_visit[j]==is_visit[r[i].b]&&j!=r[i].b) is_visit[j]=is_visit[r[i].a];
			}
			is_visit[r[i].b]=is_visit[r[i].a];
    		ans+=r[i].w;
		}
	}
	cout<<ans;
	return 0;
}

