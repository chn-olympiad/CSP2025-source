#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define lb lower_bound
int a[500005],s[500005],b[500005];
vector<int>v[1500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%d%d",&n,&k);
	v[0].pb(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		v[s[i]].pb(i);
	}
	for(int i=0;i<=n;i++)b[i]=-1;
	for(int i=1;i<=n;i++){
		if(v[s[i]^k].size()){
			if(i>=v[s[i]^k][0]&&i<v[s[i]^k][v[s[i]^k].size()-1]){
				int t=lb(v[s[i]^k].begin(),v[s[i]^k].end(),i)-v[s[i]^k].begin();
				//if(s[v[s[i]^k][t]]^s[i]!=k)t--;
				t--;if(t<0)t=0;
				int p=v[s[i]^k][t];
				if(p<=i&&s[p]^s[i]==k)b[i]=p+1;
			}else if(i>=v[s[i]^k][v[s[i]^k].size()-1]){
				int p=v[s[i]^k][v[s[i]^k].size()-1];
				if(p<=i&&s[p]^s[i]==k)b[i]=p+1;
			}
			/*}else if(i==v[s[i]^k][0]){
				int p=v[s[i]^k][0];
				if(p<=i&&s[p]^s[i]==k)b[i]=p+1;
			}*/
		}
	}
	//printf("           %d\n",v[0][0]);
	//for(int i=1;i<=n;i++)printf("%d %d %d\n",s[i],b[i],i);
	int ans=0;
	int nw1=0,nw2=0;
	while(nw1<=n){
		nw1++;
		if(b[nw1]==-1)continue;
		if(b[nw1]<=nw2)continue;
		ans++;
		//printf("%d\n",nw1);
		nw2=nw1;
	}
	printf("%d",ans);
	return 0;
}
