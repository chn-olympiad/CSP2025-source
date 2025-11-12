#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,cnt;
struct Node{
	int x,id;
	bool operator <(const Node &B)const{return x>B.x;}
}a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cnt++;
		cin>>a[cnt].x;
		a[cnt].id=i;
	}
	sort(a+1,a+1+cnt);
	int k=0,x;
	for(int i=1;i<=cnt;i++){
		if(a[i].id==1){x=i;break;}
	}
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				k++;
				if(k==x){printf("%d %d\n",i,j);return 0;}
			}
		}else{
			for(int j=n;j>=1;j--){
				k++;
				if(k==x){printf("%d %d\n",i,j);return 0;}
			}
		}
	}
	return 0;
}