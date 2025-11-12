#include<bits/stdc++.h>
using namespace std;
int a[1000010],vis[1000010];
int n,k,ans=0;
void f(){
	for(int i=1;i<=n;i++){
		if(k==i){
			ans++;
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=1,flag=0;
			for(int s=i;s<=j;s++){
				if(vis[s]==1){
					flag=1;
					break;
				}
				num^=s;
			}
			if(num==k&&flag==0){
				ans++;
				for(int s=i;s<=j;s++){
					vis[s]=1;
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f();
	//RP++! rp=2147483647!!!!!!
	//it is wrong i will wa it 
	//i can only ac first one |*__*|
	cout<<ans;
	return 0;
}
