#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10005];
int qzh[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int fa=0;
	for(int i=1;i<n;i++){
		if(a[i]^a[i+1]==k){
			fa++;
		}
		i++;
	}
	int y=0;
	for(int i=1;i<=n;i++){
		int y1=a[i];
		while(y1!=k&&i<=n){
			i++;
			y1^=a[i];
		}
		if(y1==k)
			y++;
	}
	cout<<max(y,fa);
	return 0;
}
