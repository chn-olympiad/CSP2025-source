#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans,f1,f2;
int a[N],b[N],c[N];
void dfs(int num,int c1,int c2,int c3,int step){
	if(step==n+1){
		ans=max(ans,num);
		return;
	}
	if(c1<n/2) dfs(num+a[step],c1+1,c2,c3,step+1);
	if(c2<n/2) dfs(num+b[step],c1,c2+1,c3,step+1);
	if(c3<n/2) dfs(num+c[step],c1,c2,c3+1,step+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,f1=1,f2=1;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			if(b[i]!=0) f1=0;
			if(c[i]!=0) f2=0;
		}
		if(f1&&f2){
			int num=0;
			for(int i=1;i<=n;i++) num+=a[i];
			num/=n;
			for(int i=1;i<=n;i++){
				if(a[i]>num) ans+=a[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(f2){
			int n1=0,n2=0;
			int s1=0,s2=0;
			for(int i=1;i<=n;i++) n1+=a[i],n2+=b[i];
			n1/=n,n2/=n;
			for(int i=1;i<=n;i++){
				if(a[i]>n1) s1+=a[i],s2+=b[i];
				if(a[i]<n1) s1+=b[i],s2+=a[i];
			}
			cout<<max(s1,s2)<<"\n";
			continue;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<"\n";
	}
	return 0;
}