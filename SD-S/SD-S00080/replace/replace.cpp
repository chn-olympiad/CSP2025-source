#include<bits/stdc++.h>
using namespace std;
int n,q;
struct jj{
	int z;
	string x,y;
}a[10001];
char s[2001],ss[2001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s,ss);
		a[i].z=strlen(s);
		a[i].x=s;
		a[i].y=ss;}
	while(q--){
		scanf("%s%s",s,ss);
		int nn=strlen(s);
		if(nn!=strlen(ss)){
			printf("0\n");
		}else{
			int l=0,r=0,gg=0,sum=0;
			for(int i=0;i<nn;i++){
				if(s[i]!=ss[i]){
					if(gg==0){
						l=i;
						gg=1;}
					r=i;
				}
			}
			for(int i=0;i<=l;i++){
				for(int j=1;j<=n;j++){
					if(r-i+1<=a[j].z&&i+a[j].z-1<nn){
						int xg=0;
						for(int k=i;k<i+a[j].z;k++){
							if(a[j].x[k-i]!=s[k]||a[j].y[k-i]!=ss[k]){
								xg=1;
								break;}
						}
						if(xg==0){
							sum++;
						}
					}
				}
			}
			printf("%d\n",sum);}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
