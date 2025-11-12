#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int p=998244353;
int n,m,s[1000010],c[1000010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	char xx;
	xx=getchar();
	for(int i=1;i<=n;i++){
		char a;
		a=getchar();
		s[i]=a-'0';
		sum+=s[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(sum==n){
		sum=0;
		for(int i=1;i<=n;i++){
			if(c[i]>0){
				sum++;
			}
		}
		if(sum>=m){
			int ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=p;
			}
			cout<<ans<<endl;
			
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	return 0;
}
