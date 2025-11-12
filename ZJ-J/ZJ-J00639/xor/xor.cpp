#include<bits/stdc++.h>
using namespace std;
int n,K,a[51010],s[51010],ans,cnt;
const int INF=1e9;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt=0;
			for(int k=i;k<=j;k++){
				if(a[k]==-1){
					cnt=INF;
					break;
				}
				cnt^=a[k];
			}
			if(cnt==K){
				ans++;
				for(int k=i;k<=j;k++){       
					a[k]=-1;
				}
			}	
		}
	}
	cout<<ans;
	return 0;
}
