#include<bits/stdc++.h>
using namespace std;
int main(){
int n,t,a[1000000],b[1000000],c[1000000];
cin>>t;
for(intS i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];
			cin>>b[j];
			cin>>c[j];
		}
	}
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	sort(c,c+n,cmp);
	cout<<a[0]+b[0]+c[0]<<endl;
	return 0;
}

