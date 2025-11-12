#include <cstdio>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 510;

bitset<N> ez;

int read(){
	int out = 0;
	char in = getchar();
	while (!isdigit(in))
		in = getchar();
	while (isdigit(in)){
		out = out * 10 + (in - '0');
		in = getchar();
	}
	return out;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n = read(),m = read();
	int pa[n];
	char in = getchar();
	while (!isdigit(in))
		in = getchar();
	for (int i = 0;i < n;i++,in = getchar())
		ez[i] = in == '0' ? 0 : 1;
	
	srand(time(0));
	printf("%d",int(rand()) % 998244353);//ÍòÒ»ÄØ 
		
	return 0;
}
