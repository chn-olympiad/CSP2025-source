#include<bits/stdc++.h>
using namespace std;
const int _mod=998244353;
int n,a[21],s;
void f(int,int,int);
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		f(i,0,0);
		s%=_mod; 
	} 
	printf("%d",s);
	return 0;
}
void f(int p,int q,int l) {
	int ll=0;
	for(int i=q+1;i<=n;i++){
		ll=a[i];
		if(p==q){
			if(l>ll){
				s++;
			}
			continue;
		}
		f(p,i,l+ll);
	}
	return;
}

