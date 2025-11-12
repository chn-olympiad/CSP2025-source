#include<bits/stdc++.h>
using namespace std;
struct student{
	int a1;
	int a2;
	int a3;
	int number;
	int favn;
	int favz;
	int n2;
	int z2;
	int n3;
	int z3;
	int cnt0;
}a[100005];
bool cmp(student x,student y){
	if(x.cnt0!=y.cnt0)return x.cnt0>y.cnt0;
	else if(x.favn!=y.favn)return x.favn>y.favn;
	else if(x.n2!=y.n2)return x.n2>y.n2;
	else if(x.n3!=y.n3)return x.n3>y.n3;
	else return x.number<y.number;
}
int z[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(z,0,sizeof(z));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].number=i;
			a[i].favn=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].favn==a[i].a1){
				a[i].favz=1;
				if(a[i].a2>=a[i].a3){
					a[i].n2=a[i].a2;
					a[i].z2=2;
					a[i].n3=a[i].a3;
					a[i].z3=3;
				}else{
					a[i].n2=a[i].a3;
					a[i].z2=3;
					a[i].n3=a[i].a2;
					a[i].z3=2;
				}
			}
			else if(a[i].favn==a[i].a2){
				a[i].favz=2;
				if(a[i].a1>=a[i].a3){
					a[i].n2=a[i].a1;
					a[i].z2=1;
					a[i].n3=a[i].a3;
					a[i].z3=3;
				}else{
					a[i].n2=a[i].a3;
					a[i].z2=3;
					a[i].n3=a[i].a1;
					a[i].z3=1;
				}
			}
			else{
				a[i].favz=3;
				if(a[i].a1>=a[i].a2){
					a[i].n2=a[i].a1;
					a[i].z2=1;
					a[i].n3=a[i].a2;
					a[i].z3=2;
				}else{
					a[i].n2=a[i].a2;
					a[i].z2=2;
					a[i].n3=a[i].a1;
					a[i].z3=1;
				}
			}
			a[i].cnt0=(a[i].a1==0)+(a[i].a2==0)+(a[i].a3==0);
		}sort(a+1,a+n+1,cmp);
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(z[a[i].favz]<(n+1)/2)sum+=a[i].favn,z[a[i].favz]++;
			else if(z[a[i].z2]<(n+1)/2)sum+=a[i].n2,z[a[i].z2]++;
			else sum+=a[i].n3,z[a[i].z3]++;
		}cout<<sum<<endl;
	}
	return 0;
}