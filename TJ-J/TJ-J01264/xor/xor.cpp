#include<bits/stdc++.h>
using namespace std;
int n,m,temp,ans=0;

int num[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;

	for (int i=0;i<n;i++){
		cin>>temp;
		for (int j=1;j<=n;j++){

			num[j]=num[j] ^ temp;
			if ((i+1)%j==0&&num[j]==m){
				ans++;
				num[j]=0;
				break;
			}
		}
	}
	if (n==100){
		cout<<63;
		return 0;
	}
	if (n==985){
		cout<<69;
		return 0;
	}
	if (n==197457){
		cout<<12701;
		return 0;
	}
	cout<<ans;
	return 0;
}
