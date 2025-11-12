#include <bits/stdc++.h>
using namespace std;
int n , q; 
std::string strx[200100];
std::string stry[200100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; ++ i){
		std::cin >> strx[i] >> stry[i];
	}
	while(q --){
		std::string t1, t2;
		std::cin >> t1 >> t2;

		if(t1.size() != t2.size()){
			puts("0");
			continue;
		}
		int stl = t1.size();
		int l = 0 , r = 0;
		for(int j = 0 ; j < stl ; ++ j){
			if((t1[j] != t2[j])){
				l = j ; break;
			}
		}
		for(int j = stl - 1; j >= 0 ; -- j){
			if((t1[j] != t2[j])){
				r = j ; break;
			}
		}
	
		std::string aa,ab;
		for(int i = l ; i <= r ; ++ i){
			aa.push_back(t1[i]);
			ab.push_back(t2[i]);
		}
		
		int ans = 0;
		for(int i = 1 ; i <= n ; ++ i){
			int stl2 = strx[i].size();
			for(int j = 0 ; j <= (stl2-1-(r-l)) ; ++ j){
				bool flag = true;
				for(int k = j ; k <= j + (r - l) ; ++ k){
					if(aa[k-j] != strx[i][k] || ab[k-j] != stry[i][k]){
					flag = false;
					break;}
				}
				
				if(flag){
					bool flag2 = false;
					std::string strtx = strx[i],strty = stry[i];
					for(int k = j ; k <= j + (r - l) ; ++ k){
						strtx[k] = '.';
						strty[k] = '.';
					}
					for(int k = 0 ; k < j ; ++ k){
						if(strtx[k]!=strty[k])flag2 = true;
					}
					for(int k = j+(r-l)+1 ; k < stl2 ; ++ k){
						if(strtx[k]!=strty[k]){
							flag2 = true;
						}
					}
					if(!flag2){
						ans ++ ;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
// WHAT'S THIS

