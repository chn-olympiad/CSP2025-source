#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
bool flag[505];
int cnt,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<n%998244353;
		return 0;
	}else if(m==n){
		cout<<((n*(n-1))/2)%998244353;
	}
	for(int i=0;i<n;i++){
		if(s[i]==1)flag[i]=true;
		else flag[i]=false;
	} 
	for(int i=0;i<n;i++){
		if(flag[i]==true){
			cnt++;
			if(cnt==m){
				int sum=0;
				for(int i=n;i>=m;i--){
					sum*=i;
				}
				sum/=2;
				ans=sum;
				break;
			}
		}
	}
	cout<<ans%998244353;
}