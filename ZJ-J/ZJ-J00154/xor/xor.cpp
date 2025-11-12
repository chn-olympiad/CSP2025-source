#include<bits/stdc++.h>//real AC!!!!!
#define int long long
#define INF 1145141919810
using namespace std;
int n,k,a[620001],xr[620001];
int ans,lst,now;
int f[1200001],used[620001],cnt;
int p(int x){
	if(x<0)return 0;
	else return xr[x];
}
int gtt(int l,int r){
	return (p(r)^p(l-1));
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],xr[i]=(xr[i-1]^a[i]);
	f[0]=1;
	for(int i=1;i<=n;i++){
		now^=a[i];
		int nd=(k^now);
		if(f[nd]){
			for(int i=1;i<=cnt;i++)
				f[used[i]]=0;
			cnt=0;
			now=0;
			ans++;
			f[0]=1;
		}
		else{
			f[now]++;
			used[++cnt]=now;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
