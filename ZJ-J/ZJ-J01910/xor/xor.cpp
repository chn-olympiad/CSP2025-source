#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500050];
bool pd(int l,int r){
	
	if(l==r){
		if(a[l]==k){
			//cout<<"YES";
			return 1;
		}
		else return 0;
	}
	int sum=a[l];
	for(int j=l+1;j<=r;j++){
		sum^=a[j];
	}
	
	
	if(sum==k){
		//if(l==2&&r==4)cout<<"oh"<<endl;
		return 1;
	}
	else return 0;
}
long long ans=0;
int l,r;
void dg(int deep,long long sum){
	if(deep>n){
		ans=max(ans,sum);
		//cout<<l<<" "<<r<<endl;
		return ;
	}
	for(int i=deep;i<=n;i++){
		if(pd(deep,i)){
			//l=deep+1;r=i;
			dg(i+1,sum+1);
		}
	}
	dg(deep+1,sum);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dg(1,0);
	cout<<ans;
	return 0;
}
