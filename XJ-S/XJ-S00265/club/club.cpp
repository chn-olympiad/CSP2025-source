#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int dp[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int s=0; 
		for(int i=1;i<=n;i++){
			int a1,b1,c1;
			cin>>a1>>b1>>c1;
			s+=max(a1,max(b1,c1));
		}
		cout<<s<<endl; 
	}
	return 0;
} 
