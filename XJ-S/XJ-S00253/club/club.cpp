#include<bits/stdc++.h>
using namespace std;
int t,n;
pair<short,short> a1[100001],a2[100001],a3[100001];
bool flag;
void sort1(){
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n-i+1;j++){
			if(a1[j].first>a1[j-1].first){
				swap(a1[j],a1[j-1]);
			}
			else if(a1[j].first==a1[j-1].first&&a1[j].second<a1[j-1].second){
				swap(a1[j],a1[j-1]);
			}
			if(a2[j].first>a2[j-1].first){
				swap(a2[j],a2[j-1]);
			}
			else if(a2[j].first==a2[j-1].first&&a2[j].second<a2[j-1].second){
				swap(a2[j],a2[j-1]);
			}
			if(a3[j].first>a3[j-1].first){
				swap(a3[j],a3[j-1]);
			}
			else if(a3[j].first==a3[j-1].first&&a3[j].second<a3[j-1].second){
				swap(a3[j],a3[j-1]);
			}
		}
	}
}
void check(short x){
	for(int i=1;i<=n;i++){
		if(a1[i].second==x) a1[i].first=0,a1[i].second=-1;
		if(a2[i].second==x) a2[i].first=0,a2[i].second=-1;
		if(a3[i].second==x) a3[i].first=0,a3[i].second=-1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1,ans=0;i<=t;i++,ans=0){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1[j].first>>a2[j].first>>a3[j].first;
			a1[j].second=j,a2[j].second=j,a3[j].second=j;
		}
		sort1();
		for(int x1=1,x2=1,x3=1,maxx=max(max(a1[1].first,a2[1].first),a3[1].first);x1+x2+x3<=n+1;flag=false){
			//cout<<a1[x1].first<<" "<<maxx<<" "<<x1<<" "<<x2<<" "<<x3<<" "<<ans<<endl;
//			for(int j=1;j<=n;j++){
//				cout<<a1[j].first<<" "<<a2[j].first<<" "<<a3[j].first<<endl;
//			}
			while(a1[x1].second==0&&a1[x1].second==-1){
				x1++;
			}
			while(a2[x2].second==0&&a2[x2].second==-1){
				x2++;
			}
			while(a3[x3].second==0&&a3[x3].second==-1){
				x3++;
			}
			maxx=max(max(a1[x1].first,a2[x2].first),a3[x3].first);
			if(maxx==a1[x1].first&&x1<=n/2){
				check(a1[x1].second);
				//cout<<"a1"<<endl;
				x1++,ans+=maxx,flag=true;
				if(x1>n/2){
					if(a2[x2].first+a1[x1].first>maxx){
						ans=ans-maxx+a2[x2].first+a1[x1].first;
						x1--;
					}
					if(a3[x3].first+a1[x1].first>maxx){
						ans=ans-maxx+a3[x3].first+a1[x1].first;
						x1--;
					}
				}
			}
			else if(maxx==a2[x2].first&&x2<=n/2){
				check(a2[x2].second);
				//cout<<"a2"<<endl;
				x2++,ans+=maxx,flag=true;
				if(x2>n/2){
					if(a1[x1].first+a2[x2].first>maxx){
						ans=ans-maxx+a1[x1].first+a2[x2].first;
						x2--;
					}
					if(a3[x3].first+a2[x2].first>maxx){
						ans=ans-maxx+a3[x3].first+a2[x2].first;
						x2--;
					}
				}
			}
			else if(maxx==a3[x3].first&&x3<=n/2){
				check(a3[x3].second);
				//cout<<"a3"<<endl;
				x3++,ans+=maxx,flag=true;
				if(x3>n/2){
					if(a3[x3].first+a1[x1].first>maxx){
						ans=ans-maxx+a3[x3].first+a1[x1].first;
						x3--;
					}
					if(a3[x3].first+a2[x2].first>maxx){
						ans=ans-maxx+a3[x3].first+a2[x2].first;
						x3--;
					}
				}
			}
			if(!flag){
				//cout<<"b";
				break;
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
//1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
