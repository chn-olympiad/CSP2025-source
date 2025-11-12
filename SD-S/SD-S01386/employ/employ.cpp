#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,c[505];
string s;
int cnt;
int a[505];
bool fl[505];
void dfs(int step){
	if (step>n){
		int x=n;
		for (int i=1;i<=n;i++)
			if (s[i-1]=='0'||n-x>=c[a[i]]){
				x--;
				if (x<m)
					break;
			}
		if (x>=m)
			cnt=(cnt+1)%N;
		return ;
	}
	for (int i=1;i<=n;i++)
		if (fl[i]==0){
			fl[i]=1;
			a[step]=i;
			dfs(step+1);
			fl[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
		cin>>c[i];
	bool f=1;
	for (int i=0;i<int(s.size());i++)
		if (s[i]=='0'){
			f=0;
			break;
		}
	dfs(1);
	cout<<cnt;
	return 0;
}
