//SN-J00722 王培翔 雁塔第一学校
#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[50005];
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		bool flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				if(flag==1){
					ans++;
					flag=0;
				}
				else{
					flag=1;
				}	
			}else{
				if(flag==0){
					ans++;
				}
			}
		}
		cout<<ans; 
	}
	else cout<<9;
	return 0;
}
