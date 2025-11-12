#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,t;
int a[100001][3];
int maxx=-16,maxx2=-16;
int num1,num2,num3;
int ans;
int main(){//signed
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxx=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxx==a[i][1]){
				num1++;
				if(num2>=(n/2)){
					num1--;
				} 
			}
			else if(maxx==a[i][2]){
				num2++;
				if(num2>=(n/2)){
					num2--;
				}
			}  
			else if(maxx==a[i][3]){
				num3++;
				if(num3>=(n/2)){
					num3--;
				}
			}
			ans+=maxx;
		}
		cout<<ans<<'\n';
	}
	return 0;
}