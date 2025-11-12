#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int n,k,a[N],c,l[N],r[N],s,li;
bool b[N],f=1;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	for(int i=0; i<n; i++) {
		s=0;
		for(int j=i; j<n; j++) {
			int b1[20]={},b2[20]={},tmp=a[j],ss=0,jj=0;
			while(s>0) b1[ss++]=s%2,s/=2;
			while(tmp>0) b2[jj++]=tmp%2,tmp/=2;
			ss=max(ss,jj);
			for(int b=0; b<ss; b++)
				if(b1[b]==b2[b]) b1[b]=0;
				else b1[b]=1;
			for(int b=0; b<ss; b++) s+=b1[b]*pow(2,b);
			if(s==k) l[li]=i,r[li]=j,li++;
		}
	}
	for(int i=0; i<li; i++) {
		bool f=1;
		for(int j=l[i]; j<=r[i]; j++)
			if(b[j]) {
				f=0;
				break;
			}
		if(f) {
			c++;
			for(int j=l[i]; j<=r[i]; j++) b[j]=1;
		}
	}
	cout<<c;
	return 0;
}
