#include <bits/stdc++.h>
using namespace std;
char s[5200010],s2[5200010];
int st[200010],len,f[5200010],ff[5200010];
int hsa[5200010],hsb[5200010];
char a[5200010],b[5200010];
int n,q,pre,suf;
void mkfail(int l,int r){
	f[l] = l - 1;
	for(int i = l + 1,j = l - 1; i <= r; i++){
		while(j != l - 1 && s[i] != s[j + 1])j = f[j];
		if(s[i] == s[j + 1])j++;
		f[i] = j;
		//cout << i << " " << f[i] << endl;
	}
	ff[l] = l - 1;
	for(int i = l + 1,j = l - 1; i <= r; i++){
		while(j != l - 1 && s2[i] != s2[j + 1])j = ff[j];
		if(s2[i] == s2[j + 1])j++;
		ff[i] = j;
	}
}
int mkmp(int x){
	int l = st[x],r = st[x + 1] - 2,cnt = 0;
	int lens = r - l + 1;
	//cout << l << " " << r << endl;
	for(int i = 1,j = l - 1,jj = l - 1; i <= len; i++){
		while(j != l - 1 && a[i] != s[j + 1])j = f[j];
		if(a[i] == s[j + 1])j++;
		while(jj != l - 1 && b[i] != s2[jj + 1])jj = ff[jj];
		if(b[i] == s2[jj + 1])jj++;
		//cout << j << " " << jj << " " << i << endl;
		if(j == r && jj == r && i - lens + 1 <= pre + 1 && i >= suf - 1)cnt++;
		if(j == r)j = f[j];
		if(jj == r)jj = ff[jj];
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	st[1] = 1;
	for(int i = 1; i <= n; i++){
		scanf("%s",s + st[i]);
		st[i + 1] = st[i] + strlen(s + st[i]) + 1;
		scanf("%s",s2 + st[i]);
	}
	for(int i = 1; i <= n; i++)mkfail(st[i],st[i + 1] - 2);
	for(int i = 1; i <= q; i++){
		scanf("%s",a + 1);
		scanf("%s",b + 1);
		len = strlen(a + 1);
		pre = 0,suf = len + 1;
		while(pre < len && a[pre + 1] == b[pre + 1])pre++;
		while(suf > 1 && a[suf - 1] == b[suf - 1])suf--;
		//for(int i = 1; i <= len; i++)cout << a[i];
		//cout << endl;
		if(len != strlen(b + 1)){
			printf("0\n");
			continue;
		}
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			//cout << i << " " << j << " " << n << endl;
			cnt += mkmp(j);
		}
		printf("%d\n",cnt);
	}
	return 0;
}