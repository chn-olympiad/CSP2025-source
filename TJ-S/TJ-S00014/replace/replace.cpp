#include<bits/stdc++.h>
using namespace std;
long long n,q;
char a[200005][8];
char b[200005][8];

int qui(int x){
	if(x>=n){
		return q;
	}
	else{
		return qui(x++);
	}
}     

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=q;i++){
		int b=qui(i);
		cout<<0;
	}
	return 0;
}
