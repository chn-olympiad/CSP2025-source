#include<bits/stdc++.h>
using namespace std;
int a[100010];
int s[1010][1010];
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int start=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=2;j<=n*m;j++){
			if(a[j-1]<a[j]) swap(a[j-1],a[j]);
		}
	}
	int I=1,J=1;
	bool ok1=1,ok2=0;
	for(int i=1;i<=n*m;i++){
		s[J][I]=a[i];
		if(ok1) J++;
		if(ok2) J--;
		if(J==n+1){
			I++;
			ok1=0;
			ok2=1;
			J=n;
		}else if(J==0){
			I++;
			ok2=0;
			ok1=1;
			J=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==start){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}