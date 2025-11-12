#include<bits/stdc++.h>
using namespace std;
long long t,n,ans=0;
long long a[5],f[5];
void com(long long x,long long y,long long z){
	long long b[5]={x,y,z};
	sort(b,b+3);
	if(b[2]==x&&f[1]<n/2){
		ans+=x;
		f[1]++;
	}else if(b[2]==y&&f[2]<n/2){
		ans+=y;
		f[2]++;
	}else if(b[2]==z&&f[3]<n/2){
		ans+=z;
		f[3]++;
	}else if(b[2]==x&&f[1]>=n/2){
		ans+=x-1;
		f[1]++;
	}else if(b[2]==y&&f[2]>=n/2){
		ans+=y-1;
		f[2]++;
	}else if(b[2]==z&&f[3]>=n/2){
		ans+=z-1;
		f[3]++;
	}
}
void solve(){
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>a[1];
		cin>>a[2];
		cin>>a[3];
		com(a[1],a[2],a[3]);
	}
	cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
		ans=0;
		f[1]=0;
		f[2]=0;
		f[3]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}
	return 0;
} 
