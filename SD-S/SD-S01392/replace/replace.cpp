#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1[1005],s2[1005],t,t_;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	if(n > 1000){
		while(q--)printf("0\n");
		return 0;
	}
	for(int i = 1;i<=n;i++)cin >> s1[i] >> s2[i];
	while(q--){
		cin >> t >> t_;
		if(t.length() != t_.length()){
			printf("0\n");
			continue;
		}
		int ans = 0;
		int l = t.size();
		for(int op = 1;op<=n;op++){
			int tq = s1[op].size();
			for(int i = 0;i<=l - tq + 1;i++){
				bool f = true;
				for(int j = i;j<=i + tq - 1;j++)if(t[j] != s1[op][j - i])f = false;
					if(f){
						bool ff = true;
						for(int ii = 0;ii<l;ii++){
							if((ii < i || ii > i + tq - 1) && t[ii] != t_[ii])f = false;
							if(!(ii < i || ii > i + tq - 1) && s2[op][ii - i] != t_[ii])f = false;
						}
					}
				if(f)ans++;
			}
				
		}
		printf("%d\n",ans);
	}
	return 0;
}//Ren5Jie4Di4Ling5%

