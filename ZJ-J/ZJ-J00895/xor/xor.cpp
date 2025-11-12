#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],num,ans,maxn,minn;
string s,as;
bool check(int x){
	int sum=0,k=0;
	for(int i=1;i<=n;i++){
		if(b[i]==m&&!k){
			sum++;
			k=1;
		}
		else if(b[i]==0&&k){
			sum++;
			k=0;
		}
	}
	return sum>=x;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1] xor a[i];
	}
	int l=0,r=1e6,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
		    r=mid-1;	
		} 
	}
	cout<<ans;
	return 0;
}//#Shang4Shan3Ruo6Shui4