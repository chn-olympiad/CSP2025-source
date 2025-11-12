#include<bits/stdc++.h>
using namespace std;
int a[100010][4];
int b[100010];
vector<int>sum[4];
int next(int x){
	if(x==1) return 2;
	if(x==2) return 3;
	if(x==3) return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		for(int i=1;i<=3;i++) sum[i].clear();
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int mx=0,mi;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>mx){
					mx=a[i][j];
					mi=j;
				}
			}
			ans+=mx; 
			sum[mi].push_back(i);
		}
		int ms=0;
		for(int i=1;i<=3;i++){
			if(sum[i].size()>n/2){
				ms=i;
			}
		}
		if(ms==0){
			cout<<ans<<endl;
			continue;
		}
		int len=sum[ms].size();
		for(int i=0;i<len;i++){
			int x=sum[ms][i];
			b[i]=min(a[x][ms]-a[x][next(ms)],a[x][ms]-a[x][next(next(ms))]);
		}
		sort(b,b+len);
		for(int i=0;i<len-(n/2);i++){
			ans-=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}


