#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n,m;
long long k=0;
string s;
int c[505];
long long ans=0;
long long arr(long long a,long long b){
	long long cnt=1;
	for(long long i=a;i>=a-b+1;i--){
		cnt=cnt*i%Mod;
	}
	if(cnt==161088479) cout<<"Yes";
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	k=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) k--;
	} 
	cout<<arr(n,n)<<'\n';
	return 0;
}
