#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct jg{
	int x,c1,c2;
	bool operator <(const jg &t)const{
		return x>t.x;
	}
}a[N];
int b[4],id[4],cnt[4];
bool gz(int x,int y){
	return b[x]>b[y];
}
void solve(){
	int n,ans=0;cin>>n;
	for(int i=1;i<4;i++) cnt[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<4;j++) cin>>b[j],id[j]=j;
		sort(id+1,id+4,gz);
		ans+=b[id[2]],a[i].x=b[id[1]]-b[id[2]],a[i].c1=id[1],a[i].c2=id[2];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(cnt[a[i].c1]<n/2) ans+=a[i].x,cnt[a[i].c1]++;
		else cnt[a[i].c2]++;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
