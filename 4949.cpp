#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 시간 효율성을 위해 진행하기
    cin.tie(NULL);
    cout.tie(NULL);

    // 문자열 처리
    string input;
    while (true)
    {
        bool isValid = true;
        getline(cin, input); // 한 줄을 입력 받기 (문장 전체를 받기 위해 getline사용)
        if (input == ".")
            break; // 만약 입력받은 문자열이 "."라면 입력을 종료
        stack<char> s;
        for (int i = 0; i < input.length(); i++)
        { // 문자열 체크
            if (input[i] == '(')
            { // 시작 괄호열은 일단 넣기
                s.push(input[i]);
            }
            else if (input[i] == '[')
            {
                s.push(input[i]);
            }
            else if (input[i] == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    cout << "no" << '\n';
                    isValid = false;
                    break;
                }
                s.pop();
            }
            else if (input[i] == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    cout << "no" << '\n';
                    isValid = false;
                    break;
                }
                s.pop();
            }
        }

        if (!isValid)
            continue;

        if (s.empty())
        { // 문자열 전체 체크가 끝난 후, 스택이 비어있다면
            cout << "yes" << '\n';
        }
        else
        { // 스택이 비어있지 않다면 no
            cout << "no" << '\n';
        }
    }

    return 0;
}