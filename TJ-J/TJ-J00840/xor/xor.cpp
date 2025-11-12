#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int cnt;
struct node{
	int l,r;
};
node b[1000005];
bool vis[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		bool flag=0;
		for(int r=l;r<=n;r++){
			if(flag==1){
				break;
			}
			int sum=0;
			for(int i=l;i<=r;i++){
				sum^=a[i];
			}
			if(sum==k){
				cnt++;
				flag=1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
