#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,a[500005];
bool b[500005];
struct node{
	int l,r,q;
};
vector<node> v;
bool cmp(node x,node y){
	return x.q>y.q;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int p=1,pp=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)p=0;
		if(a[i]!=0&&a[i]!=1)pp=0;
	}
	if(k==0&&p==1){
		cout<<n/2;
		return 0;
	}
	if(k==0&&pp==1){
		int kk=0;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]&&b[i]==0&&b[i-1]==0){
				kk++;
				b[i]=1;
				b[i-1]=1;
			}
		}
		cout<<kk;
		return 0;
	}
	if(k==1&&pp==1){
		int kk=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]&&b[i]==0&&b[i-1]==0){
				kk++;
				b[i]=1;
				b[i-1]=1;
			}
		}
		cout<<kk;
		return 0;
	}
	int sum;
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			for(int h=i+1;h<=j;h++){
				sum=a[h]^a[h-1];
			}
			if(sum==k){
				node c;
				c.l=i;
				c.r=j;
				c.q=0;
				v.push_back(c);
			}
		}
	}
	while(1){
		for(int i=1;i<v.size();i++){
			for(int j=i+1;j<=v.size();j++){
				if(v[i].r<=v[j].l){
					v[i].q++;
					v[j].q++;
				}
			}
		}
		sort(v.begin()+1,v.end()+1,cmp);
		if(v[1].q==0)break;
		v[1].q=0;
		v[1].l=0;
		v[1].r=0;
		sort(v.begin()+1,v.end()+1,cmp);
	}
	cout<<v.size();
	
	return 0;
} 
