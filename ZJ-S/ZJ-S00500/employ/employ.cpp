#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
const int mod=998224353;
int n,m,c[N],a[N],ans,tot[N];
char s[N];
bool check(){
	for(int i=1;i<=n;i++)if(a[i]!=i)return false;
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++)if(s[i]!='1')return false;
	return true;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=n;i++)cin>>c[i];
	do{
//		for(int i=1;i<=n;i++)cout<<a[i];
//		cout<<endl;
		int sum=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(sum>=c[a[i]]||s[i]=='0'){
				sum++;
				continue;
			}
			if(s[i]=='1'){
				num++;
			}
		}
		if(num>=m)ans++;
		next_permutation(a+1,a+1+n);
	}while(!check());
	cout<<ans;
	return 0;
}