#include <iostream>
#include <vector>

using namespace std;

int dp[101][101][101];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int a ,b ,c;

  for(int a =0; a<101; a++){
    for(int b = 0; b< 101; b++){
      for(int c = 0; c<101; c++){
        if(a <= 50 || b <=50 || c <=50  ){
          dp[a][b][c] = 1;
        }
        else if (a>70 || b>70 || c>70){
          dp[a][b][c] = dp[70][70][70];
        }
        else if (a < b && b < c){
          dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];      
        }
        else{
          dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];
        }

      }
    }
  }

  while(true){
    cin >> a >> b >> c;

    if(a == -1 && b == -1 && c == -1) break;

    cout << "w(" << a << ", " << b << ", "<< c <<") = " << dp[a+50][b+50][c+50] << endl;

    //ans.push_back(dp[a+50][b+50][c+50]);

  }

  /*for(int i =0; i<ans.size(); i++){
    cout << ans[i] << endl;
  }*/
  return 0;
} 