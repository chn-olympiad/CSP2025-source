#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r","srdin");
//	freopen("number.out","w","srdout");
	int n,m;
	cin>>n>>m;
	int v=n*m;
	int R;
	int s[v+5];
	for(int i=0;i<v;i++){
		cin>>s[i];
	}
	R=s[0];
	sort(s,s+v);
	int l[v];
	for(int i=0;i<n;i++){
		l[i]=s[v-i];
	}
	int a[n+1][m+1];
	a[1][1]=l[0];
	a[1][2]=l[1];
	a[1][3]=l[2];
	a[1][4]=l[3];
	a[1][5]=l[4];
	a[2][1]=l[5];
	a[2][1]=l[6];
	a[2][1]=l[7];
	a[2][1]=l[8];
	a[2][1]=l[9];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

