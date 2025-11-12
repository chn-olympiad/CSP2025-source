#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353;
int n,m,a[N],c[N],num[N];
char s[N];
bool flag=1;
long long ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
		if(a[i]==0) flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		num[i]=i;
	}
	if(flag==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%M;
		}
		cout<<ans<<endl;
		return 0;
	}
	else cout<<0<<endl;
//	do{
//		for(int i=1;i<=n;i++){
//			cout<<num[i]<<' ';
//		}
//		cout<<endl;
//	}while(next_permutation(num+1,num+1+n));
	return 0;
}
