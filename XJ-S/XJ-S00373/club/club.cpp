#include<bits/stdc++.h>
using namespace std;
int t, n, maxn;
const int N = 10e5+5;
int p[4];
int c[N][3]; int pp[N][3];
struct att{
	int len; int ca; int num; int l; int ll; int lll;
}; 

int f (int len, int ca, int num) {
	
	if( p[1] > maxn || p[2] > maxn || p[3] > maxn ) return num;
	num += c[len][ca]; 
	if( len +1 > n ) return num;
	 
	int maxan = -1;
	for (int i=1; i<=3; i++){
		p[i] ++ ;
		maxan = max(maxan, f(len+1, i-1, num) );
		p[i] -- ;
	}
	return maxan;
}

bool isgood(att v){
	if(v.len > n || v.l > maxn || v.ll > maxn || v.lll > maxn ) return false;
	
	return true;
}

void b(){
	att m = {0,0,0,0,0,0};
	queue<att> q; q.push( m );
	
	while(!q.empty()){
		att u = q.front();  q.pop();
		for(int i=1;i<=3;i++){
			att v = u;
			if( i == 1) {
				v.l ++;
				v.ca = 0;
			}if( i == 2) {
				v.ll ++;
				v.ca = 1;
			}if( i == 3) {
				v.lll ++;
				v.ca = 2;
			}
			v.len ++;
			
			
			if( isgood(v) ){
				v.num += c[v.len ][ v.ca ];
				pp[ v.len  ] [v.ca  ] = max (pp[ v.len  ] [v.ca  ], v.num  );
				q.push(v);
			}		
		}
		
	}
	
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j = 1; j<= t; j++){
		cin >> n;
		maxn = n/2;
		for(int i = 1; i  <= n; i++){
			cin >> c[i][0]>> c[i][1] >> c[i][2];
		}
		
		
		srand(time(0));
		int random = rand()%2;
		if(random == 1){
			int ans = f(0, 0, 0);
			printf("%d\n",ans);
		}
		else if (random == 0){
			for(int i=0;i<=n;i++) for(int j=0;j<3;j++) pp[i][j]=0;
			b();
			int ans = max( max(pp[n][1], pp[n][0]), pp[n][2] );
			printf("%d\n",ans);
		}
		
		
		
		
	}
	
	return 0;
}















