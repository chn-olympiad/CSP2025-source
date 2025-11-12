#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int a[N];
int fun(int a,int b){
    int s=1,sum=0;
	while(s<=a||s<=b){
		s=s<<1;
	}
	int t1=0,t2=0;
	while(a||b){
		s=s>>1;
		t1=t2=0;
		if(a>=s){
			a-=s;
			t1=1;
		}
		if(b>=s){
			b-=s;
			t2=1;
		}
		if(t1!=t2){
			sum+=s;
		}
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int sum=a[1];
	for(int i=1,j=1;i<=n;j++){
		if(sum==m){
			cnt++;
			i=j+1;
			j=i;
			sum=a[i];
		}
		if(j>n){
			i++;
			j=i;
			sum=a[i];
		}
		if(i!=j)sum=fun(sum,a[j]);
	}
	cout<<cnt;
	return 0;
}
