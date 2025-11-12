#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,ans,n,d[10];
bool b;
struct ST{
	ll x,y,z;
}a[100005]; 
bool cmp(ST l,ST r){
	return l.x>r.x;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0 && a[i].z!=0){
				b=1;
			}
		}
		if(b==0){
			sort(a+1,a+n+1,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	
	
	
	return 0;
} 