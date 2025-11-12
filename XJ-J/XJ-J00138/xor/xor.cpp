#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int a[maxn];
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor6.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=m){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
