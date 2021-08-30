#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main() {
    int t;
    cin>>t;
    int i=0;
    while(t--){
        i++;
        int n;
        cin>>n;
        char A[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>A[i][j];
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        */

        int cntx = 0 , cnto = 0 , cnt_dot = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]=='.'){
                    cnt_dot++;
                }
                else if(A[i][j]=='X'){
                    cntx++;
                }
                else{
                    cnto++;
                }
            }
        }
        int min_x_to_win = n+1;
        int diff_config_having_min_x_to_win = 0;
        //edge case 

        //check rows 
        for(int i=0;i<n;i++){
            int countX = 0,countO=0,count_dot=0;
            int posx =-1;
            int posy = -1;
            for(int j=0;j<n;j++){
                if(A[i][j]=='O'){
                    countO++;
                    break;
                }
                else if(A[i][j]=='X'){
                    countX++;
                }
                else{
                    count_dot++;
                    posx = i;
                    posy = j;
                }
            }
            
            if(countO==0){
                if(count_dot==1){
                    A[posx][posy]='X';
                }
                if(count_dot<min_x_to_win){
                    min_x_to_win=count_dot;
                    diff_config_having_min_x_to_win=1;
                    if(min_x_to_win==1){

                    }
                }
                else if(count_dot==min_x_to_win){
                    diff_config_having_min_x_to_win++;
                }
            }
        }
        //check columns
        for(int i=0;i<n;i++){
            int countX = 0,countO=0,count_dot=0;
            for(int j=0;j<n;j++){
                if(A[j][i]=='O'){
                    countO++;
                    break;
                }
                else if(A[j][i]=='X'){
                    countX++;
                }
                else{
                    count_dot++;
                    
                }
            }
            if(countO==0){

                if(count_dot<min_x_to_win && count_dot>0){
                    min_x_to_win=count_dot;
                    diff_config_having_min_x_to_win=1;
                    
                }
                else if(count_dot==min_x_to_win){
                    diff_config_having_min_x_to_win++;
                }
            }
        }

        //cout<<cntx<<" "<<cnto<<" "<<cnt_dot<<" "<<endl;
        // if(min_x_to_win==1){
        //     //redo ?
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<n;j++){
        //             if(A[i][j])
        //         }
        //     }
        // }
        
        if(diff_config_having_min_x_to_win == 0){
            cout<<"Case #"<<i<<": "<<"Impossible"<<endl;
        }
        else{
            cout<<"Case #"<<i<<": "<<min_x_to_win<<" "<<diff_config_having_min_x_to_win<<endl;
        }
    }
}
