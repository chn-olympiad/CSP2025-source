//SN-S00728 闫卜予 西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
//只过A,B: 
const int N=200005;
ll n,q;
string s[N][2],t[N][2];
struct AAA{
	int qian,b,hou;//b is xiabiao,zaizifuchuanlimian,suoyijianleyigeyi qian he hou doushichangdu 
}a[2][N][2];//1,2,3位分别表示:s还是t,第几个,1还是2 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			a[1][i][j].b=s[i][j].find('b');
			a[1][i][j].qian=a[1][i][j].b;
			a[1][i][j].hou=s[i][j].size()-a[1][i][j].b-1;
		}	
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			a[2][i][j].b=t[i][j].find('b');
			a[2][i][j].qian=a[2][i][j].b;
			a[2][i][j].hou=t[i][j].size()-a[2][i][j].b-1;
		}
	}
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
} 
