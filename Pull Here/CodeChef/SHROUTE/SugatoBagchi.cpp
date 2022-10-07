#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        for (int i = 0; i < M; i++)
            cin >> B[i];

        int temp = 100001, tmp[N], low = -1, high = -1;
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
                tmp[i] = 0;

            else if (A[i] != 0)
                tmp[i] = 0;

            else
                tmp[i] = temp;
        }
        for (int i = 0; i < N; i++)
        {
            if (A[i] == 1)
                high = i;
            if (high != -1)
            {
                if (A[i] == 0)
                    tmp[i] = min(tmp[i], i - high);
            }
        }
        for (int i = N - 1; i >= 0; i--)
        {
            if (A[i] == 2)
                low = i;
            if (low != -1)
            {
                if (A[i] == 0)
                    tmp[i] = min(tmp[i], low - i);
            }
        }
        for (int i = 0; i < M; i++)
        {
            int j = B[i] - 1;

            if (tmp[j] != temp)
                cout << tmp[j] << " ";

            else
                cout << -1 << " ";
        }
        cout << endl;
    }
}