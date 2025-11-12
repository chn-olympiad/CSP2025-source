#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int t,n,a[N],b[N],c[N],p[N],nmax;
int d[10];
long long endans=0;
void dfs(int x){
	if(x==n+1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(p[i]==1){
				ans+=a[i];
			}else if(p[i]==2){
				ans+=b[i];
			}else if(p[i]==3){
				ans+=c[i];
			}
		}
		endans=max(endans,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(d[i]==0) continue;
		p[x]=i;
		d[i]--;
		dfs(x+1);
		d[i]++;
	}	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
	    endans=0;
    	cin>>n;
    	nmax=n/2;
    	for(int i=1;i<=3;i++) d[i]=nmax;
    	for(int i=1;i<=n;i++){
    		cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1);
		cout<<endans<<endl;
    }
    return 0;
} 
