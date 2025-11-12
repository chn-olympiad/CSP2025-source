#include<bits/stdc++.h>
using namespace std;
int n,m;
int p,q;
bool s[N];
int c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
	}
	p=n;
	q=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		if(c==0){
			p--;
			q++;
		} 
	}
	if(m>p+1){
		printf("0");
		return 0;
	}
	
	
	
	return 0;
}
