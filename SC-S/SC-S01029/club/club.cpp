#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(b[i]!=0&&c[i]!=0){
				flag=false; 
			}
		}
		if(flag==true){
			sort(a+1,a+n+1);
			for(int i=n/2;i>=1;i--){
				ans+=a[i];
			}
		}
		printf("%d",ans);
	}
	return 0;
}