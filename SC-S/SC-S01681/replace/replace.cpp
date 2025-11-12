#include<bits/stdc++.h>
using namespace std;
struct ti{
	string Now,Next;int l;
}T[200001];
bool comp(ti a,ti b){
	return a.l>b.l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,j,k,la,lb,m,sum;
	string a,b,c,d,e;
	cin>>n>>q;
	for(i=0;i<n;i++){
		cin>>T[i].Now>>T[i].Next;
		T[i].l=T[i].Next.size();
	}
	for(i=0;i<q;i++){
		cin>>a>>b;sum=0;
		la=a.size();lb=b.size();
		if(la!=lb){
			cout<<0<<endl;continue;
		}
		for(j=0;j<n;j++){
			if(T[j].l>la){
				break;
			}
			for(k=0;k<=la-T[j].l;k++){
				d=a.substr(k,T[j].l);
				if(d==T[j].Now){
					e=a;
					for(m=k;m<k+T[j].l;m++){
						e[m]=T[j].Next[m-k];
					}
					if(e==b){
						sum++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}