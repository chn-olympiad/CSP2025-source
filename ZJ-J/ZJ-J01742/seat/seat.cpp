#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n*m;++i){
		if(a[1]<a[i]){
			cnt++;
		}
	}
	for(int i=1,j=1,flag=0;;){
		if(!cnt){
			printf("%d %d\n",j,i);
			break;
		}
		if(!flag){
			if(i==n){
				j++,flag=1;
			}
			else{
				i++;
			}
		}
		else{
			if(i==1){
				j++,flag=0;
			}
			else{
				i--;
			}
		}
		cnt--;
	}
	return 0;
}