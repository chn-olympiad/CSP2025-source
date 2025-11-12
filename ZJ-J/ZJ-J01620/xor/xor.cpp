#include<bits/stdc++.h>
using namespace std;
long long n,a[500001],ans,k,x[500001],f;
void dfs(long long s,long long id){
	ans=max(ans,s);
	if(id>n)return;
	for(int i=id;i<=n;i++)
	    for(int j=i+1;j<=n;j++){
	    	long long y=a[i]^a[j];
	        if(y==k)dfs(s+1,j);
		}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>x[1];
	a[1]=x[1];
	for(int i=2;i<=n;i++){
	    cin>>x[i];
	    a[i]=x[i]^a[i-1];
	    if(x[i]!=0&&x[i]!=1)f=1;
	}
	if(f==0&&k==1||k==0){
	    if(k==1)for(int i=1;i<=n;i++)if(x[i]==1)ans++;
	    else if(k==0)
		     for(int i=1;i<=n;i++){
		     	 if(f==0&&x[i]==0)ans++;
		     	 else if(f==0&&x[i]==1)f=1;
		     	      else if(f==1&&x[i]==1)ans++,f=0;
		     }
	}
	else dfs(0,0);
	cout<<ans;
}
