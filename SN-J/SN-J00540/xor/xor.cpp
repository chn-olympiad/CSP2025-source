#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
bool f[500005];
bool sum(int l,int r){
	int s=0;
	for(int i=l;i<=r;i++)
		s^=a[i];
	return s==k;
}
bool pd(int l,int r){
	for(int i=l;i<=r;i++)
		if(f[i]==1)
			return false;
	for(int i=l;i<=r;i++)f[i]=true;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sum(i,j))
				if(pd(i,j)){
					cnt++;
					i=j;
					break;
				}
		}
	}
	cout<<cnt;
	return 0;
}

