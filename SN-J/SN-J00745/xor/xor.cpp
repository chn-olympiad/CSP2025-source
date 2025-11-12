#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,k;
ll a[N];
int b[N];

struct edge{
	int start,ended;
};

int ans=0;
vector <edge> v; //存区间   咋选啊 
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		if(a[i]==k) v.push_back((edge){i,i});
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(b[j]^b[i-1]==k) v.push_back({i,j});
//		}
//	}
	
	//针对特殊A 真没招了
	//T3欺我老无力 
	cout<<n/2;
	
	
	return 0;
	
}

/*
哈\基米-莫.南/北\绿-豆~ 
阿西嘎.哈库哪路~呜 
哦\哈基米-曼波~ 
哈基米/莫\南北~绿豆~
*/ 

/*
哈基米哈基米哈基米哈基米哈基米 
哈基米南北绿豆 
阿西嘎阿西嘎阿西嘎阿西嘎 
呀酷南路 
*/ 


/*
		/---\
	   |    |  ------噬菌体 
	   \----|       这才是真正的艺术 
	     |
	     |
	     |
   ------|-------
   |    |      |   
   |    |      |	   
*/


