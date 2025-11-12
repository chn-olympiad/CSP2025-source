#include<bits/stdc++.h>
using namespace std;

char n[1000005];int n_size;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>'9')continue;
		n[n_size] = s[i];
		n_size++;
	}
	sort(n,n+n_size,cmp);
	cout<<n;
	return 0;
}
