#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')	x = (x<<3) + (x<<1) + (c ^ 48),c = getchar();
	return x * f;
}
const int N = 5000005,P = 19260817,M = 4999999;
ll mi[N];
int n,T;
ll f[N],g[N];
ll h[N],H[N];
int len[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(),T = read();
	mi[0] = 1;
	for(int i = 1;i <= N - 5;i++)	mi[i] = mi[i-1] * P;
	for(int i = 1;i <= n;i++){
		string a,b;
		cin >> a >> b;
		len[i] = a.size();
		for(int j = 0;j < (int)a.size();j++){
			f[i] += (a[j] - 'a' + 1) * mi[j],g[i] += (b[j] - 'a' + 1) * mi[j];
		}
//		printf("%lld->%lld\n",f[i],g[i]);
	}
	while(T--){
		string a,b;
		cin >> a >> b;
		if(a == b){
			printf("0\n");
			continue;
		}
		int l,r,sz = a.size();
		for(l = 0;l < sz;l++)
			if(a[l]	!= b[l])	break;
		for(r = sz - 1;r >= 0;r--)
			if(a[r] != b[r])	break;
		for(int j = 0;j < (int)a.size();j++){
			if(j)	h[j] = h[j-1];
			else	h[j] = 0;
			h[j] += (a[j] - 'a' + 1) * mi[j];
		}
		for(int j = 0;j < (int)a.size();j++){
			if(j)	H[j] = H[j-1];
			else	H[j] = 0;
			H[j] += (b[j] - 'a' + 1) * mi[j];
		}
		int ans = 0;
		for(int i = 0;i < (int)a.size();i++){
			for(int k = 1;k <= n;k++){
				int j = i + len[k] - 1;
				if(j >= (int)a.size())	continue;
				if(i > l || j < r)	continue;
				ll h1 = h[j];
				if(i)	h1 -= h[i-1];
				ll h2 = H[j];
				if(i)	h2 -= H[i-1];
				if(h1 == f[k] * mi[i] && h2 == g[k] * mi[i])	ans++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}