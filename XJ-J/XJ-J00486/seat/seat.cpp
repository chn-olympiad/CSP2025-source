#include <bits/stdc++.h>
using namespace std;
int c,r,n,a[510],id,p,l,h;//p£ºÅÅÃû 
bool cmp(int a,int b){
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> c >> r;n = c*r;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	id = a[1];
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i <= n;i++){
		if(a[i] == id){
			p = i;
		}
	}
	l = p/c+1;h = p%c;
	if(h == 0){
		h = c;
		l -= 1;
	}
	if(l % 2 == 0){
		h = c - h + 1;
	}
	cout << l << " " << h;
	return 0;
}
