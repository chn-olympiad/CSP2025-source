#include<bits/stdc++.h>
using namespace std;using ll=long long;using Pli=pair<ll,int>;
const int N=1e5+2;int n,a[N][5],cnt[5];
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _T;cin>>_T;
	while(_T--){
		cin>>n,cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];int maxn=max(max(a[i][1],a[i][2]),a[i][3]);
			for(int j=1;j<=3;j++)if(a[i][j]==maxn){cnt[j]++;break;}
		}
		ll tot=0;
		for(int i=1;i<=n;i++)tot+=max(max(a[i][1],a[i][2]),a[i][3]);
		int d=-1;
		for(int i=1;i<=3;i++)if(cnt[i]>n/2){d=i;break;}
		if(d==-1){cout<<tot<<"\n";continue;}
		vector<Pli> v;
		for(int i=1;i<=n;i++){
			int maxn=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][d]==maxn){
				int sec=0;
				for(int j=1;j<=3;j++)if(j!=d)sec=max(sec,a[i][j]);
				v.emplace_back(Pli{sec-maxn,i});
			}
		}
		sort(v.begin(),v.end());int r=v.size()-(n/2);ll add=0;
		for(int i=v.size()-1;i>=(int)v.size()-r;i--)add+=v[i].first;
		cout<<tot+add<<"\n";
	}
	return 0;
}