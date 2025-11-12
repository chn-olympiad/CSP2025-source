//T4
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<string>
using namespace std;
const int MAXN = 505;
const int M = 998244353;
int fa[MAXN];
int n,m;
bool s[MAXN];
int c[MAXN];
bool A = 1;

int f(int i){
    if(fa[i]==-1) fa[i]=i*f(i-1)%M;
    return fa[i];
}

void pre(){
    memset(fa,-1,sizeof(fa));
    fa[0] = 1;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string ss;cin >> ss;
	for(int i=0;i<n;i++){
        s[i] = ss[i]-'0';
        A = A&&s[i];
	}
	for(int i=0;i<n;i++){
        cin >> c[i];
	}
	pre();
    if(A){
        cout << f(n);
        return 0;
    }
	return 0;
}
