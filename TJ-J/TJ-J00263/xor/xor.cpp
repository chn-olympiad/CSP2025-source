#include<bits/stdc++.h>
using namespace std;
struct lr{
	long long l;
	long long r;
	long long zy;
};
lr aaa[50005];
long long n,k,a[50005],b[50005],z,aa=0;
void p(lr a[]){
	for(long long i=0;i<aa-1;i++){
		for(long long j=0;j<aa-1;j++){
			if(a[j].zy<a[j+1].zy){
				swap(a[j],a[j+1]);
			}
		}
	}
}
void bzd(){
	for(long long i=0;i<aa;i++){
		for(long long j=0;j<aa;j++){
			if(((aaa[i].l<=aaa[j].l&&aaa[i].r>=aaa[j].l)||(aaa[i].l<=aaa[j].r&&aaa[i].r>=aaa[j].r))&&!(i==j)){
				aaa[i].zy++;
			}
		} 
	}
	p(aaa);
	if(aaa[0].zy==0){
		return;
	}
	z--;	
	for(long long i=0;i<aa;i++){
		aaa[i]=aaa[i+1];
		aaa[i].zy=0;
	}
	aa--;
	bzd();
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(long long l=1;l<=n;l++){
		for(long long r=l;r<=n;r++){
			long long c=b[r]^b[l-1];
			if(c==k){
				aaa[aa].l=l;
				aaa[aa++].r=r;
				z++;
			}
		}
	}
	bzd();
	cout<<z;
	return 0;
}
