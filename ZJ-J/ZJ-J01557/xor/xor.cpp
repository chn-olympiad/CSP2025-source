#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[50005];
long long cnt;
map<int,map<int,long long> >mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) continue;
			mp[i][j]=mp[i][j-1]^a[j];
		}
	}
	int last_id=n+1;
	for(int i=n;i>=1;i--){
		for(int j=i;j<last_id;j++){
			if(mp[i][j]==k){
				cnt++;
				last_id=i;
				break;
			}
		}
	}
	cout<<cnt;
}