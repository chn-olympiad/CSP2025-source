#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int n;
struct T{
	int x,y,z;
}a[N];

void work(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+n+1,[&](T A,T B){
		return A.x>B.x; 
	}); 
	int ans=0;
	for(int i=1;i<=n/2;i++)ans+=a[i].x;
	for(int i=n/2+1;i<=n;i++)ans+=max(a[i].y,a[i].z);
	int tmp=ans;
	for(int i=1;i+(n/2)<=n;i++){
		tmp-=a[i].x;
		tmp+=max(a[i].y,a[i].z);
		tmp-=max(a[i+n/2].y,a[i+n/2].z);
		tmp+=a[i+n/2].x;
		ans=max(ans,tmp);
	}
	int res1=ans;
	sort(a+1,a+n+1,[&](T A,T B){
		return A.y>B.y;
	});
	ans=0;
	for(int i=1;i<=n/2;i++)ans+=a[i].y;
	for(int i=n/2+1;i<=n;i++)ans+=max(a[i].x,a[i].z);
	tmp=ans;
	for(int i=1;i+(n/2)<=n;i++){
		tmp-=a[i].y;
		tmp+=max(a[i].x,a[i].z);
		tmp-=max(a[i+n/2].x,a[i+n/2].z);
		tmp+=a[i+n/2].y;
		ans=max(ans,tmp);
	}
	int res2=ans;
	sort(a+1,a+n+1,[&](T A,T B){
		return A.z>B.z;
	});
	ans=0;
	for(int i=1;i<=n/2;i++)ans+=a[i].z;
	for(int i=n/2+1;i<=n;i++)ans+=max(a[i].y,a[i].x);
	tmp=ans;
	for(int i=1;i+(n/2)<=n;i++){
		tmp-=a[i].z;
		tmp+=max(a[i].y,a[i].x);
		tmp-=max(a[i+n/2].y,a[i+n/2].x);
		tmp+=a[i+n/2].z;
		ans=max(ans,tmp);
	}
	cout<<max({res1,res2,ans})<<"\n";
} 
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;cin>>_;
	while(_--)work();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0 
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0

*/

