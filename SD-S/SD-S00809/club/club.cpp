#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long t,n,o,nn,n1,n2,n3;
struct d{
	long long d1,d2,d3,mx;
	int m1,m2,m3,m4;
};
//bool c(d q,d w){
//	return max(q.d1,max(q.d2,q.d3))>max(w.d1,max(w.d2,w.d3));
//}
bool c(d q,d w){
	return q.d1*q.d2*q.d3<w.d1*w.d2*w.d3
	||((q.d1*q.d2*q.d3==w.d1*w.d2*w.d3)
	&&q.mx>w.mx);
//	&&q.d1+q.d2+q.d3>w.d1+w.d2+w.d3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	do{
		cin>>n;
		nn=n/2;
		o=n1=n2=n3=0;
		vector<d>a(n);
		for(auto&i:a){
			cin>>i.d1>>i.d2>>i.d3;
			if(i.d1>=i.d2&&i.d2>=i.d3){
				i.m1=1;
				i.m2=2;
				i.m3=3;
				i.mx=i.d1;
			}
			if(i.d1>=i.d3&&i.d3>=i.d2){
				i.m1=1;
				i.m2=3;
				i.m3=2;
				i.mx=i.d1;
			}
			if(i.d2>=i.d1&&i.d1>=i.d3){
				i.m1=2;
				i.m2=1;
				i.m3=3;
				i.mx=i.d2;
			}
			if(i.d2>=i.d3&&i.d3>=i.d1){
				i.m1=2;
				i.m2=3;
				i.m3=1;
				i.mx=i.d2;
			}
			if(i.d3>=i.d1&&i.d1>=i.d2){
				i.m1=3;
				i.m2=1;
				i.m3=2;
				i.mx=i.d3;
			}
			if(i.d3>=i.d2&&i.d2>=i.d1){
				i.m1=3;
				i.m2=2;
				i.m3=1;
				i.mx=i.d3;
			}
		}
		sort(a.begin(),a.end(),c);
		for(auto&i:a){
			if(i.m1==1&&n1<nn){
				++n1;
				o+=i.mx;
				continue;
			}
			if(i.m1==2&&n2<nn){
				++n2;
				o+=i.mx;
				continue;
			}
			if(i.m1==3&&n3<nn){
				++n3;
				o+=i.mx;
				continue;
			}
			if(i.m2==1&&n1<nn){
				++n1;
				o+=i.d1;
				continue;
			}
			if(i.m2==2&&n2<nn){
				++n2;
				o+=i.d2;
				continue;
			}
			if(i.m2==3&&n3<nn){
				++n3;
				o+=i.d3;
				continue;
			}
			if(i.m3==1&&n1<nn){
				++n1;
				o+=i.d1;
				continue;
			}
			if(i.m3==2&&n2<nn){
				++n2;
				o+=i.d2;
				continue;
			}
			if(i.m3==3&&n3<nn){
				++n3;
				o+=i.d3;
				continue;
			}
		}
		cout<<o<<'\n';
	}while(--t);
	return 0;
}
