#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
map<int,int>mp;
int a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int num=0,ans=0,r=0;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num^=a[i];
		int t=mp[num^k];
		if(t==0&&(num^k)!=0){
			mp[num]=i;
			continue;
		}
		if(t>=r){
			ans++;
			r=i;
		}mp[num]=i;
	}cout<<ans;
	return 0;
}