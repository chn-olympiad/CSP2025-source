#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
char a[3000002],b[3000002],c[2500002],d[2500002];
int xa[200002],xb[200002];
int fdn(){
	int ansf=0;
	char* v=c;
	for(int i=0;i<n;i++){
		char* v=strstr(c,a+xa[i]);
		while(v!=0){
			bool f=1;
			for(int j=0;j<v-c;j++){
				if(c[j]!=d[j]){
					f=0;
					break;
				}
			}
			for(int j=0;a[xa[i]+j]!=0;j++){
				if(b[xb[i]+j]!=d[v-c+j]){
					f=0;
					break;
				}
			}
			int avg=strlen(a+xa[i]);
			for(int j=v-c+avg;c[j]!=0;j++){
				if(c[j]!=d[j]){
					f=0;
					break;
				}
			}
			if(f)ansf++;
			v=strstr(v+1,a+xa[i]);
		}
	}
	return ansf;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.ans","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		scanf("%s %s\n",&a[xa[i]],&b[xb[i]]);
		xa[i+1]=xa[i]+strlen(&a[xa[i]])+1;
		xb[i+1]=xb[i]+strlen(&b[xb[i]])+1;
	}
	for(int i=0;i<q;i++){
		scanf("%s %s\n",c,d);
		bool f=0;
		for(int i=0;;i++){
			if(c[i]==0&&d[i]==0){f=1;break;}
			if(c[i]==0||d[i]==0){printf("0\n");break;}
		}
		if(f){
			printf("%d\n",fdn());
		}
	}
	return 0;
}
