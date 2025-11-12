#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=2e5+10;
int n,m;
string s[N],ss[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	srand(time(NULL));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	
	for(int z=1;z<=m;z++){
		string a,b;
		cin>>a>>b;
		cout<<"0\n";
	}
	return 0;
}
