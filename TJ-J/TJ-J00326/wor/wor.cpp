#include <bits/stdc++.h>

using namespace std;

int n,k,a[500005],cnt;

int main(){
	freopen("wor.in","r",stdin);
	freopen("wor.out","w",stdout);
	cin>>n>>k;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	if(k == 0){
		for(int i = 1;i<=n;i++){
			if(a[i] == 0){
				cnt++;
			}
		} 
	}
	cout<<cnt;
	return 0;
}
