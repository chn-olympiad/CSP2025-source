#include<bits/stdc++.h>
using namespace std;
long long n,m,p=998244353,c[505],ans[505],anss,b,ss,sum1;
string s;
bool vis[505];
void aa(int a,int sum,int y){
	if(a==0){
		ans[sum]=(ans[sum]+1)%p;
		return;
	}
	if(y>n-m)return;
	for(int i = 1; i <= n ; i++){
		if(!vis[i]){
			vis[i]=1;
			if(c[i]>y&&s[s.size()-a]=='1')aa(a-1,sum+1,y);
			else aa(a-1,sum,y+1);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1 ; i<= n ; i++){
		cin >> c[i];
		if(c[i]==0)b+=1;
	}
	sort(c+1,c+n+1);
	if(n<=10){
		aa(n,0,0);
		for(int i = m ; i <= n; i++)anss=(anss+ans[i])%p;
		cout << anss;
	}else if(n==m){
		for(int i = 0 ; i < s.size();i++)if(s[i]=='0')b=1;
		if(b)cout << 0;
		else{
			anss=1;
			for(int i = 1; i <= n ; i++){
				anss=(anss*i)%p;
			}
			cout << anss;
		}
	}else{
		for(int i = 0 ; i < s.size();i++)if(s[i]=='1')ss++;
		if(ss>m)cout << 0;
		else{
			if(c[n-m+1]>n-m){
				anss=1;
				for(int i = 1; i <= n ; i++){
					anss=(anss*i)%p;
				}
				cout << anss;
			}
		}
	}
	return 0 ;
}
