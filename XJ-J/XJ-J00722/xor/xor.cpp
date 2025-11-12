#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=5e5+10;
const int M=1.5e6;
int n,k;
int a[N],b[N];
int f[N];
int mp[M];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mp[0]=0;
	f[0]=0;
	for(int i=1;i<=n;i++){
		a[i]=a[i]^a[i-1];
		b[i]=a[i]^k;
	}
	for(int i=1;i<=n;i++){
		if(mp[b[i]]!=0){
			f[i]=f[mp[b[i]]]+1;
		}
		else{
			if(b[i]==0) f[i]=1;
		}
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
} 
