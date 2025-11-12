#include <bits/stdc++.h>
using namespace std;
long long h;
int n,k;
int a[1000005];
bool ck(int x,int y){
	for(int i=x;i<=y;i++){
		if(a[i]==257) return 0;
	}
	return 1;
}
bool ch(int x,int y){
	int l=0;
	for(int i=x;i<=y;i++){
		l^=a[i];
	}
	if(l==k) return 1;
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			a[i]=257;
			h++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ch(i,j)&&ck(i,j)){
				h++;
				memset(a,257,sizeof((j-i)*8));
				break;
			}
		}
	}
	cout<<h;
	return 0;
}
