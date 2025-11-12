#include<bits/stdc++.h>
using namespace std;
int t,n;

int a[100010][5];
int c[100010];
int ch[100010];
int p[100010];
struct node{
	int ch,id;
}nu[5][100010];
bool cmp(node a,node b){
	if(a.ch==b.ch){
		return a.id<b.id;
	}else{
		return a.ch<b.ch;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&t);
	while(t--){

		scanf("%d",&n);
		int num=0;
		int n1=0,n2=0,n3=0;
		
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		
			
			if(a[i][1]>=max(a[i][2],a[i][3])){
				n1++;
				num+=a[i][1];
				c[i]=1;
				nu[1][n1].ch=a[i][1]-max(a[i][2],a[i][3]);
				if(a[i][2]>=a[i][3]){
					p[i]=2;
				}else{
					p[i]=3;
				}
			}else if(a[i][2]>=max(a[i][1],a[i][3])){
				n2++;
				num+=a[i][2];
				c[i]=2;
				nu[2][n2].ch=a[i][2]-max(a[i][1],a[i][3]);
				if(a[i][1]>=a[i][3]){
					p[i]=1;
				}else{
					p[i]=3;
				}
			}else if(a[i][3]>=max(a[i][1],a[i][2])){
				n3++;
				num+=a[i][3];
				c[i]=3;
				nu[3][n3].ch=a[i][3]-max(a[i][1],a[i][2]);
				if(a[i][1]>=a[i][2]){
					p[i]=1;
				}else{
					p[i]=2;
				}
			}
		}
		if(n1<=n/2&&n2<=n/2&&n3<=n/2){
			printf("%d\n",num);
	
			continue;
		}else{
			if(n1>n/2){
				sort(nu[1]+1,nu[1]+1+n1,cmp);
				for(int i=1;i<=n1-n/2;i++){
					num-=nu[1][i].ch;
				}
			}else if(n2>n/2){
				sort(nu[2]+1,nu[2]+1+n2,cmp);
				for(int i=1;i<=n2-n/2;i++){
					num-=nu[2][i].ch;
				}
			}else if(n3>n/2){
				sort(nu[3]+1,nu[3]+1+n3,cmp);
				for(int i=1;i<=n3-n/2;i++){
					num-=nu[3][i].ch;
				}
			}
			printf("%d\n",num);
		
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 