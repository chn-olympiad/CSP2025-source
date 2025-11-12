#include<bits/stdc++.h>
using namespace std;
string q(int u){
	string ans,m;
	while(u>0){
		int y=u%2;
		ans+=(y+'0');
		u/=2;
	}
	for(int i=ans.size()-1;i>0;i--){
		m+=ans[i];
	}
	return m;
}
string x(string f,string h){
	for(int i=0;i<f.size();i++){
		if(f[i]==h[i]){
			f[i]=0;
		}
	}
	return f;
}
int w(string o){
	int g=1,num=0;
	for(int i=0;i<o.size();i++){
		num+=g*(o[i]-'0');
		g*=2;
	}
	return num;
}
int main(){
	int n,k,a[500005],maxes=-(1e9);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=i;k<=j;k++){
				if(w(x(q(a[i]),q(a[k])))==k){
					if(fabs(i-j)>maxes){
						maxes=fabs(i-j);
					}
				}
			}
		}
	}
	cout<<maxes;
	return 0;
}

