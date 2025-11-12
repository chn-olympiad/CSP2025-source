#include<bits/stdc++.h>
using namespace std;


const int N = 2e5+10;
struct node {
	int len;
	int from;
	int to;
	int chg;
} s[N];
char c[5000010];
char c1[5000010];
int n,q;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1; i<=n; i++) {
		scanf("%s",c+1);
		scanf("%s",c1+1);
//		cout<<c+1<<" "<<c1+1<<endl;
		int len = strlen(c+1);
		for(int j = 1; j<=len; j++) {
			if(c[j] == 'b') {
				s[i].from = j;
			}
			if(c1[j] == 'b') {
				s[i].to = j;
			}
		}
		s[i].len = len;
		s[i].chg = s[i].from-s[i].to;
	}
	int ans = 0;
	for(int i= 1; i<=q; i++) {
		scanf("%s",c+1);
		scanf("%s",c1+1);
		ans = 0;
		int len = strlen(c+1);
		int from,to;
		for(int j = 1; j<=len; j++) {
			if(c[j] == 'b') {
				from = j;
			}
			if(c1[j] == 'b') {
				to = j;
			}
		}
		
		int chg = from-to;			
		for(int j = 1;j<=n;j++){
			if(s[j].chg !=chg) continue;
			if(s[j].len<=len && s[j].len-from <= len-from && s[j].from<=from){
				ans++;
			}
		}
		
		printf("%d\n",ans);

	}






	fclose(stdin);
	fclose(stdout);
	return 0;
}
