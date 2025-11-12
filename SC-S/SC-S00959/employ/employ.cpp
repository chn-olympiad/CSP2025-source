#include<bits/stdc++.h>
using namespace std;
int m,n;
int a;
long long ji=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cout<<1<<endl;
	if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a;
			if(a==0){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=m;i++){
			ji*=i;
		}
		cout<<ji;
		return 0;
	}else{
		int j=0;
		int gg;
		cin>>gg;
		for(int i=1;i<=n;i++){
			cin>>a;
			if(a==0){
				continue;
			}
			j++;
		}
	
		for(int i=1;i<=j;i++){
			
			ji*=i;
			
		}
		cout<<ji;
		return 0;
	}
	return 0;
}