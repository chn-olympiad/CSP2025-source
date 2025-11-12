#include<bits/stdc++.h>
using namespace std;
int n,m,tong=0,ans=0;
bool f=0;
bool vis[505],v[505];
string s;
int p[505],qu[505],r=0,chick[505];
void d(int x){
	if(x>n){
		for(int i=1;i<=n;i++){
			
			if(chick[i]<p[qu[i]]&&s[qu[i]]!='0')tong++;
		}
		if(tong==m)ans++;
		tong=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			qu[x]=i;
			d(x+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.length();
	int fail=0;

	for(int i=0,j=0;i<len;i++){
		if(s[i]=='0')fail++;
		chick[++j]=fail;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	d(1);
	cout<<ans;
} 
