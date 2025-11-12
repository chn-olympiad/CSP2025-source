//吴启豪 - SN-J00188 - 西安滨河学校 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,r,c;
struct xm{
	int f;
	bool x;
}a[110];
bool cmp(xm a,xm b){
	return a.f>b.f;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].x=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
	}
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].f<<"\n";
//	}
	int i=0;r=0,c=1;
//	cout<<n<<m;
	
	while(a[i].x!=1){
		i++;
		if(r<m&&c%2==1){
			r++;
		}else if(r>1&&c%2==0){
			r--;
		}else if(c%2==1){
			r=n;
			c++;
		}else{
			r=1;
			c++;
		}
	//	printf("c:%d\tr:%d\ta[i].x:%d\n",c,r,a[i].x);
	}
	cout<<c++<<" "<<r++;
	return 0;
}
