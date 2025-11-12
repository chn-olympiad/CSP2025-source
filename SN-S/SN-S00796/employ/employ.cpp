//高浚然 SN-S00796 西安高新第一中学 
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
string s;
int c[505],a[505];
bool vis[505];
int cnt,ans,num;
int n,m;
void dfs(int x)
{
	if(x==n+1)
	{
		cnt=0;
		num=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=cnt){
				cnt++;
			}
			else{
				if(s[i-1]=='0'){
					cnt++;
				}
				else{
					num++;
				}
			}
		}
		if(num>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]){
			a[x]=i;
			vis[i]=1;
			x++;
			dfs(x);
			x--;
			vis[i]=0;
		}
		else continue;
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(n<=10){
		dfs(1);
		cout << ans;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0||s[i-1]=='0'){
				cout << 0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout << ans;
	}
	return 0;
}
