#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
string s;
const long long maxn = 998244353;
int b[505];
int p;
int c[505];
void dfs(int i,int sum,int gu){
	if(i==n+1&&sum>=m){
		p++;
		//for(int j=1;j<=n;j++)cout<<c[j]<<" ";
		//cout<<endl;
	}
	if(i==n+1)return;
	for(int ii=1;ii<=n;ii++){
		if(b[ii]==0){
			b[ii]=1;
			c[i] = ii;
			//cout<<i<<" "<<s[i]<<endl;
			if(gu>=a[ii]||s[i-1]=='0'){
				
				dfs(i+1,sum,gu+1);
			}else{
				//cout<<gu<<" "<<a[ii]<<endl;
				dfs(i+1,sum+1,gu);
			}
			b[ii]=0;
		}
	}
}
void solve1(){
	long long cnt= n;
	for(long long i= n-1;i>=1;i--){
		cnt = (cnt%maxn)*(i%maxn)%maxn;
		//cout<<cnt<<" "<<i<<endl;
	}
	cout<<cnt<<endl;
}
void solve2(){
	dfs(1,0,0);
	cout<<p;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int len =s.size();
	int F=1;
	for(int i=0;i<len;i++){
		if(s[i]=='0')F=0;
	}
	if(n<=18)solve2();
	else if(F==1)solve1();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
