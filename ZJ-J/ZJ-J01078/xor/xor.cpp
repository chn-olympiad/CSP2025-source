#include<bits/stdc++.h>
using namespace std;
int n,k,m[100],d=0,r=0,z=0,y=0;
struct num{
	int s[100]={};
	int c=-1;
	int t=0;
	int w=0;
}a[500100];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		int e,b[100];
		scanf("%d",&e);
		while(e){
			b[++a[i].c]=e%2;
			e/=2;
		}
		for(int j=0,k=0;j<=a[i].c;j++){
			if(b[j]==1){
				a[i].s[k]=j;
				k++;
			}
		}
	}
	int f[100];
	while(k){
		f[d]=k%2;
		k/=2;
		d++;
	}
	for(int j=0,i=0;j<=d;j++){
		if(f[j]==1){
			m[i]=j;
			i++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			int e[100],x=0,k=1;
			for(k=0;k<20;k++){
				for(int q=j,v=1;v<=i;v++,q--){
					if(a[q].s[a[q].w]==k){
						x++;
					}
				}
				if(x%2==0&&m[y]==k || x%2==1&&m[y]!=k){
					break;
				}
				if(m[y]==k){
					k++;
				}
			}
			if(k==20){
			z=i;
			break;
			}
		}
	}
	cout<<z;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
