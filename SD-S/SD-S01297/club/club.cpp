#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node{
	int cho,wo,se,ws;//选的值，选的编号，其次的值，其次的编号 
}E[N];
int t[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int res = 0;
		int n;
		cin>>n;
		memset(t,0,sizeof t);
		for(int i = 1;i <= n;i ++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E[i].cho = a;
			E[i].wo = 1;
			E[i].se = b;
			E[i].ws = 2;
			if(b > E[i].cho){
				E[i].cho = b;
				E[i].wo = 2;
				if(a >= c){
					E[i].se = a;
					E[i].ws = 1;
				}
				else{
					E[i].se = c;
					E[i].ws = 3;
				}
			}
			if(c > E[i].cho){
				E[i].cho = c;
				E[i].wo = 3;
				if(a >= b){
					E[i].se = a;
					E[i].ws = 1;
				}
				else{
					E[i].se = b;
					E[i].ws = 2;
				}
			}
			t[E[i].wo] ++;
			res += E[i].cho;
		}
		//----
		int maxx = 0;
		int wha = 0;
		for(int i = 1;i <= 3;i ++){
			if(t[i] > maxx){
				maxx = t[i];
				wha = i;
			}
		}
		vector <int> s;
		for(int i = 1;i <= n;i ++){
			if(E[i].wo == wha){
				int cha = E[i].cho - E[i].se;
				s.push_back(cha);
			} 
		}
		sort(s.begin(),s.end());
		for(int i = 0;i < (maxx - n/2);i ++){
			res -= s[i]; 
		}
		cout<<res<<endl;
	}
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}

