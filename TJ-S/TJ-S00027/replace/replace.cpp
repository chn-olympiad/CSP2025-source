#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
map<string,int> flag;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		flag[a[i]]=i;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		if(b[flag[x]]==y)
			printf("2\n");
		else
			printf("0\n");
	}
	return 0;
}
