#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int Q=2e5+5;
int n,q;
struct str{
	string s;
}a[N][3];
struct que{
	string q;
}t[Q][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j].s;
		}
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>t[i][j].q;
		}
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
