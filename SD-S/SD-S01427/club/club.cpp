#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
	int z;
};
bool cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	node a[205],b[205],c[205];
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int flag=0,flag1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			 if(a[i].y!=0){
			 	flag=1;
			 }
			 if(a[i].z!=0){
			 	flag1=1;
			 }
		}
		if(flag==0&&flag1==0){
			sort(a+1,a+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].x;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
} 
