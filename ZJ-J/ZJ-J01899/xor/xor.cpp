#include<bits/stdc++.h>
using namespace std;
int n,k;
int flag1=1,flag2=1;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0) flag1=0;
	if(k!=0&&k!=1) flag2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag1=0;
		if(a[i]!=1&&a[i]!=0) flag2=0; 
	}
	int x=0,y=0;
	if(flag1){
		cout<<n/2;
	} 
	else if(flag2){
		for(int i=1;i<=n;i++){
			if(a[i]==0) x++;
			else y++;
		}
		if(k==0) cout<<x+y/2;
		else cout<<y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
