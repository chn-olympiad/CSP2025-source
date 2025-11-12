#include<bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+10;
int a[MAXN],b[MAXN],c[MAXN],t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,greater<int>());
		for(int i=1;i<=n/2;++i){
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}