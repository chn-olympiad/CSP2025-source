#include<iostream>
using namespace std;
int n,a[5005],vis[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
	else cout<<0;
	return 0;
} 
//CSP-J Journal
//9:38 Start Polygon.
//     Just Like Xor......
//     Try Violence First.
//     This one really requires Qianzhuihe.
//9:44 Oh,I'm Wrong.This Doesn't Mean The Sticks must be a substring...
//     GG.
//9:49 Violence--True Violence.DFS.
//10:10 DFS Fail.
//      Ahh...
//      Internationale will finally come true!
//10:16 The Work is Now Complete.
//      100+100+30+12=242pts.Gotta Try To Complete Xor.
//      Thanks to ccf.
//      Thanks to XingXing.
//      The Three Years In OI Was Just A Dream.
//      The Hard Days,The Delighted Days,The Tired Days,The Warm Days......
//      It All Disappears In A Sudden.
//      See You,Guys.Thanks to All of You.
//      AFO.







//The Song of Internationale (Awful Translating)
//Rise up,the starving and freezing slaves,
//Rise up,everyone who's suffering!
//The blood in our veins are burning,
//Preparing to fight for the truth!
//Break down the order of the old world,
//Slaves,rise up!rise up!
//It's not us who have got nothing,
//But ones who have got the world!
//This is our final battle,
//Fight together till daybreak!
//Internationale will finally come true!
//This is our final battle,
//Fight together till daybreak!
//Internationale will finally come true!
/* 


                                                                #
                                                                 #
                                                                 #
                                              #                  #
                                             # #                 ##
                                            #   #                ##
                                           #     #               # #
                                          #     #                # #
                                         #     #                #  #
                                        #       #               #  #
                                       #     #   #              #  #
                                       #    # #   #             #   #
                                       #   #   #   #           #    #
                                       #  #     #   #          #    #
                                       # #       #   #         #    #
                                        #         #   #       #    #
                                                   #   #     #    #
                            #####                   #   #   #    #
                          #      #                    #   #     #
                          #      #                     #      #
                            ###   #                  #       #
                               #    #              #      #   #
                                #     #          #      #  #   #
                                  #     # #  # #     #      #   #
                                    #             #          # #
                                        # #  # #
        */                              
                                        
           
