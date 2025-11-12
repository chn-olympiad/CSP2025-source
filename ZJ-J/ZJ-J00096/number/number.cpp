#include<bits/stdc++.h>
using namespace std;
string a,maxa;
long long vis[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			vis[a[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(vis[i]){
			cout<<i;
			vis[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
