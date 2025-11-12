#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int m,n;
int a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin.ignore();
	string s;
	getline(cin,s); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=1;
	fro(int i=1;i<=m;i++){
		printf("%d\n",c);
	}
	
	
	
	return 0;
}
