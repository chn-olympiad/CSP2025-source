#include<bits/stdc++.h>
using namespace std;
int yh(int n,int m){
	return ((n|m)&~(n&m));
}
int n,k,a[20000][20000],c,l[1000000][3],ii;
bool f[20000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=i;j++){
			a[i][j]=yh(a[i-1][j],x);
			if(a[i][j]==k)l[++ii][0]=i-j+1,l[ii][1]=j,l[ii][2]=i;
		}
	}
	for(int i=1;i<ii;i++)
		for(int j=i+1;j<=ii;j++)
			if(l[i][0]>l[j][0])swap(l[i][0],l[j][0]),swap(l[i][1],l[j][1]),swap(l[i][2],l[j][2]);
	for(int i=1;i<=ii;i++){
		bool ff=1;
		for(int j=l[i][1];j<=l[i][2]&&f;j++)
			if(f[j])ff=0;
		if(ff){
			c++;
			for(int j=l[i][1];j<=l[i][2];j++)f[j]=1;
		}
	}
	cout<<c;
}
