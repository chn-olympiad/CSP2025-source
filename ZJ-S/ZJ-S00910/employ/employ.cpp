#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
#define MAXN 505
#define Mod 998244353
int n,m,s[MAXN],c[MAXN],a[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	For(i,1,n){
		char c;
		cin>>c;
		if(c=='0') s[i]=0;
		else s[i]=1;
	}
	For(i,1,n){
		cin>>c[i];
		a[i]=i;
	}
	int sum=0;
	do{
		int cnt=0;
		For(i,1,n){
			int now=a[i];
			if(cnt>=c[now]||s[i]==0){
				cnt++;
			}
			if(i-cnt>=m){
				sum++;
				break;
			}
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<sum<<endl;
	return 0;
}
