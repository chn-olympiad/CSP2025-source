#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,a[N],b[N];
string s;
void merge(int l,int r){
	if(l>=r) return;
	int mid=l+(r-l)/2;
	int i=l,j=mid+1,tot=l;
	while(i<=mid&&j<=r){
		if(a[i]>=a[j]){
			b[tot++]=a[i];
			i++;
		}
		else{
			b[tot++]=a[j];
			j++;
		}
	}
	while(i<=mid){
		b[tot++]=a[i];
		i++;
	}
	while(j<=r){
		b[tot++]=a[j];
		j++;
	}
	for(int x=l;x<=r;++x){
		a[x]=b[x];
	}
}
void mergesort(int l,int r){
	if(l<r){
		int mid=l+(r-l)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,r);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[++n]=s[i]-'0';
		}
	}
	mergesort(1,n);
	for(int i=1;i<=n;++i) cout<<a[i];
	return 0;
}

