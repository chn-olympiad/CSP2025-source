#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<array>
using namespace std;
int t,n;
array<int,3> a[100001];
int cnt[3];
long long ans=0;
pair<int,int> x[3];
bool cmp(array<int,3> aa,array<int,3> bb){
	return aa[2]>bb[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;++i){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
//			cin>>a[i][0]>>a[i][1]>>a[i][2];
			x[0]={a1,0},x[1]={a2,1},x[2]={a3,2};
			sort(x,x+3);
			a[i][0]=x[2].second;
			a[i][1]=x[1].second;
			a[i][2]=x[2].first-x[1].first;
			ans+=x[2].first;
		}
		cnt[0]=cnt[1]=cnt[2]=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i){
			if(cnt[a[i][0]]<n/2){
				cnt[a[i][0]]++;
			}
			else{
				cnt[a[i][1]]++;
				ans-=a[i][2];				
			}
		}
		cout<<ans<<'\n';
	}
//	fflush(stdout);
	return 0;
}
