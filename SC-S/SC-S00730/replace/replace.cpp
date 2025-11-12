#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200005][5],q[5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=m;i++){
		int ant=0;
		cin>>q[1]>>q[2];
		for(int j=1;j<=n;j++){
			if(a[j][1]==q[1]&&a[j][1]==q[1]){
				ant++;
			}
		}
		cout<<ant<<endl; 
	}
	return 0;
}