#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,ans;
int a[N],b[N],c[N];
int q,w,e,r;
void dfs(int x){
	if(x>n){
		ans=max(ans,r);
		return;
	}
	if(q<n/2){
		q++;
		r+=a[x];
		dfs(x+1);
		q--;
		r-=a[x];
	}
	if(w<n/2){
		w++;
		r+=b[x];
		dfs(x+1);
		w--;
		r-=b[x];
	}
	if(e<n/2){
		e++;
		r+=c[x];
		dfs(x+1);
		e--;
		r-=c[x];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool o=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)o=1;
		}
		q=w=e=r=ans=0;
		if(o==0){
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1);
		cout<<ans<<endl;
		
	}
	
	return 0;
}
