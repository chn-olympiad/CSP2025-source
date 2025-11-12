#include<bits/stdc++.h>
using namespace std;
int n,q,ans,p1[200005]/*是否选*/;
string pp1,pp2,p[3][200005],cp[3][200005]/*备份*/,que[3][200005];
bool check(int a,string b,string c){
	for(int z=1;z<b.length();z++){
		if(c[a+z]!=b[z])return 0;
	} 
	return 1;
}
static void dfs(string x,string y){
	if(x==y){
		ans++;
		return;
	}
	for(int j=1;j<=n;j++){
		for(int k=0;k<x.length();k++){
			pp1=p[2][j];pp2=cp[1][j];
			/*判子串相等*/
			if(p1[j]==0&&x[k]==pp1[0]&&check(k,pp1,x)){
				p1[j]=1;
				for(int aa=k;aa<=p[1][j].length();aa++){
					x[aa]=pp1[aa];//[aa]//的子串;
				}
				dfs(x,y);
				p1[j]=0;
				for(int aa=k;aa<=p[1][j].length();aa++){
					x[aa]=pp2[aa];//[aa]//的子串;	
				}	
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>p[1][i]>>p[2][i];
	} 
	for(int i=1;i<=q;i++){
		cin>>que[1][i]>>que[2][i];
		cp[1][i]=que[1][i];
		cp[2][i]=que[2][i];
		/*备份*/
	} 
	for(int i=1;i<=q;i++){
		dfs(que[1][i],que[2][i]);
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 