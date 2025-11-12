#include<bits/stdc++.h>
using namespace std;
int a[100005]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	int e,f;
	long long c=0;
	while(t--){
		c=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>e>>f;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n/2;i++){
			c+=a[i];
		}
		cout<<c<<endl;
	}
	return 0;
}
