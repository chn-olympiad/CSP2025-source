#include<bits/stdc++.h>
using namespace std;
struct yz{
	string t1,t2;
}a[1000005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].t1>>a[i].t2;
	}
	while(q--){
		string s,s1;
		cin>>s>>s1;
		if(s==s1){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

