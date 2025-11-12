#include<bits/stdc++.h>
using namespace std;

struct node{
	int left,right;
}q[100010];
int n,k,a[100010],len,mx;

int Xor(int l,int r){
	int cnt=0;
	for(int i=l;i<=r;i++){
		cnt^=a[i];
	}
	return cnt;
}
bool cmp(node x,node y){
	if(x.right!=y.right)
		return x.right<y.right;
	else
		return x.left>y.left;
}
void s1(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(Xor(i,j)==k){
				q[len].left=i;
				q[len++].right=j;
			}
		}
	}
}
void s2(){
	int now;
	sort(q,q+len,cmp);
	if(q[0].right>=1){
		mx++;
		now=q[0].right;
	}
	else{
		mx=0;
		return;
	}
	
	for(int i=1;i<len;i++){
		if(q[i].left>now){
			mx++;
			now=q[i].right;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s1();
	s2();
	cout<<mx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
