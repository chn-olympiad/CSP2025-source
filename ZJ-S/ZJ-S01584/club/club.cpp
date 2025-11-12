#include <bits/stdc++.h>
using namespace std;

struct nums{
    int a1;
    int a2;
    int a3;
    int member;
};



    int t;
    int n;
    int p;
    
    int cx,cm,s;
    
int main(){
	
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    
    for (int i = 0;i < t;i++){
        
        scanf("%d",&n);
        
        vector<nums*> a(n); 

        for (int j = 0;j < n;j++){
            a[j] = new nums();
            scanf("%d",&a[j]->a1);
            scanf("%d",&a[j]->a2);
            scanf("%d",&a[j]->a3); 
            a[j]->member = j;
        }
		
		vector<nums*> n1 = a;
		vector<nums*> n2 = a;
		vector<nums*> n3 = a;
		vector<int> num(n,0);
		
        for (int j = 0;j < n - 1;j++){
			for (int k = j+1;k < n;k++){
				if (n1[j]->a1 < n1[k]->a1) swap(n1[j],n1[k]);
			}
		}
		for (int j = 0;j < n - 1;j++){
			for (int k = j+1;k < n;k++){
				if (n2[j]->a2 < n2[k]->a2) swap(n2[j],n2[k]);
			}
		}
		for (int j = 0;j < n - 1;j++){
			for (int k = j+1;k < n;k++){
				if (n3[j]->a3 < n3[k]->a3) swap(n3[j],n3[k]);
			}
		}
        n1.push_back(0);
        n2.push_back(0);
        n3.push_back(0);
        vector<bool> mem(n,true);
		
		//p = n3[n - 1]->a3;
		
        int j1 = 0,j2 = 0,j3 = 0;
        
        vector<int> c1;
		vector<int> c2;
		vector<int> c3;
		vector<int> cn1;
		vector<int> cn2;
		vector<int> cn3;
    
        for (int j = 0;j < n * 3;j++){
			int x;
			int m;
			int c = 0;
			
			
			if(n1[j1]->a1 >= n2[j2]->a2 && n1[j1]->a1 >= n3[j3]->a3 && j1 < n) {
				m = n1[j1]->member;
				x = n1[j1]->a1;
				c = 1;
				j1 = min(n-1,j1+1);
			}else if(n2[j2]->a2 >= n1[j1]->a1 && n2[j2]->a2 >= n3[j3]->a3 && j2 < n){
				m = n2[j2]->member;
				x = n2[j2]->a2;
				c = 2;
				j2 = min(n-1,j2+1);
			}else{
				m = n3[j3]->member;
				x = n3[j3]->a3;
				c = 3;
				j3 = min(n-1,j3+1);
			}
			if(mem[m]){
				mem[m] = false;
				if(c == 1){
					//cout << 1 << j << endl;
					if ((int)c1.size() < n/2) {c1.push_back(x);cn1.push_back(m);}
					else {
						s = cn1.back();
						if(a[s]->a2 > a[s]->a3){
							cx = a[s]->a2;
							cm = 2;
						}else{
							cx = a[s]->a3;
							cm = 3;
						}
						if ((c1.back() - cx)<= x){
							c1.pop_back();
							cn1.pop_back();
							if (cm == 2) {c2.push_back(cx);cn2.push_back(s);}
							if (cm == 3) {c3.push_back(cx);cn3.push_back(s);}
							c1.push_back(x);
							cn1.push_back(m);
						}
						
					}
				}else if(c == 2){
					//cout << 2 << j << endl;
					if ((int)c2.size() < n/2) {c2.push_back(x);cn2.push_back(m);}
					else {
						s = cn2.back();
						if(a[s]->a1 > a[s]->a3){
							cx = a[s]->a1;
							cm = 1;
						}else{
							cx = a[s]->a3;
							cm = 3;
						}
						if ((c2.back() - cx)<= x){
							c2.pop_back();
							cn2.pop_back();
							if (cm == 1) {c1.push_back(cx);cn1.push_back(s);}
							if (cm == 3) {c3.push_back(cx);cn3.push_back(s);}
							c2.push_back(x);
							cn2.push_back(m);
						}
						
					}
				}else if(c == 3){
					//cout << 3 << j << endl;
					if ((int)c3.size() < n/2) {c3.push_back(x);cn3.push_back(m);}
					else {
						s = cn3.back();
						if(a[s]->a1 > a[s]->a2){
							cx = a[s]->a1;
							cm = 1;
						}else{
							cx = a[s]->a2;
							cm = 2;
						}
						if ((c3.back() - cx)<= x){
							c3.pop_back();
							cn3.pop_back();
							if (cm == 1) {c1.push_back(cx);cn1.push_back(s);}
							if (cm == 2) {c2.push_back(cx);cn2.push_back(s);}
							c3.push_back(x);
							cn3.push_back(m);
						}
						
					}
				}
			}	
			if (j1 == n && j2 == n && j3 == n) break;
				
		}		
		
		
		int o = 0;
		for (int j = 0;j < (int)c1.size();j++){
			o += c1[j];
			//cout << c1[j] << endl;
		}
		//cout <<endl;
		for (int j = 0;j < (int)c2.size();j++){
			o += c2[j];
			//cout << c2[j] << endl;
		}
		//cout << endl;
		for (int j = 0;j < (int)c3.size();j++){
			o += c3[j];
			//cout << c3[j] << endl;
		}
		printf("%d\n",o);
    }
    
    
    return 0;
}
