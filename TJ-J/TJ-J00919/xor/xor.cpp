#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<map>
#include<deque>
#include<set>
#define ll long long
using namespace std;
const int N=105;
int n,k; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		cout<<n/2;
	}else{
		cout<<1;
	}
	return 0;
}

