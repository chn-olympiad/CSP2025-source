#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
int ar[(int)1e5+3];
int br[(int)1e5+3];
int cr[(int)1e5+3];
bool zero2=1;
bool zero3=1;
void dfs(int a,int b,int c,long long score){
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	if((a+b+c)!=n){
		if(a<n/2) dfs(a+1,b,c,score+ar[a+b+c+1]);
		if(b<n/2 && !zero2) dfs(a,b+1,c,score+br[b+a+c+1]);
		if(c<n/2 && !zero3) dfs(a,b,c+1,score+cr[c+a+b+1]);
	}
	else ans=max(ans,score);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	for(int RP=0;RP<t;RP++){
		//cout<<1<<"\n";
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ar[i]>>br[i]>>cr[i];
			zero2&=(br[i]==0);
			zero3&=(cr[i]==0);
		}
		if(zero2){
			long long ans=0;
			for(int i=1;i<=n;i++) ans+=ar[i];
			cout<<ans<<"\n";
			continue;
		}
		dfs(0,0,0,0);
		cout<<ans<<"\n";
	}
}
