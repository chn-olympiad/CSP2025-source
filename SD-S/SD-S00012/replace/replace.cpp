#include <iostream>
using namespace std;
const int N = 2e5+5;

int n,q;
string k[N][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> k[i][0] >> k[i][1];
	}
	while(q--){
		string a,b;
		int arr = 0;
		cin >> a >> b;
		for(int w=1;w<=n;w++){
			bool flg = 0;
			int nxt = 0;
			int siz = k[w][0].size();
			for(int i=0;i+siz<=a.size();i++){
				if(nxt>i) continue;
				string tmp1 = a.substr(i,siz);
				string tmp2 = b.substr(i,siz);
				if((!flg)&&tmp1==k[w][0]&&tmp2==k[w][1]){
					flg = 1;
					nxt = i+siz;
					continue;
				}
				if(a[i]!=b[i]){
//					cout << i << endl;
					flg = 0;
					break;
				}
			}
			arr += flg;
		}
		cout << arr << endl;
	}
	return 0;
}
