#include <bits/stdc++.h>
using namespace std;
int t,n;
struct ddd{int a1,a2,a3;};
ddd b1[100005],b2[100005],b3[100005];
int l1,l2,l3;
bool cmp1(ddd a,ddd b){
	int x=max(a.a2-a.a1,a.a3-a.a1),y=max(b.a2-b.a1,b.a3-b.a1);
	return (x>y);
}
bool cmp2(ddd a,ddd b){
	int x=max(a.a1-a.a2,a.a3-a.a2),y=max(b.a1-b.a2,b.a3-b.a2);
	return (x>y);
}
bool cmp3(ddd a,ddd b){
	int x=max(a.a1-a.a3,a.a2-a.a3),y=max(b.a1-b.a3,b.a2-b.a3);
	return (x>y);
}
bool cmpa(ddd a,ddd b){
	return (a.a1>b.a1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for(int v=0;v<t;v++){
	l1=l2=l3=0;
	cin>>n;
	bool fa=1,fb=1;
	if(n<10000){fa=0;fb=0;}
	for(int i=0;i<n;i++){
		int d1,d2,d3;
		cin>>d1>>d2>>d3;
		if(d1>d2&&d1>d3){b1[l1].a1=d1;b1[l1].a2=d2;b1[l1].a3=d3;l1++;}
		else if(d2>d1&&d2>d3){b2[l2].a1=d1;b2[l2].a2=d2;b2[l2].a3=d3;l2++;}
		else if(d3>d1&&d3>d2){b3[l3].a1=d1;b3[l3].a2=d2;b3[l3].a3=d3;l3++;}
		else{b1[l1].a1=d1;b1[l1].a2=d2;b1[l1].a3=d3;l1++;}
	}
	if(l1>(n/2)){
		sort(b1,b1+l1,cmp1);
		int ll=l1;
		for(int i=0;ll>(n/2);i++){
			ddd a=b1[i];int x=a.a2-a.a1,y=a.a3-a.a1;
			if(x>y){
				b2[l2].a1=a.a1;b2[l2].a2=a.a2;b2[l2].a3=a.a3;l2++;
				b1[i].a1=b1[i].a2=b1[i].a3=0;ll--;
			}
			else{
				b3[l3].a1=a.a1;b3[l3].a2=a.a2;b3[l3].a3=a.a3;l3++;
				b1[i].a1=b1[i].a2=b1[i].a3=0;ll--;
			}
		}
		long long ans=0;
		for(int i=0;i<l1;i++){ans+=b1[i].a1;}
		for(int i=0;i<l2;i++){ans+=b2[i].a2;}
		for(int i=0;i<l3;i++){ans+=b3[i].a3;}
		cout<<ans<<endl;continue;
	}
	if(l2>(n/2)){
		sort(b2,b2+l2,cmp2);
		int ll=l2;
		for(int i=0;ll>(n/2);i++){
			ddd a=b2[i];int x=a.a1-a.a2,y=a.a3-a.a2;
			if(x>y){
				b1[l1].a1=a.a1;b1[l1].a2=a.a2;b1[l1].a3=a.a3;l1++;
				b2[i].a1=b2[i].a2=b2[i].a3=0;ll--;
			}
			else{
				b3[l3].a1=a.a1;b3[l3].a2=a.a2;b3[l3].a3=a.a3;l3++;
				b2[i].a1=b2[i].a2=b2[i].a3=0;ll--;
			}
		}
		long long ans=0;
		for(int i=0;i<l1;i++){ans+=b1[i].a1;}
		for(int i=0;i<l2;i++){ans+=b2[i].a2;}
		for(int i=0;i<l3;i++){ans+=b3[i].a3;}
		cout<<ans<<endl;continue;
	}
	if(l3>(n/2)){
		sort(b3,b3+l3,cmp3);
		int ll=l3;
		for(int i=0;ll>(n/2);i++){
			ddd a=b3[i];int x=a.a1-a.a3,y=a.a2-a.a3;
			if(x>y){
				b1[l1].a1=a.a1;b1[l1].a2=a.a2;b1[l1].a3=a.a3;l1++;
				b3[i].a1=b3[i].a2=b3[i].a3=0;ll--;
			}
			else{
				b2[l2].a1=a.a1;b2[l2].a2=a.a2;b2[l2].a3=a.a3;l2++;
				b3[i].a1=b3[i].a2=b3[i].a3=0;ll--;
			}
		}
		long long ans=0;
		for(int i=0;i<l1;i++){ans+=b1[i].a1;}
		for(int i=0;i<l2;i++){ans+=b2[i].a2;}
		for(int i=0;i<l3;i++){ans+=b3[i].a3;}
		cout<<ans<<endl;continue;
	}
	long long ans=0;
		for(int i=0;i<l1;i++){ans+=b1[i].a1;}
		for(int i=0;i<l2;i++){ans+=b2[i].a2;}
		for(int i=0;i<l3;i++){ans+=b3[i].a3;}
		cout<<ans<<endl;continue;
	}
	return 0;
}
