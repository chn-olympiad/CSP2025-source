#include<stdio.h>
inline void read(int &x){
	x = 0;
	char c;
	bool f = 0;
	do{
		c = getchar();
		if(c=='-') f = 1;
	}while(c<'0'||'9'<c);
	while('0'<=c && c<='9'){
		x *= 10;
		x += c - '0';
		c = getchar();
	}
	if(f) x = -x;
}

constexpr int MAXN = 505;

bool x[MAXN];
inline void read2(){
	char c;
	do{
		c = getchar();
	} while(c<'0'||'1'<c);
	int cnt = 1;
	while(c=='0' || c=='1'){
		x[cnt++] = (c=='0');
		c = getchar();
	}
}

int p[MAXN];	// patience

#include<algorithm>
using std::next_permutation;
int a[MAXN];

int main(){
	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n, m;
	read(n); read(m);
	read2();
	for(int i = 1; i <= n; i++){	//  is for n<10
		read(p[i]);
		a[i] = i;
	}
	
	int ans = 0;
	do{
		int refused = 0;
		int employed = 0;
//		for(int i=1;i<=n;i++){
//			printf("%d ",a[i]);
//		}putchar('\n');
		for(int i=1;i<=n;i++){		// i -> days
			if((x[i]) || (refused>p[a[i]])){
				refused++;
			}
			else employed++;
		}
//		printf("%d\n\n\n\n",employed);
		if(employed >= m){
			ans++;
		}
	}while(next_permutation(a+1,a+n+1));
	printf("%d\n",ans);
	return 0;
}