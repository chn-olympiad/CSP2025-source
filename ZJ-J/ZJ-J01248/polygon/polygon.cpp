#include<bits/stdc++.h>
using namespace std;
int n,a[5050],s;
bool flag=true;
bool cmp(vector<int> m){
	int q=0,w=0;
	for(int i=0;i<m.size();++i){
		q+=m[i];
		w=max(w,m[i]);
	}
	return q>w*2;
}
int f(int k){
	long long l=1;
	for(int i=1;i<=k;++i){
		l*=i;
		l%=998244353;
	}
	return l;
}
void func(vector<int> p,int t){
	if(p.size()>=3)s+=(cmp(p)?1:0);
	if(t>n)return;
	else{
		for(int i=t;i<=n;++i){
			vector<int> np(p.begin(),p.end());
			np.push_back(a[i]);
			func(np,i+1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1)flag=false;
	}
	if(flag){
		for(int i=3;i<=n;++i)s+=f(n)/f(n-i)/f(i);
		cout<<s;
	}else{
		vector<int> p;
		func(p,1);
		cout<<s;
	}
	return 0;
}
