#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],ans;
int n,l,s1=0,s2=0,s3=0;
void dfs(int k,int sum){
	if(k==n){
		if(s1<=l&&s2<=l&&s3<=l){
			if(sum>ans){
				ans=sum;
			}
		}
		return;
	}
	if(s2<l){
		s2++;
		dfs(k+1,sum+b[k+1]);
		s2--;
	}
	if(s3<l){
		s3++;
		dfs(k+1,sum+c[k+1]);
		s3--;
	}
	if(s1<l){
		s1++;
		dfs(k+1,sum+a[k+1]);
		s1--;
	}
	
	
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		l=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		dfs(0,0);
		cout<<ans<<endl;
		for(int j=1;j<=n;j++){
			a[j]=0;
			b[j]=0;
			c[j]=0;
		}
		ans=0;
		l=0;		
	}
	fclose(stdin);
	fclose(stdout);
} 
