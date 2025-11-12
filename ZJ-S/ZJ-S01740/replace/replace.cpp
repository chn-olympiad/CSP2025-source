#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2005,base=2333;
int n,q;
int len[N],L[N],ans;
ull hsh[2][N];
char s[2][N][N];
char t[2][N];
ull pre[2][N];
ull pw[N];
ull get(int x,int l,int r){
	if(l>r)return 0ull;
	return pre[x][r] -pre[x][l-1]*pw[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	pw[0]=1;
	for(int i=1;i<=2000;i++)
		pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[0][i]+1,s[1][i]+1);
		int l=strlen(s[0][i]+1);
		for(int j=1;j<=l;j++){
			hsh[0][i] = hsh[0][i]*base +s[0][i][j];		
			hsh[1][i] = hsh[1][i]*base +s[1][i][j]; 
		}
		L[i]=l;
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",t[0]+1,t[1]+1);
		int len=strlen(t[0]+1);
		ans=0;
		for(int j=1;j<=len;j++){
			pre[0][j] =pre[0][j-1]*base+t[0][j];
			pre[1][j] =pre[1][j-1]*base+t[1][j];
		}
		
		for(int j=0;j<=len;j++){
			if(pre[0][j]!=pre[1][j])break;
			for(int k=1;k<=n;k++){
				if(L[k]+j>len)continue;
				
				if(get(0,j+L[k]+1,len)!=get(1,j+L[k]+1,len))continue;
				if(get(0,j+1,j+L[k])==hsh[0][k] && get(1,j+1,j+L[k])==hsh[1][k]){
					ans++;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}

