#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+100,M=1e6+1e5;
ll n,k,a[N],f[N],p[M],ans[N],sum;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
//		cout<<f[i]<<' ';
	}
//	cout<<endl;
	memset(ans,-1,sizeof (ans));
//	for (int i=0;i<=M;i++) if (!p[i]) p[i];
	for (int i=1;i<=n;i++){
		int m=f[i]^k;
//		cout<<()a[i]^k
	 	if(m==0) {
	 		ans[i]=1;
		 }
		if ((a[i]^k)==0){
			ans[i]=1;
			ans[i]=max(ans[i],ans[i-1]+1);
		}	
		ans[i]=max(max(ans[i],ans[i-1]),ans[p[m]]+1);
		sum=max(sum,ans[i]);
//		cout<<ans[i]<<' '<<ans[p[m]]<<' '<<m<<endl;
		p[f[i]]=i;
	}
	cout<<sum;
}
