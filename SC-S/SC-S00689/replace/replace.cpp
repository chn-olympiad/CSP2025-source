#include<bits/stdc++.h>
using namespace std;
int n,m,k,lenn=0,ans=0;
int w[10005],e[10005];
struct node{
	int i,j,k;
} a[1000005];
int b[10005];
bool my(node q,node w){
	return q.k<w.k;
}
int pp(int ww){
	if(b[ww]==ww) return ww;
	b[ww]=pp(b[ww]);
	return b[ww];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cout<<m;
	return 0;
	fclose(stdin);
	fclose(stdout);
}