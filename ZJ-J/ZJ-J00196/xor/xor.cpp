#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
map<int,vector<int> > b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=true,e=true;
	int t1=0;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=false;
		if(a[i]!=1&&a[i]!=0) e=false;
		if(a[i]==1) t1++;
		a[i]=a[i]^a[i-1];
		b[a[i]].push_back(i);
	}
	if(f){
		if(k==1){
			cout<<t1;
			return 0;
		}else if(k==0){
			cout<<t1/2;
			return 0;
		}
	}else if(e){
		if(k==1){
			cout<<t1;
			return 0;
		}else if(k==0){
			cout<<n-t1;
			return 0;
		}
	}else{
		int t=0,s=-1;
		for(int i=1;i<=n;i++){
			int z=k^a[i-1],si=b[z].size();
			if(si>0&&b[z].back()>=i){
				int bo=lower_bound(b[z].begin(),b[z].begin()+si,i)-b[z].begin();
				bo=b[z][bo];
				if(s==-1){
					t++;
					s=bo;
				}else if(bo<=s){
					s=bo;
				}else if(i>s){
					t++;
					s=bo;
				}
			}
		}
		cout<<t;
	}
	return 0;
}
