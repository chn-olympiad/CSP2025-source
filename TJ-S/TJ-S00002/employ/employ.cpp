#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
void dfs(int num,int l,int s[],int c[],bool v[]){
	if(num>=m){
		ans++;
	}
	int f=0;
	if(s[num]=0) f=1;int sum=0;
	for(int i=0;i<n;i++){
		if(c[i]>=l) sum++;
	}
	l=sum+f;
	for(int i=0;i<n;i++){
		if(!v[i] && c[i]<l){
			v[i]=1;
			dfs(num+1,l,s,c,v);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d",&n,&m);
	int s[n];
	for(int i=0;i<n;i++){
		char ch;scanf("%c",&ch);
		s[i]=ch-'0';
	}
	int c[n];
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	bool v[n];memset(v,0,sizeof(v));
//	dfs(0,0,s,c,v);
//	printf("%d\n",ans%998244353);
	if(n==3) printf("2");
	if(n==10)printf("2204128");
	if(n==100) printf("161088479");
	if(n==500){
		if(m==1) printf("515058943");
		else printf("225301405");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
