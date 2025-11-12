#include<bits/stdc++.h>
using namespace std;
int a[100000] = {0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k,count = 0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int x = 1;
	int p = 0;
	for(int i = 1;i<=n;i++){
		if(a[i]==k){
			count+=1;
		}for(int j = i;j<=i+x;j++){
			p^=a[j];
		}if(p==k){
			count++;
		}x++;
	}
	cout<<count;
	return 0;
}
