#include <bits/stdc++.h>
#define MAXN 600
using namespace std;
int n,m,c[MAXN];
int d[MAXN],st;
void fastsort(int l,int r){//[l,r]
	if(l>r)return;
	if(r-l+1<=2){
		if(l==r)d[++st]=c[l];
		for(int i=1;i<=n;i++){
			swap(c[i],c[i+l]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			swap(c[i][j],c[j][i]);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	srand(time(0));
	cout<<(rand()*rand())%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

