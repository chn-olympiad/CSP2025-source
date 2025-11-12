#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,a[500010];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k) cnt++;
	}
	for(int i=0;i<n;i++){
		int x=a[i];
		for(int j=i;j<n;j++){
			x+=x|a[i];
			if(x==k) cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

