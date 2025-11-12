#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int inf=0x3f3f3f3f;
int f[N];
int maxx,cnt[N];
int main(){
	int t;
	cin>>t;
	int n;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			int x,y,z;
			cin>>x>>y>>z;
			maxx=max(max(x,y),z);
			cnt[i]+=maxx;
		}
	}
	for(int i=0;i<t;i++){
		cout<<cnt[i]<<endl;
	}
	
}