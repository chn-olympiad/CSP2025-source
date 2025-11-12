#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,b,a) for(int i=(b);i>=(a);i--)
#define mem(a,b) memset(a,b,sizeof(a));

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1e6+5;
int tong[15];
char a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	rep(i,0,len-1){
		if('0'<=a[i]&&'9'>=a[i]){
			tong[a[i]-'0']++;
		}
	}
	pre(i,9,0){
		while(tong[i]>0){
			cout<<i;
			tong[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

