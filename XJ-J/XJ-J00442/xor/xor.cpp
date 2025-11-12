#include<bits/stdc++.h>
using namespace std;
int a[5005],cnt=0,n,m,ans,flag=1,s[1005],k,last=0;
int yihuo(int a,int b){
	return (a|b)-(a&b);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[0]=0;
	s[1]=a[1];
	for(int i=1;i<=n;i++){
		s[i]=yihuo(s[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=last;j<i;j++){
			if(yihuo(s[i],s[j])==k){
				ans++;
				//cout<<j<<" "<<i<<endl;
				last=i;
				i=last;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
