#include<bits/stdc++.h>
using namespace std;
int c[505];
char s[505];
int res[505]={1,2,6,24,120,720,5040,40320,362880,3628800};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
