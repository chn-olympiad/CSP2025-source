#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int P=13331,N=2e5+10;
int n,q;
string s1,s2;
unsigned long long a[N],b[N],t1,t2,p[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;p[0]=1;
	for(int i=0;i<=N-1;i++)
	  p[i]=p[i-1]*P;
	
	return 0;
}
//chzx_lfw AK IOI!!!!!
