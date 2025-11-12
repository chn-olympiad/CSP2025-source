#include <bits/stdc++.h>

using namespace std;
string h;
int a[50000002],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> h;
	int u=h.size();
	for(int i=0;i<u;i++){
		if(h[i]>='0' && h[i]<='9'){
			a[n]=h[i]-48;
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) cout << a[i];
}
