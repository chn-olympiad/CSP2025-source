#include<bits/stdc++.h>
#define ei else if
#define ll long long
#define pend cout<<endl
//alert to the problem of ambigiousness
using namespace std;

ll quick(ll a,ll b, ll modv) {
	
	ll re=1;
	a%=modv;
	while(b>0){
		
		if(b/2==1){
			re=(re*a)/modv;
			
		}
		a=(a*a)%modv;
		b/=2;
	}
	
	return re;
	
}
ll jiecheng(int a){
	int result=1;
	for(int i=1;i<=a;i++){
		result=(result*i)%998244353;
	}
	return result;
}



int n,ress=0;
int Li[5005];
int main(){
	
	
	freopen("polygon.in","r",stdin);//inputfre
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>Li[i];
	}
	if(n==3){
		if(Li[1]+Li[2]+Li[3]>2*max(Li[3],max(Li[1],Li[2]))){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	else{
		for(int i=3;i<=n;i++){
			ress=(ress%998244353)+((jiecheng(n)/(jiecheng(i)*jiecheng(n-i)))%998244353);
			
		}
		cout<<ress;
	}
	
	
	
	//output
	
	
	return 0;
}
