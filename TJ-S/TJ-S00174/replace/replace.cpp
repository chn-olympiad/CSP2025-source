#include<bits/stdc++.h>
using namespace std;
struct node{
	string s,t;
}a[200010];
node b[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].s>>b[i].t;
	}
	int flag=0;
	for(int i=1;i<=q;i++){
		flag=0;
		for(int j=1;j<=n;j++){
			if(b[i].s==a[j].s&&b[i].t==a[j].t){
				flag=1;
			}
		}
		if(!flag){
			cout<<0<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	return 0;
} 
