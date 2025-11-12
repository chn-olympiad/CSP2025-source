#include<bits/stdc++.h>
using namespace std;
int t,n;
int a,b,c;
int sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			sum+=max(max(a,b),c);
		}
		cout<<sum<<endl;
	}
	return 0;
}