#include<bits/stdc++.h>
using namespace std;
int n,k,u,p=0;
int a[500005];
bool flag;
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		u=a[j];
//		cout<<"u0:"<<u<<" j:"<<j<<endl;
		if(u==k){
			p=j+1;
//			cout<<"ans++("<<j<<","<<j<<")"<<endl;
			ans++;
			continue;
		}
		for(int i=j-1;i>=p;i--){
			u^=a[i];
//			cout<<"u:"<<u<<" i:"<<i<<endl;
			if(u==k){
				p=j+1;
//				cout<<"ans++("<<i<<","<<j<<")"<<endl;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

//我能得340分！ 
