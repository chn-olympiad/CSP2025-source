#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int ans=0,num;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n;
		long long a[n][3];
		for(int j=0;j<n;j++){
			for(int p=0;p<3;p++){
				cin>>a[j][p];
			}
		}
		for(int j=0;j<n;j++){
			
			num=a[j][0];
			for(int p=0;p<3;p++){
				if(a[j][i]>num){
					num=a[j][i];
				}
				
			}
			ans+=num;
		}
		cout << ans+1 <<endl;
	}
	return 0;
}
