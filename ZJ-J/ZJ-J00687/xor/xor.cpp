#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int ans;
int a[1000001];
void f(int k,int num,int cnt){
	if(k==n){
		ans=max(ans,cnt);
		return;
	}
	num=num^a[k];
	if(num==m){
		f(k+1,0,cnt+1);
	}
	f(k+1,num,cnt);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int num=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			num++;
		}
	}
	if(m==0){
		cout<<num/2<<endl;
	}
	else if(m==1){
		cout<<num<<endl;
	}
	else{
		f(0,0,0);
		cout<<ans<<endl;
	}
	
	
	return 0;
}
