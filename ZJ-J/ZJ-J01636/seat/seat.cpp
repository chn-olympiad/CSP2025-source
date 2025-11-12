#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i = 2;i <= n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	//cout<<cnt<<endl;
	int flag;
	if(cnt%n>=1)flag=cnt/n+1;
	else flag=cnt/n;
	cout<<flag<<" ";
	if(flag%2==1)cout<<cnt-(flag-1)*n;
	else cout<<n-cnt%n+1;
	return 0;
}
/*
2 2
99 100 97 98
*/
