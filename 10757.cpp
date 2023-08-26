#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 시간 효율성을 위해 진행하기
    cin.tie(NULL);
    cout.tie(NULL);

    // 문자열로 입력받기
    string a, b;
    deque<char> A, B;
    deque<int> result;
    cin >> a;
    cin >> b;

    // 받아온 큰 수를 deque에 집어넣어 계산하자 (back의 원소들끼리 계산하여 출력)
    for (int i = 0; i < a.size(); i++)
    {
        A.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        B.push_back(b[i]);
    }

    // A와 B중 사이즈가 더 큰 수를 기준으로 for문 실행
    int size;
    if (A.size() < B.size())
    {
        size = B.size();
    }
    else
    {
        size = A.size();
    }

    bool carry = false; // 올림이 있을 경우
    int m, n;           // m=A, n=B
    for (int i = 0; i < size; i++)
    { // 뒷자리부터 차례대로 계산
        if (A.empty())
        {
            m = 0;
        }
        else
        {
            m = A.back() - '0'; // char to int를 위해 '0'을 뺀다
            A.pop_back();
        }
        if (B.empty())
        {
            n = 0;
        }
        else
        {
            n = B.back() - '0';
            B.pop_back();
        }
        int sum = m + n;
        if (carry)
        { // 이전 계산에서 carry가 있다면?
            sum++;
        }
        if (sum >= 10)
        {
            carry = true;
            result.push_front(sum - 10);
        }
        else
        {
            carry = false;
            result.push_front(sum);
        }
    }
    if (carry)
    {
        result.push_front(1);
    }

    size = result.size();
    while (!result.empty())
    {
        cout << result.front();
        result.pop_front();
    }

    return 0;
}