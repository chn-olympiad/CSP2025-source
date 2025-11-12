#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e4+10;
int T,n,ans,f[N];
struct Node{
	int id;
	int v[4];
}a[N],b[N];
int sum[4];
priority_queue<pair<int,int> > q1,q2;
bool cmp(Node x,Node y){
	return x.v[3]>y.v[3];
}
int aans=0;
void bfs(int id,int cnt1,int cnt2,int cnt3,int x){
	aans=max(aans,x);
	if(id==n+1) return;
	if(cnt1<n/2){
		bfs(id+1,cnt1+1,cnt2,cnt3,x+a[id].v[1]);
	} 
	if(cnt2<n/2){
		bfs(id+1,cnt1,cnt2+1,cnt3,x+a[id].v[2]);
	} 
	if(cnt3<n/2){
		bfs(id+1,cnt1,cnt2,cnt3+1,x+a[id].v[3]);
	} 
}
void solve(){
 	bfs(1,0,0,0,0);
 	cout<<aans+ans<<"\n";
 	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		aans=0;
		ans=0;
		int xx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			f[i]=0;
			int minn=INT_MAX;
			for(int j=1;j<=3;j++){
				cin>>a[i].v[j];
				minn=min(minn,a[i].v[j]);
				
				sum[j]=0;
			} a[i].id=i;
			ans+=minn;
			for(int j=1;j<=3;j++){
				a[i].v[j]-=minn;
				b[i].v[j]=a[i].v[j];
			} 
			b[i].id=i;
			minn=min(b[i].v[1],b[i].v[2]);
			xx+=minn;
			ans+=minn;
			b[i].v[1]-=minn;
			b[i].v[2]-=minn;
			a[i].v[0]=minn;
			q1.push({b[i].v[1],b[i].id});
			q2.push({b[i].v[2],b[i].id}); 
		}
		if(n<=10){
			ans-=xx;
			solve();
			continue;
		}
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n/2;i++){
			if(q1.top().first==0) break;
			cnt1++;
			ans+=q1.top().first;
			f[q1.top().second]=1;
			q1.pop();
		}
		for(int i=1;i<=n/2;i++){
			if(q2.top().first==0) break;
			cnt2++;
			ans+=q2.top().first;
			f[q2.top().second]=2;
			q2.pop();
		}
		sort(a+1,a+1+n,cmp);
		int sum3=0;
		for(int i=1;i<=n;i++){
			if(f[a[i].id]==0&&a[i].v[0]<a[i].v[3]&&sum3<n/2){
				ans=ans-min(a[i].v[1],a[i].v[2])+a[i].v[3];
				f[a[i].id]=3;
				sum3++;
			}
			if(f[a[i].id]!=0&&a[i].v[f[a[i].id]]<a[i].v[3]&&sum3<n/2){
				ans=ans-a[i].v[f[a[i].id]]+a[i].v[3];
				if(f[a[i].id]==1) cnt1--;
				if(f[a[i].id]==2) cnt2--;			
				f[a[i].id]=3;
				sum3++;
			}
			if(f[a[i].id]==0){
				if(a[i].v[1]>a[i].v[2]) f[a[i].id]=1,cnt1++;
				else if(a[i].v[1]<a[i].v[2]) f[a[i].id]=2,cnt2++;
			}
		}
		for(int i=1;i<=n;i++){
			if(f[a[i].id]==1&&cnt2<n/2&&a[i].v[1]<a[i].v[2]){
				ans=ans+a[i].v[2]-a[i].v[1];
				cnt2++,cnt1--;
			}
			else if(f[a[i].id]==2&&cnt1<n/2&&a[i].v[2]<a[i].v[1]){
				ans=ans+a[i].v[1]-a[i].v[2];
				cnt2--,cnt1++;
			}
		}
		cout<<ans<<"\n";
	}
} 
