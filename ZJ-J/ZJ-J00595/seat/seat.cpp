#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int In[110];
int Seat[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&In[i]);
	}
	x=In[1];
	sort(In+1,In+n*m+1,[](const int x,const int y){
		return x>y;
	});
	int cnt=0,px=1,py=0;
	while(cnt<=n*m){
		if((py==m&&px%2==1)||(py==1&&px%2==0)){
			Seat[++px][py]=In[++cnt];
		}
		else{
			if(px%2==1){
				Seat[px][++py]=In[++cnt];
			}
			else{
				Seat[px][py--]=In[++cnt];
			}
		}
		if(Seat[px][py]==x){
			printf("%d %d",px,py);
			break;
		}
	}
	return 0;
}