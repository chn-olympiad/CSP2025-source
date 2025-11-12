//王铭轩-SN-S00530-陕西省安康中学
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std; 
const int N = 1e5+20;

int n,a[N][5],T,X,b1,b2,b3,ans;

void dfs(int x,int maxn){
	ans = max(ans,maxn);
	if(x>n) return ;
	ans = max(ans,maxn);
	if(b1<X){
		if(a[x][1]==0){
			if(b3>=X && b2<X){
				if(a[x][2]!=0){
					b2++; 
					dfs(x+1,maxn+a[x][2]);
					b2--;
				}
				else{
					b1++; 
					dfs(x+1,maxn+a[x][1]);
					b1--;
				}
			}
			else if(b3<X && b2>=X){
				if(a[x][3]!=0){
					b3++; 
					dfs(x+1,maxn+a[x][3]);
					b3--;
				}
				else{
					b1++; 
					dfs(x+1,maxn+a[x][1]);
					b1--;
				}
			}
			else{
					b1++; 
					dfs(x+1,maxn+a[x][1]);
					b1--;
			}
		}
		else{
			b1++; 
			dfs(x+1,maxn+a[x][1]);
			b1--;
		}
	} 
	if(b2<X){
		if(a[x][2]==0){
			if(b1>=X && b3<X){
				if(a[x][3]!=0){
					b3++; 
					dfs(x+1,maxn+a[x][3]);
					b3--;
				}
				else{
					b2++; 
					dfs(x+1,maxn+a[x][2]);
					b2--;
				}
			}
			else if(b1<X && b3>=X){
				if(a[x][1]!=0){
					b1++; 
					dfs(x+1,maxn+a[x][1]);
					b1--;
				}
				else{
					b2++; 
					dfs(x+1,maxn+a[x][2]);
					b2--;
				}
			}
			else{
				b2++; 
				dfs(x+1,maxn+a[x][2]);
				b2--;
			}
		}
		else{
			b2++; 
			dfs(x+1,maxn+a[x][2]);
			b2--;
		}
	} 
	if(b3<X){
		if(a[x][3]==0){
			if(b1>=X && b2<X){
				if(a[x][2]!=0){
					b2++; 
					dfs(x+1,maxn+a[x][2]);
					b2--;
				}
				else{
					b3++; 
					dfs(x+1,maxn+a[x][3]);
					b3--;
				}
			}
			else if(b1<X && b2>=X){
				if(a[x][1]!=0){
					b1++; 
					dfs(x+1,maxn+a[x][1]);
					b1--;
				}
				else{
					b3++; 
					dfs(x+1,maxn+a[x][3]);
					b3--;
				}
			}
			else{
				b3++; 
				dfs(x+1,maxn+a[x][3]);
				b3--;
			}
		}
		else{
			b3++; 
			dfs(x+1,maxn+a[x][3]);
			b3--;
		}
	} 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		b1=0,b2=0,b3=0,ans=0;
		
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		X = n/2;	//限制数
		
		dfs(1,0);
		
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
