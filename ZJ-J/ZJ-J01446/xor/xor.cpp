#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
int a[200005];
int sum[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;cin>> n >> k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	cout<<*min_element(a+1,a+1+n)<<' '<<*max_element(a+1,a+1+n)<<endl;
	if(*min_element(a+1,a+1+n)==1&&*max_element(a+1,a+1+n)==1){
		if(k==0) cout<<n/2;
		else if(k==1) cout<<n;
		return 0;
	}else if(*min_element(a+1,a+1+n)==0&&*max_element(a+1,a+1+n)==1){
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans<<endl;
			return 0;
		}else if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else if(a[i]==1&&a[i+1]==1) {
					ans++;
					a[i+1]=a[i]=-1;
				}
			}
			cout<<ans<<endl;
			return 0;
		}else return 0;
	}
	return 0;
}
/*
13 0
1 1 0 1 1 0 1 1 1 1 1 0 1
7


*/
