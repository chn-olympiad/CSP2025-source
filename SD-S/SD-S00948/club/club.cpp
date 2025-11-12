#include <bits/stdc++.h>
using namespace std;
int t,n,p[10],s1[200010],s2[200010],s3[200010],ans; 
struct node{
	int x,y,z,xi,yi,zi,first,second,third;
}a[200010];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flag1=0,flag2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].first=max(max(a[i].x,a[i].y),a[i].z);
			a[i].second=max(min(a[i].x,a[i].y),a[i].z);
			a[i].third=min(min(a[i].x,a[i].y),a[i].z);
			a[i].xi=1,a[i].yi=2,a[i].zi=3;
			if(a[i].y!=0&&a[i].z!=0){
				flag1=1;
			}
		}
		if(n==2){
			cout<<max(a[1].first+a[2].second,a[1].second+a[2].first);
			return 0;
		}
		if(flag1==0){
			sort(a+1,a+n+1,cmp);
			cout<<a[1].x+a[2].x<<'\n';
			return 0;
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].first;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
