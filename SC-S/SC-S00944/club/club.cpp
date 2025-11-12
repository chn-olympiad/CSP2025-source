#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,pair<int,int>>;
using pi=pair<int,int>;
const int N=1e5+5;
int n,m,T,cnt[3];
pair<int,int> dif[3][N];
pii a[N];
long long ans;
bool cmp(pii x,pii y){
	if(x.first==y.first){
		if(x.second.first==y.second.first)
			return x.second.second>
			y.second.second;
		return x.second.first>y.second.first;
	}
	return x.first>y.first;
}
bool cmp2(pi x,pi y){
	if(max(x.first,x.second)==
	max(y.first,y.second))
		return min(x.first,x.second)>
		min(y.first,y.second);
	return max(x.first,x.second)>
	max(y.first,y.second);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		m=n/2;
		memset(cnt,0,sizeof(cnt));
		ans=0;
		for(int i=1;i<=n;i++){
			int x,y,z; cin>>x>>y>>z;
			a[i]={x,{y,z}};
		}
		sort(a+1,a+1+n,cmp);
		int t1=0,t2=0,t3=0;
		for(int i=1;i<=n;i++){
			int x=a[i].first,
			y=a[i].second.first,
			z=a[i].second.second;
			int maxn=max(x,max(y,z));
			if(maxn==x){
				cnt[0]++;
				ans+=x;
				dif[0][++t1]={y-x,z-x};
			}
			else if(maxn==y){
				cnt[1]++;
				ans+=y;
				dif[1][++t2]={x-y,z-y};
			}
			else{
				cnt[2]++;
				ans+=z;
				dif[2][++t3]={x-z,y-z};
			}
		}
		sort(dif[0]+1,dif[0]+1+t1,cmp2);
		sort(dif[1]+1,dif[1]+1+t2,cmp2);
		sort(dif[2]+1,dif[2]+1+t3,cmp2);
		int p1=0,p2=0,p3=0;
		int f1=0,f2=0;
		while(cnt[0]>m){
			f1=1;
			cnt[0]--;
			++p1;
			if(dif[0][p1].first>
			dif[0][p1].second){
				cnt[1]++;
				ans+=dif[0][p1].first;
			}
			else{
				cnt[2]++;
				ans+=dif[0][p1].second;
			}
		}
		while(cnt[1]>m){
			f2=1;
			cnt[1]--;
			++p2;
			if(f1==0&&dif[1][p2].first>
			dif[1][p2].second){
				cnt[0]++;
				ans+=dif[1][p2].first;
			}
			else{
				cnt[2]++;
				ans+=dif[1][p2].second;
			}
		}
		while(cnt[2]>m){
			cnt[2]--;
			++p3;
			if(dif[2][p3].first>
			dif[2][p3].second){
				cnt[0]++;
				ans+=dif[2][p3].first;
			}
			else if(f2==0){
				cnt[1]++;
				ans+=dif[2][p3].second;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}