#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int inf=0x3f3f3f3f3f;
int n,m;
int a[N];
bool cmp(int q,int w){
	return q>w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//don't forget to delete the '//' 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int now=a[1],k;
	//cout<<now<<endl;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=len;i++){
		if(a[i]==now) k=i;
	}
	//cout<<k<<endl;
	int x=k/m+1,p=k%m;
	//cout<<k<<"%"<<m<<"="<<p<<endl; 
	if(p==0) p=m,x--;
	//cout<<x<<" "<<m<<endl;
	if(x%2==1){
		cout<<x<<" "<<p<<endl;
	}else{
		cout<<x<<" "<<(m-p+1)<<endl;
	}
	return 0;	
}
