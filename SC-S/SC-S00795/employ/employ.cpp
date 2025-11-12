#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000],n,m;
int l[100000],sum;
bool dfs(int top,int zhao,int zou)
{
	if(zou>l[n-1]&&zhao<m)return 0;
	if(n-top+zhao-1<m)return 0;
	if(n-top==1)return 1;
	if(s[top]==0||zou>l[top])return dfs(top+1,zhao,zou+1);
	return dfs(top+1,zhao+1,zou);
}
bool b[100000];
void sc(int top,int shang)
{
	if(top==n){
		sum+=dfs(0,0,0);
		b[shang]=1;
	}
	for(int i=0;i<n-top;i++){
		if(b[i]){
			l[top]=a[i];
			b[i]=0;
			sc(top+1,i);
		}
	}
	b[shang]=1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>s;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sc(0,0);
	cout<<sum;
	return 0;
}
//呃啊，玩单了