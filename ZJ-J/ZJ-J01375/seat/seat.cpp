#include<bits/stdc++.h>
using namespace std;

const int N=15;

struct node{
	int val, id;
	bool operator<(const node &a)const{
		return val<a.val;
	}
	
	bool operator>(const node &a)const{
		return val>a.val;
	}
};

node a[N*N];

inline int rd(){
	int f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-f;
	int x=(c&15);while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+(c&15);
	return x*f;
};

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n=rd(),m=rd(),cnt=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		if(i==1)a[i].id=true;
	}
	sort(a+1,a+n*m+1,greater<node>());
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(a[cnt].id==1){
				cout<<m<<" "<<(m%2==0?n-j+1:j)<<endl;
				return 0;
			}
		}
	}
	return 0;
}
