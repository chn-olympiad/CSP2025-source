#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define IO
using namespace std;
#define ll long long
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
string s,ans;int n;
int main(){
#ifdef IO
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;n=s.size();
	L(i,0,n-1){
		if(s[i]>='0'&&s[i]<='9')ans+=s[i];
	}
	sort(ans.begin(),ans.end(),[](char a,char b){
		return a>b;
	});
	cout<<ans;
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
