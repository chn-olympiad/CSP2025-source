#include<bits/stdc++.h>
using namespace std;
//�߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷� 
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIP;
const int N=1e5+10;
struct AC{
	int fir,sec,thi;
}a[N];
int n;
bool cmp(AC a,AC b){
	return a.fir>b.fir;
}
void solve(){
	cin>>n;
	memset(a,0,sizeof(a));
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].fir>>a[i].sec>>a[i].thi;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].fir;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
} 
