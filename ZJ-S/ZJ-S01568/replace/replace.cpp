#include<bits/stdc++.h>
using namespace std;
char in[1001][1001];
char out[1001][1001];
int f[1001];
int ans;
int n,m;
int l;
char q[1001],a[1001],tmp[1001];
void ex(char s[],int loc,int ty){
	for(int i=0;i<1001;i++){
		tmp[i]=NULL;
	}
	for(int i=0;i<strlen(s);i++){
		tmp[i]=s[i];
	}
	int t=0;
	for(int i=loc;i<loc+strlen(out[ty]);i++){
		tmp[i]=out[ty][t];
		t++;
	}
}
int check(char s[],int loc,int ty){
	int t=0;
	for(int i=loc;i<loc+strlen(in[ty]);i++){
		if(s[i]!=in[ty][t]){
			return 0;
		}
		t++;
	}
	return 1;
}
void dfs(char s[]){
	if(s==a){
		ans++;
		return ;
	}
	for(int i=0;i<n;i++){
		if(f[i]==0){
			for(int j=0;j<l;j++){
				if(s[j]==in[i][0]){
					if(check(s,j,i)){
						ex(s,j,i);
						s=tmp;
						f[i]=1;
						dfs(s);
						f[i]=0;
					}
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>in[i]>>out[i];
	}
	while(m--){
		cin>>q>>a;
		ans=0;
		memset(f,0,sizeof(f));
		l=strlen(q);
		dfs(q);
		cout<<ans;
	}
	return 0;
}