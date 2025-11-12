#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	//	cout<<i;
		int aa[101000]{0};
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			aa[j]=a;
		}
		long long a=0;
		sort(aa,aa+n);
		for(int j=n/2;j<n;j++){
			a+=aa[j];
		}
	cout<<a<<endl;
}
     return 0;
}

