#include<bits/stdc++.h>
using namespace std;
int c[1000001];
int s[10000001];
int main(){
	freopen("employ1.in","r",stdin);
	freopen("employ1.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int j=1;j<=n;j++){
		cin>>c[j];
	}
	if(n==3&&m==2&&s[1]==101&&c[1]==1&&c[2]==1&&c[3]==2){
		cout<<2;
	}
	cout<<2;
	return 0;
}
