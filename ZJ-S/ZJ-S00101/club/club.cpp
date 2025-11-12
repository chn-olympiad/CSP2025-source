#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long a[5];
}s[100005];
long long n,ans,q,t=-1,p[100005],f[100005];
vector<long long> e[3];
void solve(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		memset(s[i].a,0,sizeof(s[i].a));
	}
	t=-1;
	q=0;
	memset(p,0,sizeof(p));
	memset(f,0,sizeof(f));
	e[0].clear();
	e[1].clear();
	e[2].clear();
	ans=0;
	for(long long i=1;i<=n;i++){
		cin>>s[i].a[0]>>s[i].a[1]>>s[i].a[2];
		if(s[i].a[0]>=max(s[i].a[1],s[i].a[2])){
			e[0].push_back(i);
			p[i]=0;
		}else if(s[i].a[1]>=max(s[i].a[0],s[i].a[2])){
			e[1].push_back(i);
			p[i]=1;
		}else{
			e[2].push_back(i);
			p[i]=2;
		}
	}
	if(e[0].size()*2>n){
		t=0;
	}else if(e[1].size()*2>n){
		t=1;
	}else if(e[2].size()*2>n){
		t=2;
	}
	if(t!=-1){
		for(long long j=0;j<e[t].size();j++){
			long long i=e[t][j];
			q++;
			if(t==0){
				f[q]=(min(s[i].a[0]-s[i].a[1],s[i].a[0]-s[i].a[2]));
			}else if(t==1){
				f[q]=(min(s[i].a[1]-s[i].a[0],s[i].a[1]-s[i].a[2]));
			}else{
				f[q]=(min(s[i].a[2]-s[i].a[0],s[i].a[2]-s[i].a[1]));
			}
		}
	}
	sort(f+1,f+1+q);
	for(long long i=1;i<=n;i++){
		ans=ans+s[i].a[p[i]];
	}
	for(long long i=1;i<=q-n/2;i++){
		ans=ans-f[i];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
