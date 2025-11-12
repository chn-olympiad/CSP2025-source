#include<iostream>
#include<algorithm>
using namespace std;
char a[1000005]={};
int b[1000005]={};
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int b=a[0],c=0;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			c=i+1;
			break;
		}
	}
	if(c%n==0){
		if(c/n%2==0){
			cout<<c/n<<' '<<1;
		}else{
			cout<<c/n<<' '<<n;
		}
		return 0;
	}
	if((c-1)/n%2==0){
		if(c/n%2==1){
			cout<<c/n+1<<' '<<n-c%n+1;
			return 0;
		}
		cout<<c/n+1<<' '<<c%n;
	}else{
		cout<<c/n+1<<' '<<n-c%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
