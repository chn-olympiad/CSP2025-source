#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long t,n,a[100003][4],c[100003],ans,maxn[100003],qm[100003],dp[100003][4];
bool fb;
void dfs(int d,int cl1,int cl2,int cl3,long long sum){
	if(d>=n){
		ans=max(ans,sum);
		return;
	}if((sum+qm[n-1]-qm[d-1])<=ans){
		return;
	}
	if(cl1<n/2){
		dfs(d+1,cl1+1,cl2,cl3,sum+a[d][0]);
	}if(cl2<n/2){
		dfs(d+1,cl1,cl2+1,cl3,sum+a[d][1]);
	}if(cl3<n/2&&!fb){
		dfs(d+1,cl1,cl2,cl3+1,sum+a[d][2]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int v=0;v<t;v++){
		cin>>n;
		bool fa=1;
		fb=1;
		ans=0;
		for(int i=0;i<n;i++){
			long long m;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				m=max(m,a[i][j]);
				if(j==2&&a[i][j]!=0){
					fb=0,fa=0;
				}
				if(j==1&&a[i][j]!=0){
					fa=0;
				}else{
					c[i]=a[i][0];
				}
			}maxn[i]=m;
		}qm[0]=maxn[0];
		for(int i=1;i<n;i++){
			qm[i]=qm[i-1]+maxn[i];
		}
		if(fa){
			sort(c,c+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=c[i];
			}cout<<ans<<endl;
			continue;
		}dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}//Ren5Jie4Di4Ling5%
