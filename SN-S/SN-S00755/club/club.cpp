#include <bits/stdc++.h>
using namespace std;
int const N=1e5+7;
int t,n,a[N][3];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	while(t--){
		int zh1[N],zh2[N],ans=0;
		cin>>n;
		int cs=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
			
		if(n<=2){
			int f1=a[1][1],f2=a[1][2],f3=a[1][3],s1=a[2][1],s2=a[2][2],s3=a[2][3];
			int m1=max(f1,f2),q1=min(f1,f2);
			m1=max(m1,f3),q1=min(q1,f3);	
			int m2=max(s1,s2),q2=min(s1,s2);
			m2=max(m2,s3),q2=min(q2,s3);		
			ans=m1+m2;
			
		}

		else{
			for(int i=1;i<=n;i++){
				zh1[i]=a[i][1];
			}
			sort(zh1+1,zh1+1+n,cmp);
			for(int i=1;i<=cs;i++)ans+=zh1[i];
		}
		cout<<ans;
	} 
	return 0;
}
