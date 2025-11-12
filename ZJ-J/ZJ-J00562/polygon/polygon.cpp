#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+7;
int a[N],b[N];
vector <int > num;
int len=0;
ll sum=0;
ll jc(int n){
	ll x=1;
//	printf("jc.%d ",n);
	while(n--){
//		printf("%d ",x);
		x*=n;
	}
//	printf("\n");
	return x;
}
ll C(int n,int m){
//	printf("C.%d %d\n",n,m);
	if(m==0) return 1;
	return jc(n)/jc(m)/jc(n-m);
}
void f(ll n, int i, ll mxx, ll cnt, int sl){
//	printf("%lld %d %lld %lld %d\n",n,i,mxx,cnt,sl);
	if(i>n) {
		if(sl<3) return;
		if(cnt<=(mxx<<1)){
			return;
		}
		ll ans=1;
		for(int j=1;j<=n;j++){
//			printf("ans\n");
			ans*C(a[num[j]],b[num[j]]);
		}
		sum+=ans;
		return;
	}
	int ans=0;
	for(int j=0; j<=a[num[i]]; j++){
//		printf("%lld %d %lld %lld %d %d\n",n,i,mxx,cnt,sl,j);
		f(n,i+1,(j==0 ? mxx : num[i]),cnt+j*num[i],sl+j);
	}
	return;
}

int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	num.push_back(-1);
	for(int i=1;i<=n;i++){
		int ls;cin>>ls;
		if(!a[ls]) num.push_back(ls),len++;
		a[ls]++;
	}
	sort(num.begin(),num.end());
	f(len,1,-1,0,0);
//	cout<<1<<endl;
	cout<<sum<<endl;
	return 0;
}
