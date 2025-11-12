#include<bits/stdc++.h>
using namespace std;
int n,q,f,to;
string a,b,x;
map<string,int> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int l=a.size();
		for(int j=0;j<l;j++){
			if(a[j]!=b[j]){
				f=j;
				break;
			}
		}
		for(int j=l-1;j>=0;j--){
			if(a[j]!=b[j]){
				to=j;
				break;
			}
		}
		x=a.substr(f,to-f+1)+b.substr(f,to-f+1);
		m[x]++;
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int l=a.size();
		for(int j=0;j<l;j++){
			if(a[j]!=b[j]){
				f=j;
				break;
			}
		}
		for(int j=l-1;j>=0;j--){
			if(a[j]!=b[j]){
				to=j;
				break;
			}
		}
		x=a.substr(f,to-f+1)+b.substr(f,to-f+1);
		printf("%d\n",m[x]);
	}
	return 0;
}
