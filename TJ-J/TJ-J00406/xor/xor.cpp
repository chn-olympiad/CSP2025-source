#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		int cnt=0;
		bool flag=false;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(x==0){
				cnt++;
			}else if(x==1&&flag){
				cnt++;
			}
			if(x==1){
				flag=!flag;
			}
		}
		cout<<cnt;
	}if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(x==1){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
} 
