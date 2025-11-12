#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
int nxt[N][2],a[N][2],n,q,last[N],num[N][2],cov[N];
string s,s1,s2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin >> s;
		for(int j=0;j<s.size();j++)
		    a[last[i-1]+j+1][0] = s[j] - 'a' + 1;
		cin >> s;
		for(int j=0;j<s.size();j++)
		    a[last[i-1]+j+1][1] = s[j] - 'a' + 1;
		last[i] = last[i-1] + s.size();
	}
	for(int z=0;z<=1;z++)
		for(int i=1;i<=n;i++){
			int l = last[i-1] + 1,r = last[i];
			for(int j=l+1;j<=r;j++){
				int k = j-1;
				while(k >= l && a[nxt[k][z] + l][z] != a[j][z]) k = nxt[k][z] + l - 1;
				if(k == l-1){
					if(a[l] == a[j]) nxt[j][z] = 1;
				}
				else{
					if(a[nxt[k][z] + l][z] == a[j][z]) nxt[j][z] = nxt[k][z] + 1;
				}
				//cout<<"nxt: "<<nxt[j][z]<<" "<<j<<" "<<z<<endl;
			}
		}
	while(q --){
		int ans = 0,posl = 0,posr = 0,flag = 0;;
		cin >> s1 >> s2; int m = s1.size();
		if(s1.size() != s2.size()){
			puts("0"); continue;
		}
		for(int i=1;i<=m;i++)
			num[i][0] = s1[i-1] - 'a' + 1,num[i][1] = s2[i-1] - 'a' + 1;
		for(int i=1;i<=m;i++){
	    	if(num[i][0] != num[i][1]){
	    		if(posr){
	    			flag = 1; break;
				}
				else if(!posl) posl = i;
			}
			if(num[i][0] == num[i][1] && posl) posr = i - 1;
		}
		if(!posr) posr = m;
		if(flag){
			puts("0"); continue;
		}
		for(int i=1;i<=n;i++){
			for(int z=0;z<=1;z++){
			int l = last[i-1] + 1,r = last[i];
			int len = r - l + 1;
			if(r - l + 1 > m) continue;
			int tmp = l;
			for(int j=1;j<=m;j++){
				//cout<<"i: "<<i<<" "<<j<<" "<<z<<endl;
				if(num[j][z] == a[tmp][z]) ++ tmp;
				else{
					if(tmp > l) tmp = nxt[tmp-1][z] + l,j --;
				}
				if(tmp > r){
					if(cov[j] && posl >= j-len+1 && posr <= j){
						++ ans;
						}
					else cov[j] = 1;
					//cout<<"len: "<<len<<" "<<j<<endl;
				}
			}	
			}
			for(int j=1;j<=m;j++) cov[j] = 0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
