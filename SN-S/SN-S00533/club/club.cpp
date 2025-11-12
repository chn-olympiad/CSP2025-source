#include<bits/stdc++.h>
using namespace std;
struct as{
	int a;
	int b;
	int c;
};
bool cmp(as x,as y){
	if(x.b>y.b)
		return true;
	return false;
}
int main(){
	long long d=0,sum,a1,b1,c1;
	as o[100000];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d;
		a1=0;
		b1=0;
		c1=0;
		sum=0;
		for(int k=0;k<d;k++){
			cin>>o[k].a>>o[k].b>>o[k].c;
		}
		sort(o,o+d,cmp);
		for(int k=0;k<d;k++){
			if(o[k].a>o[k].b && o[k].a>o[k].c && a1<=n/2){
				sum+=o[k].a;
				a1++;
			}else if(o[k].b>o[k].c && b1<=n/2){
				sum+=o[k].b;
				b1++;
			}else{
				sum+=o[k].c;
				c1++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
