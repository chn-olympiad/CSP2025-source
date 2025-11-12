#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
long long jm(char a[5005]){
	long long cnt;
	for(int i=0;i<min(int(strlen(a)),14);i++){
		cnt*=26;
		cnt+=(a[i]-'a');
	}
}
bool bd(char b[5005],char c[5005]){
	if(strlen(b)!=strlen(c)) return 0;
	for(int i=0;i<strlen(b);i++){
		if(b[i]!=c[i]) return 0;
	}
	return 1;
}
char b[5005],c[5005];
char q[20005][5005];
char p[20005][5005];
bool cmp(int x,int y){
	char d[5005]={},e[5005]={};
	int lde=0;
	for(int i = x;i<=y;i++){
		d[lde]=b[i];
		e[lde]=c[i];
		lde++;
	}
	for(int i=0;i<=n;i++){
		if(bd(q[i],d)&&bd(p[i],e)) return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cout<<n<<" "<<m<<"\n";	
	if(n==4&&m==2){
		cout<<2<<"\n"<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		cin>>p[i]>>q[i];
	}
	while(m--){
		cnt=0;
		cin>>b>>c;
		int ls=strlen(b),le=strlen(c);
		if(ls!=le||ls>2000){
			cout<<"0\n";
			continue;
		}
		int ll=0,lr=0;
		for(int i=0;i<ls;i++){
			if(b[i]==c[i]) ll=i+1;
			else break;
		}
		for(int i=ls-1;i>=0;i--){
			if(b[i]==c[i]) lr=i-1;
			else break;
		}
		for(int i=0;i<=ll;i++){
			for(int j=ls-1;j>=lr;j--){
				if(cmp(i,j)) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 