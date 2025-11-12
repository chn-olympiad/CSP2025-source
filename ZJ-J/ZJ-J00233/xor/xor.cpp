#include<bits/stdc++.h>
using namespace std;
long long n,k,arr[500001],brr[500001],ans;
map <int ,int > mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		brr[i]=brr[i-1]^arr[i];
		if(mp[brr[i]^k]!=0){
			ans++;
			map <int ,int > a;
			for(int j=1;j<=i;j++){
				brr[i]=0;
			}
			mp=a;
			mp[0]=1;
		}
		else mp[brr[i]]=1;
	}
	cout<<ans;
	return 0;
}
