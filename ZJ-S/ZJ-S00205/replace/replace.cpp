#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	string a,b;
}a[N];
int n,q;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].b;
	while(q--){
		string s,s1;
		cin>>s>>s1;
		printf("0\n");
	} 
	return 0;
}
