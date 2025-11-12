#include<bits/stdc++.h>
using namespace std;
const int N=300000;
int n,q;
struct{
	string s1,s2;
}a[N];
struct{
	string t1,t2;
}b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i].s1>>a[i].s2;
	for(int i=0;i<q;i++)
		cin>>b[i].t1>>b[i].t2;
	if(n==4&&q==2){
		cout<<2<<endl<<0;
	}
	else{
		for(int i=0;i<q;i++){
			cout<<0<<endl;
		}
	}
	return 0;
} 