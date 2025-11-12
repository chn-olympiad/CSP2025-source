#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct group{
	long long f,s,t;
};
bool cmp(const group &x,const group &y){
	return x.f>y.f;
}
group a[100005];
int vis[100005][4]={},n;
int work(){
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].f>>a[i].s>>a[i].t;
		if(a[i].s>0||a[i].t>0){
			flag=1;
		}
	}
	if(flag==0){
		sort(&a[1],&a[n+1],cmp);
		long long ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].f;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n==2){
		int a1[4],a2[4];
		a1[1]=a[1].f;
		a2[1]=a[2].f;		
		a1[2]=a[1].s;
		a2[2]=a[2].s;
		a1[3]=a[1].t;
		a2[3]=a[2].t;
		long long ans=-1;
		for(int i=1;i<4;i++){
			for(int j=1;j<4;j++){
			if(i!=j&&ans<a1[i]+a2[j]){
				ans=a1[i]+a2[j];
			}
		}
		}
		cout<<ans<<endl;
		return 0;
	}
	
	
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
	cin>>t;
	while(t--)
	work();

	return 0;
}
