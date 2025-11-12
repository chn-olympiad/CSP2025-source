#include <bits/stdc++.h>
using namespace std;
int n,q;
int cnt=0;
string q1,q2;
string s1[200010],s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		cin >> q1 >> q2;
		int len=q1.length();
		int ll=q2.length();
		if(len!=ll){
			cout << "0\n";
			continue;
		}
		int st=0,ed=-1;
		for(int j=0;j<len;j++){
			if(q1[j]!=q2[j]){
				st=j;break;
			}
		}
		for(int j=len-1;j>=0;j--){
			if(q1[j]!=q2[j]){
				ed=j;break;
			}
		}
		for(int j=1;j<=n;j++){
			int k=0,l=s1[j].length();
			if(ed-st+1>l) continue;
			while(k<len){
				if(k+l>len) break;
				if(s1[j][0]==q1[k]){
					int ff=0;
					for(int z=k;z<k+l;z++){
						if(s1[j][z-k]!=q1[z]){ff=1;break;}
					}
					if(ff==0){
						if(k>st||k+l<ed){ff=1;break;}
						for(int z=k;z<k+l;z++){
							if(s2[j][z-k]!=q2[z]){ff=1;break;}
						}
					}
					if(ff==0) cnt++;
				}
				k++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
