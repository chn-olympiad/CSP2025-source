#include<bits/stdc++.h>
using namespace std;
int val[100010][10];
int n;
long long dfs(int x,int cnta,int cntb,int cntc,long long ans){
	long long ansa=-1,ansb=-1,ansc=-1;
	if(x==n){
		if(cntb>=(n/2)&&cnta>=(n/2)){
			ansc=ans+val[x][3];
			return ansc;
		}
		if(cntc>=(n/2)&&cnta>=(n/2)){
			ansb=ans+val[x][2];
			return ansb;
		}
		if(cntb>=(n/2)&&cntc>=(n/2)){
			ansa=ans+val[x][1];
			return ansa;
		}
		if(cnta>=(n/2)){
			ansb=ans+val[x][2];
			ansc=ans+val[x][3];
			return max(ansb,ansc);
		}
		if(cntb>=(n/2)){
			ansa=ans+val[x][1];
			ansc=ans+val[x][3];
			return max(ansa,ansc);
		}
		if(cntc>=(n/2)){
			ansa=ans+val[x][1];
			ansb=ans+val[x][2];
			return max(ansa,ansb);
		}
		ansa=ans+val[x][1];
		ansb=ans+val[x][2];
		ansc=ans+val[x][3];
		return max(ansa,max(ansb,ansc));
	}
	if(cnta>=(n/2)){
		ansb=dfs(x+1,cnta,cntb+1,cntc,ans+val[x][2]);
		ansc=dfs(x+1,cnta,cntb,cntc+1,ans+val[x][3]);
		ans=max(ansb,ansc);
		return ans;
	}
	if(cntb>=(n/2)){
		ansa=dfs(x+1,cnta+1,cntb,cntc,ans+val[x][1]);
		ansc=dfs(x+1,cnta,cntb,cntc+1,ans+val[x][3]);
		ans=max(ansa,ansc);

		return ans;
	}
	if(cntc>=(n/2)){
		ansa=dfs(x+1,cnta+1,cntb,cntc,ans+val[x][1]);
		ansb=dfs(x+1,cnta,cntb+1,cntc,ans+val[x][2]);
		ans=max(ansa,ansb);
		return ans;
	}
	ansa=dfs(x+1,cnta+1,cntb,cntc,ans+val[x][1]);
	ansb=dfs(x+1,cnta,cntb+1,cntc,ans+val[x][2]);
	ansc=dfs(x+1,cnta,cntb,cntc+1,ans+val[x][3]);
	ans=max(ansa,max(ansb,ansc));
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>val[i][j];
			}
		}
		cout<<dfs(0,0,0,0,0)<<'\n';
	}
}
