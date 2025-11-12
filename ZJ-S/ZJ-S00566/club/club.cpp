#include<bits/stdc++.h>
using namespace std;
int t,n,m,n1,n2,n3;
struct r{
	int a1,a2,a3,st,b;
}a[100005];
bool cmp(r x,r y){
	int a[3],b[3];
	a[0]=x.a1;
	a[1]=x.a2;
	a[2]=x.a3;
	b[0]=y.a1;
	b[1]=y.a2;
	b[2]=y.a3;
	sort(a,a+3);
	sort(b,b+3);
	if(x.b==y.b){
		if(a[2]==b[2]){
			if(a[1]==b[1])return a[0]>b[0];
			else return a[1]>b[1];
		}return a[2]>b[2];
	};
	return x.b>y.b;
}
int main(){
	freopen("club4.in","r",stdin);
	freopen("club4.out","w",stdout);
	cin>>t;
	while(t--){
		long long sum=0;
		cin>>n;
		m=n/2;
		int n0=n;
		n1=0;n2=0;n3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int b1=abs(a[i].a1-a[i].a2);
			int b2=abs(a[i].a1-a[i].a3);
			int b3=abs(a[i].a2-a[i].a3);
			a[i].b=max(max(b1,b2),b3);
		};
		int k=1;
		sort(a+1,a+1+n,cmp);
		while(k<=n){
			if(a[k].a1>a[k].a2){
				if(a[k].a1>a[k].a3){
					if(n1<m){
					a[k].st=1;
					n1++;
					sum+=a[k].a1;}
					else if(a[k].a2>a[k].a3){
						a[k].st=2;
						n2++;
						sum+=a[k].a2;
					}else {
						a[k].st=3;
						n3++;
						sum+=a[k].a3;
					}
				}else{if(n3<m){
					a[k].st=3;
					n3++;
					sum+=a[k].a3;}
					else{
						a[k].st=1;
						n1++;
						sum+=a[k].a1;
					}
				}
			}
			else if(a[k].a2>a[k].a3){if(n2<m){
				a[k].st==2;
				n2++;
				sum+=a[k].a2;}
				else if(a[k].a1>a[k].a3){
						a[k].st=1;
						n1++;
						sum+=a[k].a1;
					}
					else{
						a[k].st=3;
						n3++;
						sum+=a[k].a3;
					}
			}
			else{if(n3<m){
				a[k].st==3;
				n3++;
				sum+=a[k].a3;}
				else{
						a[k].st=2;
						n2++;
						sum+=a[k].a2;
					}
			};
			k++;
			}cout<<sum<<endl;
		}
		
		return 0;
	}
