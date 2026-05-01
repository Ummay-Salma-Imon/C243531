#include <iostream>
using namespace std;

int main()
{
    int n, maxL; // n=how many num of lenths there, maxL = total lenth
    cin >> n >> maxL;

    int len[n+1], price[n+1]; // n ta lenths er n ta price thakbe
    for(int i = 1; i <= n; i++)// lenths , prices input neya
       cin >> len[i] >> price[i];

    int dp[n+1][maxL+1]; // row borabor jabe je: maxL(0 to maxL)
                     // col borabor nambe je lenghts(0 to n)
    ///initialize 1st row, col = 0
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxL; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    ///filling table(rod cutting unbounded)
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= maxL; j++)
        {
            if(j < len[i])
                dp[i][j] = dp[i-1][j];

            else if(j >= len[i])
                dp[i][j] = max(dp[i-1][j], dp[i][j-len[i]] + price[i]);
        }
    }
    //print table:
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxL; j++)
           cout << dp[i][j] << "\t";
        cout << endl;
    }

    cout << "max amount: " << dp[n][maxL] << endl;

    ///backtracking to find selected items
    int i = n, j = maxL;
    while(i > 0 && j > 0)
    {
        if(j >= len[i] && dp[i][j] == dp[i][j-len[i]] + price[i])
        {
            cout << len[i] << " ";
            j = j - len[i];
        }
        else
           i--;
    }
}
