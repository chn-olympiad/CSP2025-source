#include<bits/stdc++.h>;
using namespace std;
int n,m,a[100010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int ke=a[1],k;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ke){
			k=i;
			break;
		}
	}
	int l=1,h=1;
	for(int i=1;i<k;i++){
		cout<<l<<" "<<h<<endl;
		if((h==n&&l%2==1)||(h==1&&l%2==0)) l++;
		else if(l%2==1) h++;
		else if(l%2==0) h--;
	}
	printf("%d %d",l,h);
	return 0;
} 
