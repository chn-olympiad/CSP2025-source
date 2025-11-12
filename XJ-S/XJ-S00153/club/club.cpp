#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
#define ll long long 
ll res[N];
int a[N][5];
ll cnt,f[N],s[5],as;
void dfs(int x,ll sum1){
	if(x>n){
//		cout<<"AC"<<'\n';
		res[++cnt]=sum1;
		return ;
	}
		for(int i=1;i<=n;i++){
			for(int w=1;w<=3;w++){
				if(f[i]==0&&s[w]<n/2){
					as++;
//					cout<<x<<' '<<i<<' '<<w<<' '<<s[w]<<'\n';
					sum1+=a[i][w];
					f[i]=1;
					s[w]++;
					dfs(x+1,sum1);
					sum1-=a[i][w]; 
					f[i]=0;
					s[w]--;
				}
			}
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(res,0,sizeof(res));
		for(int i=1;i<=n;i++)	f[i]=0,s[i]=0;
		ll ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0ll);
		cout<<cnt;
		for(int i=1;i<=cnt;i++){
			ans=max(ans,res[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
