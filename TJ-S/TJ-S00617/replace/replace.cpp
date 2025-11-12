#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
const int L=5e6+10;

int n;
int q;

int a[N][2];

vector<int> vv[N];
vector<int> vvv[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
//	printf("a");
	
	cin>>n>>q;
	
	bool vis=true;
	
	string s1;
	string s2;
	int b1=-1;
	int b2=-1;
	
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		a[i][0]=s1.length();
		for(int j=0;j<a[i][0];j++){
			if(s1[j]=='b'){
				b1=j;
				break;
			}
		}
		a[i][1]=s2.length();
		for(int j=0;j<a[i][1];j++){
			if(s2[j]=='b'){
				b2=j;
				break;
			}
		}
		if(b1-b2>0){
			vv[b1-b2].push_back(a[i][0]);	
		}else{
			vvv[b2-b1].push_back(a[i][0]);
		}
	}
//	printf("a");
	
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int sl=s1.length();
		int sll=s2.length();
		if(sl!=sll){
			printf("0\n");
			continue;
		}
		int b1;
		int b2;
		for(int i=0;i<sl;i++){
			if(s1[i]=='b'){
				b1=i;
				break;
			}
		}
		for(int i=0;i<sll;i++){
			if(s2[i]=='b'){
				b2=i;
			}
		}
		int bb;
		int cc;
		if(b1>b2){
			bb=b1-b2;
			sort(vv[bb].begin(),vv[bb].end());
			cc=vv[bb].size();
			int l=0;
			int r=cc;
			int md;
			while(l<r){
				md=(l+r)>>1;
				if(vv[bb][md]>sl){
					r=md-1;
				}else{
					l=md+1;
				}
			}
			printf("%d\n",l);
		}else if(b1>b2){
			bb=b2-b1;
			sort(vvv[bb].begin(),vvv[bb].end());
			cc=vvv[bb].size();
			int l=0;
			int r=cc;
			int md;
			while(l<r){
				md=(l+r)>>1;
				if(vvv[bb][md]>sl){
					r=md-1;
				}else{
					l=md+1;
				}
			}
			printf("%d\n",l);
		}
	}
	
	return 0;
}
