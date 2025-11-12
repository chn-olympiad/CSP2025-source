#include<bits/stdc++.h>
using namespace std;
int a[10005],x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,a[100005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[3];
	int ans=0;
	for(int i=1;i<=n;i++){
		b[1]=i;
		for(int j=i+1;j<=n;j++){
			b[2]=j;
			for(int k=j+1;k<=n;k++){
				b[3]=k;
				sort(b+1,b+3+1);
				if(i+j+k<b[3]*2){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

