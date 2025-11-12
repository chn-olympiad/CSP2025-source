#include<iostream>
#include<cstdio>
using namespace std;
int a,b,d[500005],ans=0;
bool d0[500005]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",&d[i]);
	} 
	for(int n=0;n<a;n++){
		for(int s=0;s<a-n;s++){
			int k=0;
			for(int i=s;i<=s+n;i++){
				k=k^d[i];
				if(d0[i]){
					k=-1;break;
				}
			}
			if(k==b){
				ans++;
				for(int i=s;i<=s+n;i++){
					d0[i]=1;
				}
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
