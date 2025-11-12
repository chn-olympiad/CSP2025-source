#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n,k;
int a[N];
int cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=a[i];
		if(a[i]==k) {cnt++; continue; }
		for(int j=i+1;j<=n;j++){
			ans=ans^a[j];
			if(ans==k) { i=j+1; cnt++; break; }
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
