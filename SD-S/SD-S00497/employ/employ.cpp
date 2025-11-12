#include<bits/stdc++.h>
#define int long long
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define forrr(i,a,b) for(int i=a;i>=n;i--)
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int mod=998244353;
int c[600];
int a[600];
signed main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	scanf("%lld%lld",&n,&m);
	string s;
	cin>>s;
	forr(i,1,n){
		cin>>c[i];
	}
	int ans=0;
	forr(i,1,n) a[i]=i;
	do{
		int sum=0;
		int m2=0;
		forr(i,1,n){
			if(s[i-1]-'0'==0){
				sum++;
				continue;
//				cout<<"$$\n";
			}else{
				if(sum>=c[a[i]]){
					sum++;
					continue;
				}else{
					m2++;
				}
			}
//			cout<<m2<<'\n';
		}
//		cout<<"!!"<<m2<<' '<<m<<'\n';
		if(m2>=m) ans=(ans+1)%mod;
//		forr(i,1,n) cout<<a[i]<<' ';
//		cout<<'\n';
	}while(next_permutation(a+1,a+1+n));
	cout<<ans%mod<<'\n';
	/*
	3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

	*/
 	return 0;
 }
