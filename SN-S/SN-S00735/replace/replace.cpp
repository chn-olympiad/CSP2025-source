#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string e[200010] = {};
	cin >>n>>q;
	map<string,string>m;
	for(int i=1;i<=n;i++){
		string a,b;
		cin >> a >> b;
		m[a] = b;
		e[i] = a;
	}
	if(q == 1){
		string a,b;
		cin >> a >> b;
		int sum = 0;
		while(a.length()){
			for(int j = 1;j <= n;j++){
				int f = a.find(e[j]);
				string c = "";
				if(f >= 0 && f <= a.length()){
					//构造新字符串 
					for(int l = 0;l < f;l++){
						c += a[l];
					}
					c += m[e[j]];
					for(int l = f + e[j].length();l < a.length();l++){
						c += a[l];
					}
					if(c == b)sum++;
				}
				for(int i = 0;i < a.length();i++){
					a[i] = a[i + f + e[j].length()];
				}
			}
		}
		printf("%d",sum);
		return 0;
	}
	for(int i = 1;i <= q;i++){
		string a,b;
		int sum =0;
		cin >> a >> b;
		for(int j = 1;j <= n;j++){
			int f = a.find(e[j]);
			string c = "";
			if(f >= 0 && f <= a.length()){
				//构造新字符串 
				for(int l = 0;l < f;l++){
					c += a[l];
				}
				c += m[e[j]];
				for(int l = f + e[j].length();l < a.length();l++){
					c += a[l];
				}
				if(c == b)sum++;
			}
		}
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
