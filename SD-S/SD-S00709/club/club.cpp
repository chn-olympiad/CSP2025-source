#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],dr,lx[N],sq,del[N],sum,cnt;
vector<int>v[5],emv;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		dr=sq=cnt=sum=0;
		for(int i=1;i<=3;++i) v[i]=emv;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;++i){
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) lx[i]=1;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]) lx[i]=2;
			else lx[i]=3;
			dr+=a[i][lx[i]];
			v[lx[i]].push_back(i);
		}
		for(int i=1;i<=3;++i){
			if(v[i].size()>n/2) sq=i;
		}
		if(sq==0){
			printf("%d\n",dr);
			continue;
		}
		for(int i=1;i<=n;++i){
			if(sq!=lx[i]){
				del[i]=1e9;
				continue;
			}
			if(lx[i]==1) del[i]=a[i][1]-max(a[i][2],a[i][3]);
			else if(lx[i]==2) del[i]=a[i][2]-max(a[i][1],a[i][3]);
			else del[i]=a[i][3]-max(a[i][2],a[i][1]);
		}
		sort(del+1,del+1+n);
		for(int i=1;i<=n;++i){
			if(lx[i]!=sq) continue;
			if(v[sq].size()-(cnt++)<=n/2) break;
			sum+=del[i];
		}
		printf("%d\n",dr-sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
