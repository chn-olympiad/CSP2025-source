#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int t,n,ans;
struct student{
	int a1,a2,a3;
}a[100005];
int cmp(student x,student y){
	return x.a1>y.a1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].a1;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
