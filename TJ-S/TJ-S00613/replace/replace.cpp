#include<bits/stdc++.h>
using namespace std; 

int n, q; 
struct node{
	string s1, s2; 
} s[200005];

int main(){
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout); 
	
	scanf("%d%d", &n, &q); 
	for(int i = 1; i <= n; i++) cin >> s[i].s1 >> s[i].s2; 
	
	while(q--){
		int sum = 0; 
		string t1, t2; 
		cin >> t1 >> t2; 
		if(t1.size() != t2.size()){
			printf("0\n"); 
			continue; 
		}
		int len = t1.size(); 
		int lft = INT_MAX, rgt = 0; 
		for(int i = 0; i < len; i++) if(t1[i] != t2[i]) lft = min(lft, i), rgt = max(rgt, i); 
		
		for(int i = 1; i <= n; i++){
			int ls = s[i].s1.size(); 
			//if(ls < rgt - lft + 1) continue; 
			// and j <= lft and j + ls - 1 >= rgt
			for(int j = 0; j + ls <= len; j++){
				if(t1.substr(j, ls) == s[i].s1){
					string ss = t1; 
					for(int k = 0; k < ls; k++){
						ss[j + k] = s[i].s2[k]; 
					}
					if(ss == t2) sum++; 
				}
				//cout << i << " " << sum << endl << endl;
				//sum += (t1.substr(j, ls) == s[i].s1 and t2.substr(j, ls) == s[i].s2); 
			}
		}
		
		printf("%d\n", sum); 
	}
	
	return 0; 
} 
