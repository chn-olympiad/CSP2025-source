#include<bits/stdc++.h>
#define NN 100005
using namespace std;
int a[NN][3];
int c[3][NN],s[3];
int qs[NN];
int ps1[]={1,0,0};
int ps2[]={2,2,1};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int T;cin>>T;
	while(T--){
		memset(qs,0,sizeof(qs));
		int n,mxx=0;cin>>n;
		for(int j=0;j<3;j++)s[j]=0;
		for(int i=1,mx,mp;i<=n;i++){
			for(int j=0;j<3;j++)cin>>a[i][j];
			mx=max({a[i][0],a[i][1],a[i][2]});
			mxx=max(mx,mxx);
			mp=(mx==a[i][0])?0:(mx==a[i][1])?1:2;
			c[mp][s[mp]++]=i;
		}
		int tx=max({s[0],s[1],s[2]});
		int tp=(tx==s[0])?0:(tx==s[1])?1:2;
		if(tx > (n/2)){
			int eps=tx-n/2;
			long long ss = 0;
			for(int i=0;i<3;i++){
				for(int ji=0;ji<s[i];ji++){
					ss+=a[c[i][ji]][i];
				}
			}
			for(int ii=0;ii<s[tp];ii++){
				int i=c[tp][ii];
				int p1=ps1[tp],p2=ps2[tp];
				qs[(min(a[i][tp]-a[i][p1],a[i][tp]-a[i][p2]))]++;
			}
			for(int i=0;i<=mxx;i++){
				if(eps>=qs[i])eps-=qs[i],ss-=i*qs[i];
				else{
					while(qs[i]--){
						ss-=i;
						eps--;
						if(eps==0)break;
					}
					break;
				}
				if(eps==0)break;
			}
			printf("%lld\n",ss);
		}
		else{
			long long ss = 0;
			for(int i=0;i<3;i++){
				for(int ji=0;ji<s[i];ji++){
					ss+=a[c[i][ji]][i];
				}
			}
			printf("%lld\n",ss);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}