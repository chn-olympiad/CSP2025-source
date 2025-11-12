#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=600;
const int mod=998244353;
int c[N];
bool s[N];
int a[N];
string s1;
int n,m;
signed main(){
	//freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		s[i]=s1[i-1]-'0';
		if(s[i]==1){
			tot++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	int ans=1;
	if(tot==n)
	{	
		for(int i=2;i<=n;i++)
		{
			//cout<<ans<<'\n';
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	else{
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=a[i-1]+1;
		}
		
		while(next_permutation(a+1,a+n+1)){
			int mm=0;
			int pre=0;
			for(int i=1;i<=n;i++){
				cout<<c[a[i]]<<" ";
			}
			cout<<endl;
			for(int i=1;i<=n;i++)
			{	
				
				if(mm==m){
					ans++;
					continue;
				}
				if(c[a[i]]>pre&&s[i]==1){
					mm++;
				}
				else if(s[i]==0||c[a[i]]<=pre){
					pre++;
				}cout<<mm<<" "<<pre<<" ";
			}
			cout<<endl;
		}
		cout<<ans;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
//161088479
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/


