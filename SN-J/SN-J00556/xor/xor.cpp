#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,cnt;
ll a[500001],s[500001],vis[500001];
ll calsum(int l,int r){
	if(l==r){
		return a[l];
	}
	s[l]=a[l];
	for(int i=l;i<r;i++){
		s[i+1]=s[i]^a[i+1];
	}
	return s[r];
}
bool check(int l,int r){
	for(int i=l;i<=r;i++){
		if(vis[i]==1){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","rw",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(calsum(i,j)==k&&check(i,j)){
				cnt++;
				for(int x=i;x<=j;x++){
					vis[x]=1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
//Tairitsu from Eternal Core, Vicious Labyrinth and Black Fate
