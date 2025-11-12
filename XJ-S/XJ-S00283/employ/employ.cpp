#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,m;
int c[505];
int ans=0;
string join;

void plzh(int x){
	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>join;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int len=join.length();
	ans=1<<len;
	cout<<ans%998244353;
}
