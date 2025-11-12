#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0' || '9'<ch){
		if(ch == '-') f=-1;
		ch = getchar();
	}
	while('0'<=ch && ch<='9'){
		x = (x<<3)+(x<<1)+ch-'0';
		ch = getchar();
	}
	return x*f;
}
const int N=1e5+10;
int T,n,a[5][N];
int red[N];
int hav1[N],hav2[N],hav3[N];
int cnt[5];
ll ans = 0;
inline void init(){
	cnt[1] = cnt[2] = cnt[3] = 0;
	ans = 0;
}
inline void addin(int nm,int i){
	if(nm == 1) hav1[++cnt[1]] = red[i];
	else if(nm == 2) hav2[++cnt[2]] = red[i];
	else hav3[++cnt[3]] = red[i];
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++){
			a[1][i] = read(),a[2][i] = read(),a[3][i] = read();
		}
		init();
		for(int i=1;i<=n;i++){
			int mxnm = 1;
			if(a[mxnm][i] < a[2][i]) mxnm = 2;
			if(a[mxnm][i] < a[3][i]) mxnm = 3;
			//printf("i=%d,mxnm=%d\n",i,mxnm);
			ans += a[mxnm][i];
			
			if(mxnm == 1) red[i] = abs(a[1][i] - max(a[3][i],a[2][i]) );
			else if(mxnm == 2) red[i] = abs(a[2][i] - max(a[1][i],a[3][i]));
			else red[i] = abs(a[3][i] - max(a[1][i],a[2][i]));
			//printf("red[%d]=%d\n",i,red[i]);
			
			addin(mxnm,i);//预处理出每个会怎样减少  
		}
		sort(hav1+1,hav1+cnt[1]+1);
		sort(hav2+1,hav2+cnt[2]+1);
		sort(hav3+1,hav3+cnt[3]+1);
		
		if(cnt[1] > (n/2)){
			//printf("cnt[%d] = %d\n",1,cnt[1]);
			for(int i=1;i<=cnt[1]-(n/2);i++) ans -= hav1[i];
		}else if(cnt[2] > (n/2)){
//			printf("cnt[%d] = %d\n",2,cnt[2]);
//			for(int i=1;i<=cnt[2];i++) cout<<hav2[i]<<" ";
//			cout<<"\n";
			for(int i=1;i<=cnt[2]-(n/2);i++) ans -= hav2[i];
		}else{
			//printf("cnt[%d] = %d\n",3,cnt[3]);
			for(int i=1;i<=cnt[3]-(n/2);i++) ans -= hav3[i];
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}

