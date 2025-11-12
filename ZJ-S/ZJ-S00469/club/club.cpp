#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct node{
	int x,y,z,id,o;
}a[N],tmp1[N],tmp2[N];
bool cmp1(node &a,node &b){
	return a.x-a.y<b.x-b.y;
}
bool cmp2(node &a,node &b){
	return a.x-a.z<b.x-b.z;
}
int ans,cnt[4];
bitset <N> vis;
void solve(){
	cin>>n;
	vis.reset();
	ans=cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].o=i;
		if(a[i].x>=a[i].y && a[i].x>=a[i].z){
			a[i].id=1;
			cnt[1]++;
		}
		else if(a[i].y>a[i].x && a[i].y>=a[i].z){
			a[i].id=2;
			cnt[2]++;
		}
		else{
			a[i].id=3;
			cnt[3]++;
		}
		ans+=max(a[i].x,max(a[i].y,a[i].z));
	}
	if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2) return cout<<ans<<"\n",void();
	if(cnt[2]>n/2){
		swap(cnt[1],cnt[2]);
		for(int i=1;i<=n;i++) swap(a[i].x,a[i].y);
	}
	else if(cnt[3]>n/2){
		swap(cnt[1],cnt[3]);
		for(int i=1;i<=n;i++) swap(a[i].x,a[i].z);
	}
	for(int i=1;i<=n;i++) if(a[i].x<a[i].y || a[i].x<a[i].z) vis[a[i].o]=1;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) tmp1[i]=a[i];
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++) tmp2[i]=a[i];
	int i=1,j=1;
//	cout<<cnt[1]<<" ";
	for(;cnt[1]>n/2;){
		while(vis[tmp1[i].o]) i++;
		while(vis[tmp2[j].o]) j++;
		if(cnt[2]>=n/2) ans-=tmp2[j].x-tmp2[j].z,vis[tmp2[j].o]=1,cnt[3]++;
		else if(cnt[3]>=n/2) ans-=tmp1[i].x-tmp1[i].y,vis[tmp1[i].o]=1,cnt[2]++;
		else if(tmp1[i].x-tmp1[i].y<=tmp2[j].x-tmp2[j].z) ans-=tmp1[i].x-tmp1[i].y,vis[tmp1[i].o]=1,cnt[2]++;
		else ans-=tmp2[j].x-tmp2[j].z,vis[tmp2[j].o]=1,cnt[3]++;
		cnt[1]--;
	}
	cout<<ans<<"\n";
}
int T;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T--;solve());
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
//Ren5Jie4Di4Ling5%
