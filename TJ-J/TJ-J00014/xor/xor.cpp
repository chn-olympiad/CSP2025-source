#include<bits/stdc++.h>
using namespace std;
int n,f,ans;
int a[500005],b[500005];
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				if(vis[a[k]])	goto qp;
				sum^=a[k];
			}
			if(sum==f){
				ans++;
				for(int k=i;k<=j;k++){
					vis[a[k]]=true;
				}
			}
			qp:;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//#include<iostream>
//using namespace std;
//int n,k;
//int a[10005]={1},sum,ans;
//int main(){
//	cin>>n>>k;
//	for(int i=1,x;i<=n;i++){
//		cin>>x;
//		sum=(sum+x)%k;
//		ans+=a[sum];
//		a[sum]++;
//	}
//	cout<<ans<<endl;
//}
