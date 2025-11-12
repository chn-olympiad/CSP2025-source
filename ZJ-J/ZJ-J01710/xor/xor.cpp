#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
		}cout<<cnt;
	}else{
		int cnt=0;
		for(int i=2;i<=n;i++){
//			cout<<a[i-1]<<' '<<a[i];
			if(a[i-1]==1&&a[i]==1){
				cnt++;
				i++;
			}
			else if(a[i]==0)cnt++;
		}cout<<cnt;
	}
	return 0;
}