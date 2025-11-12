//rp++
//love CCF
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,bel[N],cnt[N];
long long sum;
struct _{int x,y,z;}a[N];
bool cmp1(_ u,_ v){return u.x-max(u.y,u.z)<v.x-max(v.y,v.z);}
bool cmp2(_ u,_ v){return u.y-max(u.x,u.z)<v.y-max(v.x,v.z);}
bool cmp3(_ u,_ v){return u.z-max(u.x,u.y)<v.z-max(v.x,v.y);}
int solve(){
	sum=cnt[0]=cnt[1]=cnt[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x>=max(a[i].y,a[i].z)){
			bel[i]=0,cnt[0]++;
			sum+=a[i].x;
		}
		else if(a[i].y>=max(a[i].x,a[i].z)){
			bel[i]=1,cnt[1]++;
			sum+=a[i].y;
		}
		else if(a[i].z>=max(a[i].x,a[i].y)){
			bel[i]=2,cnt[2]++;
			sum+=a[i].z;
		}
	}
	vector<_> v;
	if(cnt[0]>n/2){
		for(int i=1;i<=n;i++) if(bel[i]==0) v.push_back(a[i]);
		sort(v.begin(),v.end(),cmp1);
		int i=0;
		while(cnt[0]>n/2){
			cnt[0]--;
			sum-=v[i].x-max(v[i].y,v[i].z);
			i++;
		}
	}
	else if(cnt[1]>n/2){
		for(int i=1;i<=n;i++) if(bel[i]==1) v.push_back(a[i]);
		sort(v.begin(),v.end(),cmp2);
		int i=0;
		while(cnt[1]>n/2){
			cnt[1]--;
			sum-=v[i].y-max(v[i].x,v[i].z);
			i++;
		}		
	}
	else if(cnt[2]>n/2){
		for(int i=1;i<=n;i++) if(bel[i]==2) v.push_back(a[i]);
		sort(v.begin(),v.end(),cmp3);
		int i=0;
		while(cnt[2]>n/2){
			cnt[2]--;
			sum-=v[i].z-max(v[i].x,v[i].y);
			i++;
		}			
	}
	cout<<sum<<'\n';
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
