#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int num[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	k=n*m;
	for(int i=1;i<=k;i++){
		scanf("%d",&num[i]);
	}
	int s=num[1];
	sort(num+1,num+k+1,cmp);
	int seat;
	for(int i=1;i<=k;i++){
		if(num[i]==s){
			seat=i;
			break;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==seat){
					printf("%d %d",i,j);
					break;
				}	
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==seat){
					printf("%d %d",i,j);
					break;	
				}
			}
		}
	}
	return 0;
}
