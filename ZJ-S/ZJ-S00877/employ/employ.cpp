#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int k=n;
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			k=i;
			break;
		}
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		for(int j=i-1;n-k+1-j>0;j++){
			cnt+=n-k+1-j;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
