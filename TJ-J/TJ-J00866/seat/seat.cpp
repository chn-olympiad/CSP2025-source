#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i = 1,i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>a[i];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
