#include<bits/stdc++.h>
using  namespace std;
long long a[100010][5];
vector<long long> v[5];
int cnt[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		v[1].clear();
		v[2].clear();
		v[3].clear();
		int n;
		cin >> n;
		long long ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			//cin >>  >>  >> ;
			long long mx=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=mx;
			if(mx==a[i][1]){
				cnt[1]++;
				v[1].push_back(a[i][1]-max(a[i][2],a[i][3]));
			}else if(mx==a[i][2]){
				cnt[2]++;
				v[2].push_back(a[i][2]-max(a[i][1],a[i][3]));
			}else{
				cnt[3]++;
				v[3].push_back(a[i][3]-max(a[i][1],a[i][2]));
			}
		}
		int wwh=0;
		if((int)(v[1].size())>n/2){
			sort(v[1].begin(),v[1].end());
			wwh=(int)(v[1].size())-n/2;
			for(int i=0;i<wwh;i++)ans-=v[1][i];
		}else if((int)(v[2].size())>n/2){
			sort(v[2].begin(),v[2].end());
			wwh=(int)(v[2].size())-n/2;
			for(int i=0;i<wwh;i++)ans-=v[2][i];
		}else if((int)(v[3].size())>n/2){
			sort(v[3].begin(),v[3].end());
			wwh=(int)(v[3].size())-n/2;
			for(int i=0;i<wwh;i++)ans-=v[3][i];
		}
		cout << ans << endl;
	}
	return 0;
} 
