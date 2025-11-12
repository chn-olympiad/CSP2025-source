#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
int n,m,c[550],a[550],b[550];
string s;
inline int co(int s,int k){
	if(k==0)	return 1;
	int sum1=1,sum2=1;
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	b[0]=0;
	for(int i=1;i<=s.length();i++){
		b[i]=b[i-1]+((s[i-1]-'0')^1);cout<<b[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		a[c[i]]++;
	}
	
	return 0;
}