#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 시간 효율성을 위해 진행하기
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력받기
    int n, k;
    cin >> n;      // 1~n명의 사람
    cin >> k;      // k번째 사람 제거
    int result[n]; // 결과를 반환할 리스트 선언

    queue<int> q; // 큐를 이용하여 알고리즘 구현
    for (int i = 1; i < n + 1; i++)
    {
        q.push(i); // 1~n의 사람을 큐에 넣음
    }

    for (int i = 0; i < n; i++)
    { // n번만큼 수를 제외해줌
        for (int j = 1; j < k + 1; j++)
        { // k번째 순서를 빼기 전까지 계속 돌림
            if (j == k)
            { // k번째 순서라면?
                result[i] = q.front();
                q.pop();
            }
            else
            {                      // k번째 순서가 아니라면
                q.push(q.front()); // 뺄 원소를 다시 큐에 넣음
                q.pop();
            }
        }
    }

    // 출력
    cout << '<';
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << result[i];
        }
        else
        {
            cout << result[i] << ", ";
        }
    }
    cout << '>';
    return 0;
}