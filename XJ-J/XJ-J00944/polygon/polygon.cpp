#include<bits/stdc++.h>
using namespace std;

int n;
int l[6000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}
	if(n<=3){
		int w=max(l[1],l[2]);
		w=max(w,l[3]);
		if(l[1]+l[2]+l[3]>w*2){
			printf("%d",1);
		}else{
			printf("%d",0);
		}
	}
	return 0;
}
