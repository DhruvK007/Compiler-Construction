#include <bits/stdc++.h>
using namespace std;

class State
{
public:
    int state;
    vector<pair<char, int>> transitions;
    State(int state, vector<pair<char, int>> transitions)
    {
        this->state = state;
        this->transitions = transitions;
    }
};

int main()
{
    int nSymbols;
    cout << "Number of input symbols : ";
    cin >> nSymbols;

    vector<char> v;

    cout << "Input Symbols : ";
    for (int i = 0; i < nSymbols; i++)
    {
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    int nStates;
    cout << "Enter number of states : ";
    cin >> nStates;

    int initialState;
    cout << "Enter initial state : ";
    cin >> initialState;

    int nAcceptStates;
    cout << "Number of Accepting States : ";
    cin >> nAcceptStates;

    vector<int> acceptStates;
    cout << "Accepting States : ";
    for (int i = 0; i < nAcceptStates; i++)
    {
        int temp;
        cin >> temp;
        acceptStates.push_back(temp);
    }

    vector<State> DFA;
    cout << "Transition Table" << endl;

    for (int i = 1; i <= nStates; i++)
    {
        vector<pair<char, int>> temp;
        for (int j = 0; j < nSymbols; j++)
        {
            int transition;
            cout << i << " to " << v[j] << " -> ";
            cin >> transition;
            temp.push_back(make_pair(v[j], transition));
        }
        DFA.push_back(State(i, temp));
    }

    string str;
    cout << "\nInput String :";
    cin >> str;
    int state = initialState;
    for (int i = 0; i < str.length(); i++)
    {
        vector<pair<char, int>> temp = DFA[state - 1].transitions;
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j].first == str[i])
            {
                state = temp[j].second;
                break;
            }
        }
    }

    for (int i = 0; i < acceptStates.size(); i++)
    {
        if (state == acceptStates[i])
        {
            cout << "\nValid String";
            return 0;
        }
    }

    cout << "Invalid String";
    return 0;
}