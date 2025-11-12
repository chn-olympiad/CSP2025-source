#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef unsigned long long ull;
const int P=13331;
int n,q;
ull h(string x) {
	ull res=0;
	for(int i=0; i<x.size(); i++) {
		res=res*P+x[i]-'a';
	}
	return res;
}
vector<pair<ull,ull>> A;
ull p[N];
int main() {
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
 	
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=100000;i++){
		p[i]=p[i-1]*P;
	}
	for(int i=1; i<=n; i++) {
		string x,y;
		cin>>x>>y;
		A.push_back({h(x),h(y)});
	}
	while(q--) {
		int cnt=0;
		string t1,t2;
		int len=t1.size();
		t1="?"+t1;
		cin>>t1>>t2;
		ull t22=h(t2);
//		cout<<t1<<"???"<<t2<<"\n";
		cout<<A[1].first<<"a1a1a1a1"<<A[1].second;
		for(int i=1; i<=len; i++) {
			for(int j=i;j<=len;j++){
				cout<<i<<"   "<<j<<"\n";
				for(int k=0;k<A.size();k++){
					cout<<"k="<<k<<"\n";
					ull x=A[k].first;
					ull y=A[k].second;
					cout<<x<<"²âÊÔAÖÐ¹þÏ£"<<y<<"\n"; 
					if(h(t1.substr(i,j-i+1))==x){
						ull t11=y*p[len-j]+h(t1.substr(j+1))+h(t1.substr(1,i-1))*p[len-i];
						cout<<t11<<"²âÊÔÖÐ"<<t22<<"\n";
						if(t11==t22)cnt++;
					}
				}
			}
		}
		
		cout<<cnt<<"\n";
	}
}
