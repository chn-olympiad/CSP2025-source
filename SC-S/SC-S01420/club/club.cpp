#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct an{
	int id,l1,l2,l3,favor,n3,n2;
};
an a[N];
int my[N];
bool cmp(an i,an j){
	return i.l1<j.l1;
}
bool cmp1(an i,an j){
	if(i.n2!=j.n2){
		return i.n2>j.n2;
	}
	else return i.n3>j.n3;
}
void ans(int n){

	int a1=n,a2=0,a3=0,n3,n2,i;
	for(i=1;i<=n;i++){
		a[i].n2=a[i].l2-a[i].l1;
		a[i].n3=a[i].l3-a[i].l1;
	}
	sort(a+1,a+1+n,cmp1);
	i=1;
	while(a2<n/2&&a3<n/2){
		if(n2>=n3){
			a[i].favor=a[i].l2;
			a2++;
		}else{
			a[i].favor=a[i].l3;
			a3++;
		}
		i++;
	}	
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,m1=0,m2=0,m3=0,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		int cnt=0,j;
		cin>>n;
		for(j=1;j<=n;j++){
			a[j].id=j;
			cin>>a[j].l1>>a[j].l2>>a[j].l3;
		}
		for(int i=1;i<=n;i++) a[i].favor=a[i].l1;
		ans(n);
		for(int i=1;i<=n;i++) cnt+=a[i].favor;
		cout<<cnt<<endl;
	}
	return 0;
} 