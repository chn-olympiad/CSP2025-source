#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct xx{
	int a;
	int b;
	int c;
}ee[N];
long long maxx=-1;
long long t[5];
int n;
bool cmp(xx op,xx ed){
	return op.a >ed.a ;
}
void dfs(long long x,long long he){
	if(x==n+1){
		maxx=max(maxx,he);
		return;
	}
	if(t[1]<n/2){
		t[1]++;
		dfs(x+1,he+ee[x].a);
		t[1]--;
	}
	if(t[2]<n/2){
		t[2]++;
		dfs(x+1,he+ee[x].b );
		t[2]--;
	}
	if(t[3]<n/2){
		t[3]++;
		dfs(x+1,he+ee[x].c );
		t[3]--;
	}
}
void dfs2(long long x,long long he){
	if(x==n+1){
		maxx=max(maxx,he);
		return;
	}
	if(t[1]<n/2){
		t[1]++;
		dfs(x+1,he+ee[x].a);
		t[1]--;
	}
	if(t[2]<n/2){
		t[2]++;
		dfs(x+1,he+ee[x].b );
		t[2]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int h;
	cin>>h;
	int he=0;
	int ji=0;
	int ji2=0;
	while(h--){
		cin>>n;
		ji=0;
		ji2=0;
		he=0;
		maxx=-1;
		for(int i=1;i<=4;i++){
			t[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>ee[i].a >>ee[i].b >>ee[i].c ;
			if(ee[i].b==0&&ee[i].c==0){
				ji++;
			}else if(ee[i].c==0&&ee[i].b !=0){
				ji2++;
			}
		}
		if(ji==n){
			sort(ee+1,ee+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				he+=ee[i].a; 
			}
			cout<<he<<endl;
			continue;
		}
		if(ji2==n){
			dfs2(1,0);
			cout<<maxx<<endl;
			continue;
		}
		dfs(1,0);
		cout<<maxx<<endl;
	}
	return 0;
}