#include<bits/stdc++.h>
using namespace std;
long long a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,b,c;
		long long sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b>>c;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=a[i];
		}
		cout<<sum;
	}
	return 0;
}
