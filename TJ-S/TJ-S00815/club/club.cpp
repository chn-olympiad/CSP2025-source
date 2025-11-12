#include<bits/stdc++.h>
using namespace std;
struct str{
	int x,a1,a2,a3;
	
};
str a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans,s1,s2,s3,x;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(max(max(a[i].a1,a[i].a2),a[i].a3)==a[i].a1) a[i].x=1;
			else if(max(max(a[i].a1,a[i].a2),a[i].a3)==a[i].a2) a[i].x=2 ;
			else a[i].x=3;
			if(a[i].x==1) ans+=a[i].a1;
			else if(a[i].x==2) ans+=a[i].a2;
			else ans+=a[i].a3;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
