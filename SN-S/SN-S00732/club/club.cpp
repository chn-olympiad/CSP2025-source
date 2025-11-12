#include<bits/stdc++.h>
using namespace std;
long long T,n,a[10010010][4],ans;//屎山代码发力！！！Sunh图腾！！！
int For(int I,int sum,int A,int B,int C){
	if(I==n){
		ans=max(ans,sum);
		return 0;
	}
	for(int i=0;i<3;i++)
	{
		if(i==0&&A<n/2) For(I+1,sum+a[I][i],A+1,B,C);
		if(i==1&&B<n/2)	For(I+1,sum+a[I][i],A,B+1,C);
		if(i==2&&C<n/2)	For(I+1,sum+a[I][i],A,B,C+1);
	} 
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=0; t<T; t++) {
		cin>>n;
		ans=0;
		
		for(int i=0; i<n; i++) 
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		
		For(0,0,0,0,0);
		
		cout<<ans<<endl;		
	}
	
	return 0;
}
/*


*/
