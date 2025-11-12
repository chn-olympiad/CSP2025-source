#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[202],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		
		scanf("%d",&a[i]);
		
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cnt=i;
			break;
		}
	}
	int l=cnt/n,t=cnt%n;
	if(t!=0){
		++l;
	}else{
		t=n;
	}
	if(l%2==0){
		t=n-t+1;
	}
	printf("%d %d",l,t);
    return 0;
}

