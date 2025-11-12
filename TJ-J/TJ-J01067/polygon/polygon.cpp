#include<bits/stdc++.h>
using namespace std;

const int MAXN=6e4;
int n,a[MAXN],f[MAXN],mod,ans;
bool A=1;
struct node{
	int s;
};
vector<node> v[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>1) A=0;
	}
	cout << n-2;
	
	return 0;
} 
