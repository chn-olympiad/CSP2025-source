#include<bits/stdc++.h>
using namespace std;
int T;
int n,a[100005][5],ans;
int club(int r,int f,int s1,int n2,int t3){
	if(s1>n/2||n2>n/2||t3>n/2) return 0;
	if(r==n) {
		ans=max(ans,f);
		return 0;
	}
	r+=1;
	club(r,f+a[r][1],s1+1,n2,t3);
	club(r,f+a[r][2],s1,n2+1,t3);
	club(r,f+a[r][3],s1,n2,t3+1);
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		club(0,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
		memset(a,0,sizeof(a));
	}
	return 0;
} 
