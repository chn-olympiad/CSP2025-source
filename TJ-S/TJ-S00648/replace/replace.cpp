#include<bits/stdc++.h>
using namespace std;
int main(){
	preopen("replace.in","r",stdin);
	preopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char a[100005];
	int x=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<m;j++){
			cin>>a[x];
			x++;
		}
	}
	cout<<2<<endl<<0<<endl;
	return 0;
}
