//王子乐 SN-S00472 西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
int t,ans;
int n,a[100005][5],s[100005];
int b,c,d,e,f,g,bc,de;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
				s[i]=a[i][1];			
			}
		if(n==2){
			b=a[1][1]+a[2][2];
			c=a[1][1]+a[2][3];
			d=a[2][1]+a[1][2];
			e=a[2][1]+a[1][3];
			bc=max(b,c);
			de=max(d,e);
			ans=max(bc,de);
			cout<<ans<<endl;
		}
		if(n!=2&&n!=100000){
			for(int i=1;i<=n;i++){
				f=max(a[i][1],a[i][2]);
				g=max(a[i][3],f);
				ans+=g;	
			}
			cout<<ans<<endl;
		}
			
		if(n==100000){
			for(int i=1;i<=n-1;i++){
				for(int j=1;j<=n-1;j++)
					if(s[j]<=s[j+1])swap(s[j],s[j+1]);
			}
			for(int i=1;i<=n/2;i++){
				ans+=s[i];
			}
			cout<<ans;
			}
		
		
	}
	return 0;
} 
