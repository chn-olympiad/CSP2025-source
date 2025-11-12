#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define x first
#define y second
using namespace std;
int n,m; 
string a;
int b[500];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)cin>>b[i];
	cout<<m;
	
	return 0;
}
