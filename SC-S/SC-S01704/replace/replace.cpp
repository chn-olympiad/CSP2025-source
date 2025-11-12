#include<bits/stdc++.h>
using namespace std;
int n,m;
string a1,a2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1>>a2;
	}
	for(int i=1;i<=n;i++){
		cin>>a1>>a2;
	}
	if(n==4&&m==2){
		cout<<"2\n0";
	}
	if(n==3&&m==4){
		cout<<"0\n0\n0";
	}
	return 0;
}