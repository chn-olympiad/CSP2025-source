#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	int ans=0;
	int x,y,z;
	int a[100005]={0};
	int b[100005]={0};
	int c[100005]={0};
	int vi[5]={0};
	cin>>t>>n;
	for(int k=0;k<t;++k){
		for(int i=0;i<n;++i){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a,a+n);
		for(int i=n/2;i<n;++i)
			ans+=a[i];
		vi[k]=ans;
		ans=0;
	}
	for(int i=0;i<t;++i) cout<<vi[i]<<endl;
} 
