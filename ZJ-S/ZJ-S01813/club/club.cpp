#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],ANS;
void dfs(int ans,int A,int B,int C,int num){
	if(num>n){
		ANS=max(ANS,ans);
		return ;
	}
	if(A<n/2)dfs(ans+a[num],A+1,B,C,num+1);
	if(B<n/2)dfs(ans+b[num],A,B+1,C,num+1);
	if(C<n/2)dfs(ans+c[num],A,B,C+1,num+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ANS=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(0,0,0,0,1);
		cout<<ANS<<endl;
	}
	return 0;
}
