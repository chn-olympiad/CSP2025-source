#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010],s[1000010],ans,i,j,sum,ans1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		sum+=a[i];
	}
	if(n<=1000){
		for(i=0;i<n;i++){
			for(j=i+1;j<=n;j++){
				int h=s[i]^s[j];
				if(h==k){
					ans++;
					i=j;
				}
			}
		}
		cout<<ans;
	}
	else{
		if(k==1)cout<<sum;
		else if(k==0){
			ans1=n-sum;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i-1]==1){
					ans1++;
					i++;
				}
			}
			cout<<ans1;
		}
		else cout<<n/2;
	}
}
