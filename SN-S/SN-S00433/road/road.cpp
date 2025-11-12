#include<bits/stdc++.h>
using namespace std;
long long t,n,sumx,sumy,sumz,sum;
struct node{
	long long x;
	long long y;
	long long z;
	bool flag;
}a[100003];
bool cmp(node xx,node yy){
	return (xx.x-xx.z)>(yy.x-yy.z);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(max(a[i].x,a[i].y)==a[i].x&&sumx<=n/2) a[i].flag=true,sumx++,sum+=a[i].x;
			else break;
		}
		for(int i=1;i<=n;i++){
			if(a[i].flag==false&&sumy<=n/2) a[i].flag=true,sumy++,sum+=a[i].y;
			else break;
		}
		cout<<sum<<endl;
	}
	return 0;
}
