#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];
bool flag=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1)flag=0;
	}
	if(flag&&(k==0||k==1)){
		int cnt=0,ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
				else if(a[i]==0){
					ans+=cnt/2+1;
					cnt=0;
				}
			}
			ans+=cnt/2;
		}
		else{
			for(int i=2;i<=n;i++){
				if(a[i]!=a[i-1]){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
