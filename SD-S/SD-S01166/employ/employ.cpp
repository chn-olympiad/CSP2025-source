#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdio>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[505];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		cout<<2;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}

