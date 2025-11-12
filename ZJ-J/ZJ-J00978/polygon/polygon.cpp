#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[5005],cnt=0;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt=cnt+a[i];
		if(a[i]<maxx)maxx=a[i];
	}
	if(n<=3){
		if(n<3) printf("0");
		else if(cnt>maxx*2)printf("1");
		else printf("0");		
	}
	else{
		cout<<10;
	}
	return 0;
}
