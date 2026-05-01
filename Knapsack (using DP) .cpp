#include <iostream>
using namespace std;

int main()
{
    int n, maxW;
    cin >> n >> maxW;

    int wei[n+1], val[n+1];
    for(int i = 1; i <= n; i++)
        cin >> wei[i] >> val[i];

    int dp[n+1][maxW+1];
 for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxW; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= maxW; j++)
        {
            if(j < wei[i])
               dp[i][j] = dp[i-1][j];

            else if(j >= wei[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wei[i]] + val[i]);
        }
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxW; j++)
            cout << dp[i][j] << "\t\t";
        cout << endl;
    }

    int i = n, j = maxW;
    while(i > 0 && j > 0)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            cout << i << " ";
            j = j - wei[i];
        }
        i--;
    }

    return 0;

}
