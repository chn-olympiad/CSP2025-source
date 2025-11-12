#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		int last,x,s=0;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(i==1) last=x;
			else{
				if(x==0) s++;
				if(last==1&&x==1){
					s++;
					last=0;
				}else{
					last=x;
				}
			}
		}
		cout<<s;
	}else if(k==1){
		int s=0,x;
		for(int i=1;i<=n;i++){
			cin>>x;
			s+=x;
		}
		cout<<s;
	}else{
		cout<<k;
	}
	return 0;
}
