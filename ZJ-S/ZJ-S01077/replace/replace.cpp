#include<bits/stdc++.h>
using namespace std;
const int N=2E5+10;
string s[N][2],t[N][2];
int l[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,c=0;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		l[i][1]=s[i][1].size();
		l[i][2]=s[i][2].size();
	}
	for(i=1;i<=q;i++){
		c=0;
		cin>>t[i][1]>>t[i][2];
		int l1=t[i][1].size(),l2=t[i][2].size();
		for(int j=1;j<=n;j++){
			int a=t[i][1].find(s[j][1]);
			while(a!=-1){
				t[i][1].replace(a,l[j][1],s[j][2]);
				if(t[i][1]==t[i][2]) c++;
				t[i][1].replace(a,l[j][2],s[j][1]);
				a=t[i][1].find(s[j][1],a+1);
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
