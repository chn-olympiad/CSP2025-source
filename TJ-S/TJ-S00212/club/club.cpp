#include<bits/stdc++.h>
using namespace std;
int t,n,sum;
bool cmp (int a,int b){
	return a>b;
}
int a[100005];
int b[100005];
int c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			sum+=max(a[j],max(b[j],c[j]));
		}
		cout<<sum<<endl;
		sum=0;
	}





	return 0;
}
