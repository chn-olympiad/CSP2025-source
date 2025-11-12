#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int> >b;
int sum=int_MIN;
int dfs(int s,int n){
	int mx=s;
	for(pair<int,int> v:b){
		if(v.first>n){
			mx=max(dfs(s+1,v.second),mx);
		}
	}
	return mx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int s=a[i];
			for(int c=i+1;c<=j;c++){
				s^=a[c];
			}
			if(s==k){
				b.push_back({i,j});
			}
		}
	}
	sum=dfs(0,-1);
	cout<<sum;
	return 0;
}