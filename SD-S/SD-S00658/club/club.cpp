#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define pii pair<int,int>
#define fr first
#define se second
using namespace std;

const int MAXN=1e5+10;

int n,v[4][MAXN],num[4],ans;
pii a[MAXN][3];

void solve(){
	memset(v,0,sizeof(v)),memset(a,0,sizeof(a)),memset(num,0,sizeof(num));ans=0;
	cin>>n;for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j].fr,a[i][j].se=j;
	for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+4);
	for(int i=1;i<=n;i++) ans+=a[i][3].fr,v[a[i][3].se][++num[a[i][3].se]]=a[i][3].fr-a[i][2].fr;
	for(int i=1;i<=3;i++) sort(v[i]+1,v[i]+num[i]+1);
	for(int i=1;i<=3;i++){
		if(num[i]>n/2){
			for(int j=1;j<=num[i]-n/2;j++) ans-=v[i][j];
			break;
		}
	}
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int t;cin>>t;while(t--) solve(); 
	return 0;
} 
