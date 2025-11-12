#include<bits/stdc++.h>
using namespace std;
int t,n,h=0;
struct node{
	int a,b,c,ma=0;
}m[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].ma=max(m[i].a,max(m[i].b,m[i].c));
		}
		for(int i=1;i<=n;i++){
			h+=m[i].ma;
		}
		cout<<h<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
