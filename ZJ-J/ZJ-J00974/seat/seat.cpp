#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[150],p;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	if((p/n)%2!=0){
		if(p%n!=0){
			cout<<(p/n)+1<<" "<<n-(p%n)+1;
		}else{
			cout<<p/n<<" "<<n;
		}
	}else{
		if(p%n!=0){
			cout<<(p/n)+1<<" "<<p%n;
		}else{
			cout<<p/n<<" "<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

