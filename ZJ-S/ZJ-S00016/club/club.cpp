#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
int t,n,a[100005],b[100005],c[100005],x[100005],s[100005],q[100005],sum,qwq;
vector<int> va,vb,vc;
bool cmp(int A,int B){
	return A<B;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(;t;t--){
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[i]=read();
			c[i]=read();
			x[i]=max(a[i],max(b[i],c[i]));
			if(x[i]==a[i]){
				s[i]=x[i]-max(b[i],c[i]);
				va.push_back(i);
			}
			else if(x[i]==b[i]){
				s[i]=x[i]-max(a[i],c[i]);
				vb.push_back(i);
			}
			else{
				s[i]=x[i]-max(a[i],b[i]);
				vc.push_back(i);
			}
		}
		int AA=va.size(),BB=vb.size(),CC=vc.size();
		for(int i=1;i<=n;i++){
			sum+=x[i];
		}
		if(AA>=BB && AA>=CC){
			for(int i=0;i<AA;i++){
				q[i]=s[va[i]];
			}
			qwq=AA;
		}
		else if(BB>=AA && BB>=CC){
			for(int i=0;i<BB;i++){
				q[i]=s[vb[i]];
			}
			qwq=BB;
		}
		else{
			for(int i=0;i<CC;i++){
				q[i]=s[vc[i]];
			}
			qwq=CC;
		}
		if(qwq>n/2){
			sort(q,q+qwq,cmp);
			for(int i=0;i<qwq-n/2;i++){
				sum-=q[i];
			}
		}
		cout<<sum<<endl;
		sum=0;
		va.clear();
		vb.clear();
		vc.clear();
		qwq=0;
		for(int i=0;i<=n+1;i++){
			a[i]=b[i]=c[i]=x[i]=s[i]=q[i]=0;
		}
	}
	return 0;
}
