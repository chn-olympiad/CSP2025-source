#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int b[1000000],c[100000],cnt1,cnt2,sum,n,m,k;
void dfs(int u,int v){
	
	for(int i=1;i<=n;i++){
		if(a[v][i]!=0){
			b[cnt1]=i;
			c[cnt2]=a[v][i];
			cnt1++;
			cnt2++;
			int d=0;
			for(int g=0;g<cnt1-1;g++){
				if(b[g]==b[cnt1-1]){
					int w=0,x=0;
					for(int j=0;j<cnt2;j++){
						if(w<c[j]){
							w=c[j];
							x=j;
						}
					}
					sum-=w;
					a[b[x]][b[x+1]]=0;
					a[b[x+1]][b[x]]=0;
					break;
				}
			}
			if(d==1)break;
			dfs(v,i);
			b[cnt1]=0;
			c[cnt2]=0;
			cnt1--;
			cnt2--;
		}
	}
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	for(int i=0;i<m;i++){
		int tep,tmp,temp;
		cin >>tep >>tmp >>temp;
		sum+=temp;
		a[tep][tmp]=temp;
		a[tmp][tep]=temp;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=0){
				b[0]=i;
				b[1]=j;
				c[1]=a[i][j];
				cnt1+=2;
				cnt2++;
				dfs(i,j);
				b[0]=0;
				b[1]=0;
				cnt1=0;
				cnt2=0;
			}
		}
	}
	cout <<sum;
	return 0;
}
