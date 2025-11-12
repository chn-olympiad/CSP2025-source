#include<bits/stdc++.h>
using namespace std;	
int yunsuan(int r,int b){
	int a=r|b;
	int c=r&b;
	return a-c;
}
int n,a[500001],s[500001],k,ans,t[500001];
bool istrue(int i,int len){
	for(int j=i;j<=i+len-1;j++){
		if(t[j]==1){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=yunsuan(s[i-1],a[i]);
		//cout<<s[i];
	}	
	for(int len=1;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){			
			if(yunsuan(s[i+len-1],s[i-1])==k&&istrue(i,len)){
				ans++;
				t[i+len-1]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
