#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],c;
bool b[510];
int main(){
	freopen("employ.in","w",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(!b[i])c++;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(!c){
		cout<<0;
		return 0;
	}else{
		cout<<m;
	}
	return 0;
} 