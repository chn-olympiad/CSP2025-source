#include<bits/stdc++.h>
using namespace std;
int s1,s2,s3;
int n,a[100005][4];
int ans=-1;
struct T{
	int p,q,c;
}b[100005];
void dfs(int x,int sum){
	if(x==n+1){
		ans=max(sum,ans);
		return;
	}
	if(s1>n/2||s2>n/2||s3>n/2)return;
	if(s1<n/2){
	s1++;dfs(x+1,a[x][1]+sum);	s1--;
	}
	if(s2<n/2){
	s2++;dfs(x+1,a[x][2]+sum);	s2--;
	}
	if(s3<n/2){
	s3++;dfs(x+1,a[x][3]+sum);s3--;	
	}
	return;
}
bool cmp(T x,T y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){s1=s2=s3=0;ans=-1;
	cin>>n;
	if(n<=30){
		for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		 }
		 dfs(1,0);
		 cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>b[i].p>>b[i].q>>b[i].c;
				b[i].c=b[i].p-b[i].q;
			}
			sort(b+1,b+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n;i++){
				if(i<=n/2)sum+=b[i].p;
				else sum+=b[i].q;
			}
			cout<<sum<<endl;
		}
		
	} 
	return 0;   
} 





