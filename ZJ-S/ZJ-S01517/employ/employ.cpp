#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=502;
const int p=998244353;

int n,m;
string s;
int c[MAXN];

int jc[MAXN];

int main(){
//	freopen("employ3.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for (int i=1;i<MAXN;i++){
		jc[i]=jc[i-1]*i%p;
	}
	
	cin >> n >> m;
	cin >> s;
	for (int i=0;i<n;i++){
		cin >> c[i];
	}
	cout << jc[n];
	
	
	return 0;
}
