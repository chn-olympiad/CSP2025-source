#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct xinchengyuan{
	int ei;
	int bi;
	int sei;
	int he;
	int zuidade;
	int zuixiaode;
	int zhongjiande;
	int daaidi;
	int xiaoaidi;
	int zhongaidi;
}ren[N];
bool tanxin(xinchengyuan a,xinchengyuan b){
	if(a.zuidade!=b.zuidade){
		return a.zuidade>b.zuidade;
	}else if(a.zhongjiande!=a.zhongjiande){
		return a.zhongjiande>a.zhongjiande;
	}else{
		return a.zuixiaode>b.zuixiaode;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		long long manyidu=0;
		cin>>n;
		int erfenzhin=n/2;
		for(int i=0;i<n;i++){
			cin>>ren[i].ei>>ren[i].bi>>ren[i].sei;
			ren[i].zuidade=max(ren[i].ei,max(ren[i].bi,ren[i].sei));
			ren[i].zuixiaode=min(ren[i].ei,min(ren[i].bi,ren[i].sei));
			ren[i].he=ren[i].ei+ren[i].bi+ren[i].sei;
			ren[i].zhongjiande=ren[i].he-ren[i].zuidade-ren[i].zuixiaode;
			if(ren[i].zuidade==ren[i].ei){
				ren[i].daaidi=0;
				if(ren[i].zhongjiande==ren[i].bi){
					ren[i].zhongaidi=1;
					ren[i].xiaoaidi=2;
				}else{
					ren[i].zhongaidi=2;
					ren[i].xiaoaidi=1;
				}
			}else if(ren[i].zuidade==ren[i].bi){
				ren[i].daaidi=1;
				if(ren[i].zhongjiande==ren[i].ei){
					ren[i].zhongaidi=0;
					ren[i].xiaoaidi=2;
				}else{
					ren[i].zhongaidi=2;
					ren[i].xiaoaidi=0;
				}
			}else{
				ren[i].daaidi=2;
				if(ren[i].zhongjiande==ren[i].bi){
					ren[i].zhongaidi=1;
					ren[i].xiaoaidi=0;
				}else{
					ren[i].zhongaidi=0;
					ren[i].xiaoaidi=1;
				}
			}
		}
		sort(ren,ren+n,tanxin);
		int a,b,c;
		a=b=c=erfenzhin;
		for(int i=0;i<n;i++){
			int iei=ren[i].ei;
			int ibi=ren[i].bi;
			int isei=ren[i].sei;
			if(iei!=ibi&&ibi!=isei&&iei!=isei){
				if(ren[i].daaidi==0&&a){
					a--;
					manyidu+=ren[i].ei;
				}else if(ren[i].daaidi==1&&b){
					b--;
					manyidu+=ren[i].bi;
				}else if(ren[i].daaidi==2&&c){
					c--;
					manyidu+=ren[i].sei;
				}else{
					if(ren[i].zhongaidi==0){
						manyidu+=ren[i].ei;
					}else if(ren[i].zhongaidi==1){
						manyidu+=ren[i].bi;
					}else{
						manyidu+=ren[i].sei;
					}
				}
			}else{
				if(iei==ibi&&ibi==isei){
					if(max(a,max(b,c))==a){
						a--;
						manyidu+=iei;
					}else if(max(a,max(b,c))==b){
						b--;
						manyidu+=ibi;
					}else{
						c--;
						manyidu+=isei;
					}
				}else if(iei==ibi){
					if(iei<isei&&c){
						c--;
						manyidu+=isei;
					}else if(max(a,b)==a){
						a--;
						manyidu+=iei;
					}else{
						b--;
						manyidu+=ibi;
					}
				}else if(isei==ibi){
					if(iei>isei&&a){
						a--;
						manyidu+=iei;
					}else if(max(c,b)==c){
						c--;
						manyidu+=isei;
					}else{
						b--;
						manyidu+=ibi;
					}
				}else{
					if(iei<ibi&&b){
						b--;
						manyidu+=ibi;
					}else if(max(a,c)==a){
						a--;
						manyidu+=iei;
					}else{
						c--;
						manyidu+=isei;
					}
				}
			}
		}
		cout<<manyidu<<"\n";
	}
	return 0;
}
