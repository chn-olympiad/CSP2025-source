//SN-J01014 赵子晗 西安市曲江第二中学 
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const ll N=5e5+10;

ll n,k,a[N],pre[N],ans=0;
bool ba=1,bb=1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	if(!k) ba=0;
	if(k!=0&&k!=1) bb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]^pre[i-1];
		if(a[i]!=1) ba=0;
		if(a[i]!=0&&a[i]!=1) bb=0;
	}
	if(ba){
		cout<<n/2;
		return 0;
	}
	if(bb){
		if(k==0) for(int i=1;i<=n;i++){if(a[i]==0) ans++;}
		else for(int i=1;i<=n;i++){if(a[i]==1) ans++;}
		cout<<ans;
		return 0;
	}
	
	
	return 0;
}
