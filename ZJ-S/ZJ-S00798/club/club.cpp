#include <bits/stdc++.h>
using namespace std;
struct no{
	int first,second,third;
}a[200010];
priority_queue<long long,vector<pair<long long,pair<long long,long long> > >,greater<pair<long long,pair<long long,long long> > > > q;
long long T,n,i,b[200010][4],f[4],ans;
bool cmp(long long q,long long h){
	return q>h;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q.empty()) q.pop();
		ans=0;
		f[1]=f[2]=f[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>b[i][1]>>b[i][2]>>b[i][3];
		for(i=1;i<=n;i++)
			if(b[i][1]!=0||b[i][3]!=0) break;
		if(i==n+1){
			long long c[100010];
			for(int i=1;i<=n;i++) c[i]=b[i][2];
			sort(c+1,c+1+n);
			long long ans=0;
			for(int i=n;i>=n/2+1;i--) ans+=c[i];
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(b[i][1]>=b[i][2]&&b[i][2]>=b[i][3]) a[i].first=1,a[i].second=2,a[i].third=3;
			else if(b[i][1]>=b[i][3]&&b[i][3]>=b[i][2]) a[i].first=1,a[i].second=3,a[i].third=2;
			else if(b[i][2]>=b[i][1]&&b[i][1]>=b[i][3]) a[i].first=2,a[i].second=1,a[i].third=3;
			else if(b[i][2]>=b[i][3]&&b[i][3]>=b[i][1]) a[i].first=2,a[i].second=3,a[i].third=1;
			else if(b[i][3]>=b[i][1]&&b[i][1]>=b[i][2]) a[i].first=3,a[i].second=1,a[i].third=2;
			else if(b[i][3]>=b[i][2]&&b[i][2]>=b[i][1]) a[i].first=3,a[i].second=2,a[i].third=1;
			f[a[i].first]++;ans+=b[i][a[i].first];
		}
		if(f[1]<=n/2&&f[2]<=n/2&&f[3]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			q.push({b[i][a[i].first]-b[i][a[i].second],{a[i].first,a[i].second}});
		while(f[1]>n/2||f[2]>n/2||f[3]>n/2){
			long long x=q.top().first,y=q.top().second.first,z=q.top().second.second;
			q.pop();
			if(f[y]>n/2&&f[z]<n/2){
				ans-=x;
				f[y]--;
				f[z]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
