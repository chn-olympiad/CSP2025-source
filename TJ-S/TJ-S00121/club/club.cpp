#include<bits/stdc++.h>
using namespace std;
struct{
	long long a,b,c;
	long long ma=INT_MIN,cnt=0;
}a[100010];
long long t,n,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].ma){
				a[i].ma=a[i].a;
			}
			if(a[i].b>a[i].ma){
				a[i].ma=a[i].b;
			}
			if(a[i].c>a[i].ma){
				a[i].ma=a[i].c;
			}
			s+=a[i].ma;
			cout<<a[i].ma<<endl;
			a[i].ma=0;
		}
		cout<<s<<endl;
		s=0;
	}
	return 0;
}
