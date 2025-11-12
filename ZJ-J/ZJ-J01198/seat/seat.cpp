#include<iostream>
#include<algorithm>
using namespace std;
int a,b,s[105],s1;
bool cmp(int q,int h){
	if(q!=h)return q>h;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&a,&b);
	scanf("%d",&s[0]);
	s1=s[0];
	for(int i=1;i<a*b;i++){
		scanf("%d",&s[i]);
	}
	sort(s,s+a*b,cmp);
	for(int i=0;i<a*b;i++){
		if(s[i]==s1){
			printf("%d %d",i/b+1,i%a+1);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

