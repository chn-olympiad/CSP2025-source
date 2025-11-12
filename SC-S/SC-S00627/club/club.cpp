#include<bits/stdc++.h>
using namespace std;
struct club{
	int val;
	int no;
};
struct sc{
	club s[4];
	int turn=1;
}a[100005];
int t,n;
int cntx,cnty,cntz;
int p=1;
int ans;
bool cmp(club x,club y){
	return x.val>y.val;
}
bool cmp2(sc x,sc y){
	return x.s[1].val<y.s[1].val;
}
bool cmp3(sc x,sc y){
	//cout<<"comp3:"<< x.s[a[p].turn].val - x.s[a[p].turn+1].val<<" "<<y.s[a[p].turn].val - y.s[a[p].turn+1].val<<endl;
	return x.s[a[p].turn].val - x.s[a[p].turn+1].val  <  y.s[a[p].turn].val - y.s[a[p].turn+1].val;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		p=1;
		cntx=cnty=cntz=0;
		scanf("%d",&n);
		int lim=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].s[1].val,&a[i].s[2].val,&a[i].s[3].val);
			a[i].s[1].no=1;
			a[i].s[2].no=2;
			a[i].s[3].no=3;
			a[i].turn=1;
		}
		for(int i=1;i<=n;i++)sort(a[i].s+1,a[i].s+4,cmp);//喜好最大值排序
		sort(a+1,a+n+1,cmp2);
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++)cout<<a[i].s[j].val<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			if(a[i].s[1].no==1){//turn只和当前可利用最小欢迎度有关？
//			cout<<"[X]"<<endl;
				ans+=a[i].s[1].val;
				if(cntx<lim)cntx++;//cout<<"++"<<cntx<<":"<<lim<<endl;
				else{//超过限制
//				cout<<"exed"<<endl;
					
					sort(a+1,a+n+1,cmp3);
					
//				cout<<"<"<<a[p].s[1].val<<">"<<endl;
					ans-=a[p].s[1].val;
					
					a[p].turn++;
//				cout<<"<a[p].turn:"<<a[p].turn<<">"<<endl;
					
					if(a[p].turn>3)p++;
					
//					cout<<"<"<<a[p].s[a[p].turn].val<<">"<<endl;
					ans+=a[p].s[a[p].turn].val;//最好次好、第三差值最小者改次好或者第三
					
					sort(a+1,a+n+1,cmp2);
					
					//已经加入一半的情况下，不会再有一组加入超过一半了
					if(a[p].s[a[p].turn].no==2)cnty++;
					else if(a[p].s[a[p].turn].no==3)cntz++;	
					
				}
			}
			else if(a[i].s[1].no==2){//turn只和当前可利用最小欢迎度有关？
//				cout<<"[Y]"<<endl;
				ans+=a[i].s[1].val;
				if(cnty<lim)cnty++;//cout<<"++"<<endl;
				else{//超过限制
//					cout<<"exed"<<endl;
					
					sort(a+1,a+n+1,cmp3);
					
					for(int i=1;i<=n;i++){
//						for(int j=1;j<=3;j++)cout<<a[i].s[j].val<<" ";
//						cout<<endl;
					}
					
//					cout<<"<"<<a[p].s[1].val<<">"<<endl;
					ans-=a[p].s[1].val;
					
					a[p].turn++;
//					cout<<"<a[p].turn:"<<a[p].turn<<">"<<endl;
					
					if(a[p].turn>3)p++;
					
//					cout<<"<"<<a[p].s[a[p].turn].val<<">"<<endl;
					ans+=a[p].s[a[p].turn].val;//最好次好、第三差值最小者改次好或者第三
					
					sort(a+1,a+n+1,cmp2);
					
					//已经加入一半的情况下，不会再有一组加入超过一半了
					if(a[p].s[a[p].turn].no==1)cntx++;
					else if(a[p].s[a[p].turn].no==3)cntz++;	
				}
			}
			else if(a[i].s[1].no==3){//turn只和当前可利用最小欢迎度有关？
//				cout<<"[Z]"<<endl;
				ans+=a[i].s[1].val;
				if(cntz<lim)cntz++;//cout<<"++"<<endl;
				else{//超过限制
//					cout<<"exed"<<endl;
					
					sort(a+1,a+n+1,cmp3);
					
//					cout<<"<"<<a[p].s[1].val<<">"<<endl;
					ans-=a[p].s[1].val;
					
					a[p].turn++;
//					cout<<"<a[p].turn:"<<a[p].turn<<">"<<endl;
					
					if(a[p].turn>3)p++;
					
//					cout<<"<"<<a[p].s[a[p].turn].val<<">"<<endl;
					ans+=a[p].s[a[p].turn].val;//最好次好、第三差值最小者改次好或者第三
					
					sort(a+1,a+n+1,cmp2);
					
                    //已经加入一半的情况下，不会再有一组加入超过一半了
					if(a[p].s[a[p].turn].no==1)cntx++;
					else if(a[p].s[a[p].turn].no==2)cnty++;	
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}