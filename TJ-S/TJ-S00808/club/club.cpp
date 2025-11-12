#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;scanf("%d",&n);
		int a1a,b1b,c1c;
		for(int j=0;j<n;j++){
			scanf("%d%d%d",&a1a,&b1b,&c1c);
			a[j]=a1a;
		}sort(a,a+n);
		int ans=0;
		for(int j=0;j<n/2;j++){
			ans+=a[j];
		}printf("%d",ans);
	}
	return 0;
} 
