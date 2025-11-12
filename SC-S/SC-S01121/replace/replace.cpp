#include<iostream>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	char a[1000],b[1000];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	char t[1000];
	for(int i=1;i<=q;i++){
		cin>>t[i];
	}
	int cnt=0;
	cnt=n+q;
	cout<<cnt<<" "<<n-q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}