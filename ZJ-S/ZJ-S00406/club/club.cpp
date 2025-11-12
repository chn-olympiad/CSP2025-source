#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,t,g[4][100010];
int m[4][100010],l[4],d,e,ans,f[100010];
int ch[50003];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		l[1]=0;
		l[2]=0;
		l[3]=0;
		cin>>n;
		int maxn=n/2;
		for(int i=1;i<=n;i++){
			f[i]=0;
			d=0;
			e=0;
			m[1][i]=0;
			m[2][i]=0;
			m[3][i]=0;
			for(int j=1;j<=3;j++){
				cin>>g[j][i];
				if(g[j][i]>=d){
					f[i]=d;
					d=g[j][i];
					e=j;
				}
				else if(g[j][i]>=f[i]){
					f[i]=g[j][i];
				}
			}
			if(l[e]<maxn){
				ans+=d;
				m[e][i]=d;
				l[e]++;
			}
			else if(l[e]>=maxn){
				int mm=0,nn=0;
				for(int k=1;k<=i;k++){
					if(k==i&&nn!=0){
						ans+=mm;
						m[e][i]=d;
						m[e][nn]=0;
					}
					if(k==i&&nn==0){
						ans+=f[i];
						break;
					}
					if(m[e][k]==0){
						continue;
					}
					if(d-m[e][k]+f[k]>f[i]){
						if(d-m[e][k]+f[k]>mm){
							mm=d-m[e][k]+f[k];
							nn=k;
					    }
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
