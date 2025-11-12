#include<bits/stdc++.h>
using namespace std;
int n,q;
struct first{
	string s1;
	string s2;
}a[10005];
bool pd(int x,first y){
	for(int i=0;i<=y.s1.length();i++){
		if(y.s1[i]==a[x].s1[0]){
			bool k=true;
			for(int j=1;j<a[x].s1.length();j++){
				if(y.s1[i+j]!=a[x].s1[j]){
					k=false;
					break;
				}
			}
			if(k){
				first z=y;
				for(int j=0;j<a[x].s1.length();j++){
					z.s1[i+j]=a[x].s2[j];
				}
				if(z.s1==z.s2){
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++){
		first b;
		int cnt=0;
		cin>>b.s1>>b.s2;
		if(b.s1.length()==b.s2.length()){
			for(int i=1;i<=n;i++){
				if(pd(i,b)){
					cnt++;
				}
			}
			printf("%d\n",cnt);
		}
		else{
			printf("%d\n",cnt);
		}
	}
	return 0;
}
