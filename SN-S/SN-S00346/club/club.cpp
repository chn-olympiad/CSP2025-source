#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
	int z;
};
node a[114514];
int n,m,t,ans;
int num;
bool cmpx(node x,node y){
	return x.x>y.x;
}
bool cmpy(node x,node y){
	return x.y>y.y;
}
bool cmpz(node x,node y){
	return x.z>y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmpx);
		for(int i=1;i<=n;i++){
			if(i<=n/2) num+=a[i].x;
			else num+=max(a[i].y,a[i].z);
		}
		ans=max(ans,num);
		num=0;
		sort(a+1,a+n+1,cmpy);
		for(int i=1;i<=n;i++){
			if(i<=n/2) num+=a[i].y;
			else num+=max(a[i].x,a[i].z);
		}
		ans=max(ans,num);
		num=0;
		sort(a+1,a+n+1,cmpz);
		for(int i=1;i<=n;i++){
			if(i<=n/2) num+=a[i].z;
			else num+=max(a[i].x,a[i].y);
		}
		ans=max(ans,num);
		num=0;
		cout<<ans;
		ans=0;
	}
	return 0;
}

