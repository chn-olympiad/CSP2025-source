#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
const int N=1e6+100;
struct s{
	ll a,b,c;
}a[N]; 
ll n;
ll f[N],p[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>T;
	while(T--){
		cin>>n;
		ll m=n;
		int i=0;
		while(m--){
			i++;
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		memset(f,0,sizeof(f));
		f[0]=0;
		
		for(int i=n-1;i>0;i--){
			
			for(int j=0;j<n;j++){
				
			p[j]=f[j]=max(f[j],f[j]+a[i].a);
			f[j]=max(f[j],f[j-a[i].a]+a[i].b);
		
			if(p[j]==f[j])
				f[j]=max(f[j],f[j-a[i].a]+a[i].c);
			else
				f[j]=max(f[j],f[j-a[i].b]+a[i].c);
			
			
			
			
			
		}}
		cout<<f[n-1]<<" ";
		
} }