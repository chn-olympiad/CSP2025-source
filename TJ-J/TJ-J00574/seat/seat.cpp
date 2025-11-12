#include<iostream>
using namespace std;
int ggg(int a,int b){
	double c=(double)a/b;
	if(c>a/b){
		return (int)c+1;
	}
}
int main(){
	int n,m,cj,ls,ans=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>cj;
	for(int i=0;i<n*m-1;i++){
		cin>>ls;
		if(ls>=cj){
			ans++;
		}
	}
	int e=ggg(ans,n);
	cout<<e<<" ";
	if(e%2==1){
		cout<<ans-e*n+n<<endl;
	}else{
		cout<<n-(ans-e*n+n)+1<<endl;
	}
	return 0;
}
