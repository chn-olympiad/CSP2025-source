#include<bits/stdc++.h>
using namespace std;
struct peop{
    int a,b,c;
} us[300];
struct ch{
	int pdd,val,vc;
};
int t,n,dp[102][102][102];
void solveA(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>us[i].a>>us[i].b>>us[i].c;
    }
    for(int i=1;i<=n;i++){
        for(int ax=0;ax<=(n/2);ax++){
            for(int bx=0;bx<=(n/2);bx++){
                for(int cx=0;cx<=(n/2);cx++){
                    if((ax+bx+cx)!=i) continue;
                    if((ax-1)>=0) dp[ax][bx][cx]=max(dp[ax][bx][cx],dp[ax-1][bx][cx]+us[i].a);
                    if((bx-1)>=0) dp[ax][bx][cx]=max(dp[ax][bx][cx],dp[ax][bx-1][cx]+us[i].b);
                    if((cx-1)>=0) dp[ax][bx][cx]=max(dp[ax][bx][cx],dp[ax][bx][cx-1]+us[i].c);
                    //cout<<i<<" "<<ax<<" "<<bx<<" "<<cx<<" "<<dp[ax][bx][cx]<<endl;
                }
            }
        }
    }
    int ans=-1;
    for(int ax=0;ax<=(n/2);ax++){
        for(int bx=0;bx<=(n/2);bx++){
            for(int cx=0;cx<=(n/2);cx++){
                if((ax+bx+cx)==n) ans=max(ans,dp[ax][bx][cx]);
            }
        }
    }
    cout<<ans<<endl;
}
bool cmp(ch p,ch q){
	if(p.val==q.val) return p.vc>q.vc;
	return p.val>q.val;
}
void solveB(){
	peop u[100005];
	int pdb=0,pdc=0;
	for(int i=1;i<=n;i++){
		cin>>u[i].a>>u[i].b>>u[i].c;
		if(u[i].b!=0) pdb=1;
		if(u[i].c!=0) pdc=1;
	}
	if(pdb==0&&pdc==0){
		int psix[100005];
		for(int i=1;i<=n;i++) psix[i]=u[i].a;
		sort(psix+1,psix+1+n);
		long long ans=0;
		for(int i=n;i>(n/2);i++) ans+=psix[i];
		cout<<ans<<endl;
		return;
	}
	if(pdc==0){
		ch ux[100005];
		for(int i=1;i<=n;i++){
			if(u[i].a>u[i].b) ux[i].pdd=1;
			else if(u[i].a<u[i].b) ux[i].pdd=2;
			else ux[i].pdd=3;
			ux[i].val=max(u[i].a,u[i].b);
			ux[i].vc=ux[i].val+abs(u[i].a-u[i].b);
		}
		sort(ux+1,ux+1+n,cmp);
		long long ans=0,bf=0;
		int na=0,nb=0,rem=0;
		if(n%2==1) n--;
		for(int i=1;i<=n-rem;i++){
			if(ux[i].pdd==1){
				if((na+1)<=(n/2)){
					na++;
					ans+=ux[i].val;
				}
			}
			if(ux[i].pdd==2){
				if((nb+1)<=(n/2)){
					nb++;
					ans+=ux[i].val;
				}
			}
			if(ux[i].pdd==3){
				ans+=ux[i].val;
				rem++;
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=202){
            solveA();
        }
		else{
			solveB();
		}
    }
    return 0;
}