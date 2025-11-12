#include<bits/stdc++.h>
using namespace std;
int n,m,k,o,l,r,h,a[1000];
string s;
void cop(int c,int d){
	m=a[c];
	a[c]=a[d];
	a[d]=m;
	for(int w=1;w<=n;w++){
		if(s[w-1]==1&&a[w]<l) h++;
		else l++;
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int w=1;w<=n;w++){
		if(s[w]==1&&a[w]<l) h++;
		else l++;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			cop(i,j);
			sort(a+1,a+1+n);
		}
	}
	cout<<h;
	return 0;
}
