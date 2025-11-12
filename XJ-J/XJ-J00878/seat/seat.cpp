#include<bits/stdc++.h> 
using namespace std;
int n,m,a[101],me,l=1,h=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x=n*m;
	for(int i=1;i<=x;i++)
		scanf("%d",&a[i]);
	me=a[1];
	sort(a+1,a+x+1);
	for(int i=x;i;i--){
		if(a[i]==me){
			printf("%d %d",l,h);
			return 0;
		}
		if(l%2==0){
			if(h>1)
				h--;
			else
				l++;
		}
		else{
			if(h+1<=n)
				h++;
			else
				l++;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
