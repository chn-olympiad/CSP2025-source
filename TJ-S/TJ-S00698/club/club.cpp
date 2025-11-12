#include<bits/stdc++.h>
using namespace std;
long long t,n,m,mr[5],ans,s[100005][5],uesd[100005],a[100005],b[100005],c[100005],fac,fab,fbc,fc,fb,fa;
void dfs(int c,long long sum){
	if(c>n){
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(mr[i]<m){
			mr[i]++;
			dfs(c+1,sum+s[c][i]);
			mr[i]--;
		}
	}
}
void dfsab(int c,long long sum){
	if(c>n){
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=2;i++){
		if(mr[i]<m){
			mr[i]++;
			dfs(c+1,sum+s[c][i]);
			mr[i]--;
		}
	}
}
void dfsac(int c,long long sum){
	if(c>n){
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i+=2){
		if(mr[i]<m){
			mr[i]++;
			dfs(c+1,sum+s[c][i]);
			mr[i]--;
		}
	}
}
void dfsbc(int c,long long sum){
	if(c>n){
		ans=max(sum,ans);
		return;
	}
	for(int i=2;i<=3;i++){
		if(mr[i]<m){
			mr[i]++;
			dfs(c+1,sum+s[c][i]);
			mr[i]--;
		}
	}
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		ans=0;
		fab=0;
		fbc=0;
		fc=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>s[i][j];
			}
			a[i]=s[i][1];
			b[i]=s[i][2];
			c[i]=s[i][3];
			if(s[i][3]!=0){
				if(s[i][2]!=0){
					fbc=1;
				}
				if(s[i][1]!=0){
					fac=1;
				}
				fc=1;
			}
			if(s[i][2]!=0){
				if(s[i][1]!=0){
					fab=1;
				}
				fb=1;
			}
			if(s[i][1]!=0){
				fa=1;
			}
		}
		if(!fc){
			dfsab(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(!fb){
			dfsac(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(!fa){
			dfsbc(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(!fbc){
			sort(a,a+n+1,cmp);
			for(int i=1;i<=m;i++){
				ans+=a[i];
				cout<<ans<<endl;
				continue;
			}
		}
		if(!fac){
			sort(b,b+n+1,cmp);
			for(int i=1;i<=m;i++){
				ans+=b[i];
				cout<<ans<<endl;
				continue;
			}
		}
		if(!fab){
			sort(c,c+n+1,cmp);
			for(int i=1;i<=m;i++){
				ans+=c[i];
				cout<<ans<<endl;
				continue;
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}	
	return 0;
}
